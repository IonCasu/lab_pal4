/*
 * TLS_fundamental.c
 *
 *  Created on: 19 gen 2021
 *      Author: cocco
 */

#include "TLS_fundamental.h"

#if DEBUG_LEVEL > 0
/*
 * Funzione usata per il debug della TLS
 */
static void my_debug(void *ctx, int level, const char *file, int line,
                     const char *str)
{
    const char *p, *basename;
    (void) ctx;

    /* Extract basename from file */
    for(p = basename = file; *p != '\0'; p++) {
        if(*p == '/' || *p == '\\') {
            basename = p + 1;
        }
    }

    TERMOUT("%s:%04d: |%d| %s", basename, line, level, str);
}
#endif

/**
  * @brief  Initialize TLS entities, RNG and the session data
  * @retval None
  */
void Net_TLS_Init(void)
{
	int ret;
	const char *pers = "ssl_client1";

	/* Funzioni di inizializzazione TLS */
	network_init(&network);		//Initialize Network struct
	(&server_fd)->fd=-1; 		//initialize socket file descriptor to -1
	mbedtls_ssl_init(&ssl);
	mbedtls_ssl_config_init(&conf);
	mbedtls_x509_crt_init(&cacert);
	mbedtls_ctr_drbg_init(&ctr_drbg);
	mbedtls_entropy_init(&entropy);
#if DEBUG_LEVEL > 0
	mbedtls_ssl_conf_dbg(&conf, my_debug, NULL);
 	mbedtls_debug_set_threshold(DEBUG_LEVEL);
#endif

	/*
	 *  Aggiunta della sorgente di entropia.
	 *  La sorgente di entropia serve per ottenere un numero casuale che permetta la generazione di una
	 *  chiave sicura nel criptaggio TLS
	 *  */
	TERMOUT( "> Adding a new entropy source..." );
	ret = mbedtls_entropy_add_source(&entropy,mbedtls_rng_poll_cb,&hrng,32,MBEDTLS_ENTROPY_SOURCE_STRONG);
	if (ret != 0)
	{
		TERMOUT( " failed\n  ! mbedtls_entropy_add_source returned %d\n", ret );
	}
	TERMOUT( " ok\n" );

	/*
	 * 0. Initialize the RNG and the session data
	 */
	TERMOUT( "> Seeding the random number generator..." );
	if( ( ret = mbedtls_ctr_drbg_seed( &ctr_drbg, mbedtls_entropy_func, &entropy,
			(const unsigned char *) pers,
			strlen( pers ) ) ) != 0 )
	{
		TERMOUT( " failed\n  ! mbedtls_ctr_drbg_seed returned %d\n", ret );
	}
	TERMOUT( " ok\n" );

	/*
	 * 0. Initialize certificates
	 */
	TERMOUT( "> Loading the CA root certificate ..." );
	ret = mbedtls_x509_crt_parse( &cacert, (const unsigned char *) certificate, sizeof(certificate));
	if( ret < 0 )
	{
		TERMOUT( " failed\n  !  mbedtls_x509_crt_parse returned -0x%x\n", -ret );
	}
	TERMOUT( " ok (%d skipped)\n", ret );
	return;
}

/**
  * @brief  Deinitialize TLS entities
  * @retval None
  */
void Net_TLS_DeInit(void)
{
	mbedtls_x509_crt_free( &cacert );
	mbedtls_ssl_free( &ssl );
	mbedtls_ssl_config_free( &conf );
	mbedtls_ctr_drbg_free( &ctr_drbg );
	mbedtls_entropy_free( &entropy );
}

/**
  * @brief  Connect to server and perform TLS handshake
  * @param servername: URL of the server
  * @param serverport: port to connect to
  * @param servercn: name inside the certificate
  * @retval Connection status
  */
WIFI_Status_t TLS_connect(const char * servername, const uint16_t serverport, const char * servercn)
{
	int ret = -1;
	WIFI_Status_t retw = WIFI_STATUS_ERROR;
	WIFI_Status_t rc = WIFI_STATUS_OK;
	uint32_t flags = 0x1234;

	/*
	 * 1. Start the connection
	 */
	TERMOUT( "> Connecting to tcp %s:%d...\n",servername,serverport);
	if((retw=ClientConnectNViaDNS(&network, servername, serverport)) != 0)
	{
		TERMOUT( " failed\n  ! mbedtls_net_connect returned %d\n", ret );
		rc = WIFI_STATUS_ERROR;
	}
	else
	{
		TERMOUT (" ok.\n");
	}
	(&server_fd)->fd=(&network)->my_socket;

	/*
	 * 2. Setup stuff
	 */
	TERMOUT( "> Loading default SSL configuration..." );
	if( ( ret = mbedtls_ssl_config_defaults( &conf,
			MBEDTLS_SSL_IS_CLIENT,
			MBEDTLS_SSL_TRANSPORT_STREAM,
			MBEDTLS_SSL_PRESET_DEFAULT ) ) != 0 )
	{
		TERMOUT( " failed\n  ! mbedtls_ssl_config_defaults returned %d\n\n", ret );
		rc = WIFI_STATUS_ERROR;
	}
	else
	{
		TERMOUT( " ok\n" );
	}

	/* OPTIONAL is not optimal for security,
	 * but makes interop easier in this simplified example
	 *
	 * Al posto di MBEDTLS_SSL_VERIFY_REQUIRED si può inserire MBEDTLS_SSL_VERIFY_OPTIONAL
	 * per evitare il controllo del certificato. E' utile in fase di prova, non è accettabile
	 * a codice completo
	 */
	TERMOUT( "> Setting up the SSL structure..." );
	mbedtls_ssl_conf_authmode( &conf, MBEDTLS_SSL_VERIFY_REQUIRED);
	mbedtls_ssl_conf_ca_chain( &conf, &cacert, NULL );
	mbedtls_ssl_conf_read_timeout( &conf, WIFI_READ_TIMEOUT );
	mbedtls_ssl_conf_rng( &conf, mbedtls_ctr_drbg_random, &ctr_drbg );
	if( ( ret = mbedtls_ssl_setup( &ssl, &conf ) ) != 0 )
	{
		TERMOUT( " failed\n  ! mbedtls_ssl_setup returned %d\n", ret );
		rc = WIFI_STATUS_ERROR;
	}
	else
	{
		TERMOUT( " ok\n" );
	}

	TERMOUT( "> Checking certificate name validity..." );
	if( ( ret = mbedtls_ssl_set_hostname( &ssl, servercn ) ) != 0 )
	{
		TERMOUT( " failed\n  ! mbedtls_ssl_set_hostname returned %d\n", ret );
		rc = WIFI_STATUS_ERROR;
	}
	else
	{
		TERMOUT( " ok\n" );
	}

	/*
	 * Funzione che collega le funzioni di ricezione ed invio (mbedtls_net_recv, mbedtls_net_send)
	 * alla libreria TLS
	 */
	TERMOUT("> Configuring TLS send and recv functions...");
	mbedtls_ssl_set_bio(&ssl, (void*) &network, bl475eiota2_tls_send, bl475eiota2_tls_recv, bl475eiota2_tls_recv_timeout);
	TERMOUT( " ok\n" );

	/*
	 * 4. Handshake
	 */
	TERMOUT( "> Performing the SSL/TLS handshake..." );
	while( ( ret = mbedtls_ssl_handshake( &ssl ) ) != 0 )
	{
		if( ret != MBEDTLS_ERR_SSL_WANT_READ &&
				ret != MBEDTLS_ERR_SSL_WANT_WRITE &&
				ret != MBEDTLS_ERR_SSL_CRYPTO_IN_PROGRESS )
		{
			TERMOUT( " failed\n  ! mbedtls_ssl_handshake returned -0x%x\n\n", -ret );
			rc = WIFI_STATUS_ERROR;
		}
	}
	TERMOUT( " ok\n" );

	/*
	 * 5. Verify the server certificate
	 */
	TERMOUT( "> Verifying peer X.509 certificate..." );
	/* In real life, we probably want to bail out when ret != 0 */
	if( ( flags = mbedtls_ssl_get_verify_result( &ssl ) ) != 0 )
	{
		char vrfy_buf[512];
		TERMOUT( " failed\n" );
		rc = WIFI_STATUS_ERROR;
		mbedtls_x509_crt_verify_info( vrfy_buf, sizeof( vrfy_buf ), "  ! ", flags );
		TERMOUT( "%s\n", vrfy_buf );
	}
	else
	{
		TERMOUT( " ok\n" );
	}
	return rc;
}
