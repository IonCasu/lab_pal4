/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  *
  * Il codice qui scritto effettua le seguenti operazioni:
  *  - Connessione alla rete Wi-Fi
  *  - Creazione di una connessione criptata TLS
  *  - Creazione di una connessione MQTT
  *  - Sottoscrizione a due diversi topic
  *  - Publish su due diversi topic
  *  - Scrittura a terminale di avvenuta ricezione di un messaggio inviato dal broker
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dfsdm.h"
#include "i2c.h"
#include "quadspi.h"
#include "rng.h"
#include "spi.h"
#include "usart.h"
#include "usb_otg.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* DEBUG defines */

/*
 * Le seguenti define servono, rispettivamente, per abilitare l'uso dell'output sulla console di debug e
 * per cambiare il livello di debug della libreria TLS (i valori vanno da 1 a 5)
 */

#define TERMINAL_USE
#define DEBUG_LEVEL 1

/* TLS defines
 *
 * Qui vengono dichiarati indirizzo e porta di un paio di server, quello di Modena utilizzato nel progetto
 * e quello di test di mosquitto, utile per provare la connessione. La porta è sempre la stessa.
 * */

//#define SERVER_NAME "test.mosquitto.org"
#define SERVER_NAME "94.177.167.141"
#define SERVER_PORT 8883
//#define HOSTNAME "test.mosquitto.org"
//#define HOSTNAME "94.177.167.141"

/* MQTT defines
 *
 * WIFI_WRITE_TIMEOUT - Millisecondi prima della caduta dell'errore a seguito di una write
 * WIFI_READ_TIMEOUT - Millisecondi prima della caduta dell'errore a seguito di una read
 * WRITE_BUF_SIZE - Dimensione del buffer di scrittura del pacchetto
 * READ_BUF_SIZE - Dimensione del buffer di ricezione del pacchetto
 */
#define WIFI_WRITE_TIMEOUT 10000
#define WIFI_READ_TIMEOUT  10000
#define WRITE_BUF_SIZE	2000
#define READ_BUF_SIZE	2000

/*
 * Collegamento tra la funzione TERMOUT e la printf per la visualizzazione su console di debug
 */
#if defined (TERMINAL_USE)
#define TERMOUT(...)  printf(__VA_ARGS__)
#else
#define TERMOUT(...)
#endif

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/*
 * Variabile usata per il Random Number Generator (RNG)
 */
RNG_HandleTypeDef hrng;

#if defined (TERMINAL_USE)
extern UART_HandleTypeDef hDiscoUart;
#endif /* TERMINAL_USE */

/*
 * Variabili utilizzate dalla libreria TLS
 */
mbedtls_net_context server_fd;
mbedtls_entropy_context entropy;
mbedtls_ctr_drbg_context ctr_drbg;
mbedtls_ssl_context ssl;
mbedtls_ssl_config conf;
mbedtls_x509_crt cacert;


/*
 * Certificati utilizzati per validare la connessione al server (Modena e Mosquitto)
 */

//Modena
const unsigned char certificate[] =
		"-----BEGIN CERTIFICATE-----\r\n"
		"MIIEEzCCAvugAwIBAgIJAN0/f83JD+j9MA0GCSqGSIb3DQEBCwUAMIGfMQswCQYD\r\n" \
		"VQQGEwJJVDELMAkGA1UECAwCTU8xDzANBgNVBAcMBk1vZGVuYTEZMBcGA1UECgwQ\r\n" \
		"RGF0YVJpdmVyIFMuci5sLjEWMBQGA1UECwwNSVQgRGVwYXJ0bWVudDEaMBgGA1UE\r\n" \
		"AwwRbXF0dC5kYXRhcml2ZXIuaXQxIzAhBgkqhkiG9w0BCQEWFGhvc3RpbmdAZGF0\r\n" \
		"YXJpdmVyLml0MB4XDTIwMTAwODE1NDkxOVoXDTIxMTAwODE1NDkxOVowgZ8xCzAJ\r\n" \
		"BgNVBAYTAklUMQswCQYDVQQIDAJNTzEPMA0GA1UEBwwGTW9kZW5hMRkwFwYDVQQK\r\n" \
		"DBBEYXRhUml2ZXIgUy5yLmwuMRYwFAYDVQQLDA1JVCBEZXBhcnRtZW50MRowGAYD\r\n" \
		"VQQDDBFtcXR0LmRhdGFyaXZlci5pdDEjMCEGCSqGSIb3DQEJARYUaG9zdGluZ0Bk\r\n" \
		"YXRhcml2ZXIuaXQwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDHvBcn\r\n" \
		"zQmkQTbvIpw2zcePhA/+X5hG/hXONlpj3+7z/37hI8Q8pmPCoyqno2+L1BNWERlY\r\n" \
		"VDUlcL+OwPaHrYRSbSmeRXGfeRp6qOa+wWKE3LtMCZN1D6z2OY3+smZ9Ob60A8/s\r\n" \
		"KxdTigg88sWi48iTcInTSuEy2Ixh1zsC0TFD2Me/Vxyk3EsvDROiYHwf5K1Ur6SB\r\n" \
		"jbj3Olmm7mXvrynjYfX+uzKELrkbjDpLfot7UGAEv8sf4P1tHz1WP0GZUlbw2gIC\r\n" \
		"ILHR+Bdazku8GTuZNLUopRqWDDQHUTqB3j2ORO/VeGh4RdzvQxJ3bYpaa+3lOMMA\r\n" \
		"isVd3xv5lePerm0PAgMBAAGjUDBOMB0GA1UdDgQWBBTz9ngRUjN8NyWmeWYQNO1l\r\n" \
		"HNpd9zAfBgNVHSMEGDAWgBTz9ngRUjN8NyWmeWYQNO1lHNpd9zAMBgNVHRMEBTAD\r\n" \
		"AQH/MA0GCSqGSIb3DQEBCwUAA4IBAQCiDc6HRzkVj+zcdz71nDDmcOthjDW3VPfg\r\n" \
		"TbMS3y9F2TZ/+TbmqARUSWoWEVOFztNpZzn60Gb9WVZzsQicAk09+ADiYNVZCIlu\r\n" \
		"/ASP1z+B3yBFK4B8HazkXA6QQw9UW5/9aWi8XQewDg2yB0GIW44Q/XIxlZVJrTLu\r\n" \
		"J/Xjsdzx7UTNZ48wRqNwzmxnxenJCrWVZVFKPqqxBCfwJlD6rn77zN9CoCGPpNSX\r\n" \
		"nPm+8SrAXL0TSelNM7VzypOvNVCQY5tjdeToaYStjgmhbB2Nu5CnFEk2bM5l716p\r\n" \
		"VoHJzqoz+nFE662NpA+Lw9Q8IJtw/MkgqlNbtWMrA41StfvP6FXc\r\n" 			   \
		"-----END CERTIFICATE-----\r\n";

//Mosquitto
const unsigned char mosquitto_certificate[] =
		"-----BEGIN CERTIFICATE-----\r\n"
		"MIIEAzCCAuugAwIBAgIUBY1hlCGvdj4NhBXkZ/uLUZNILAwwDQYJKoZIhvcNAQEL\r\n"
		"BQAwgZAxCzAJBgNVBAYTAkdCMRcwFQYDVQQIDA5Vbml0ZWQgS2luZ2RvbTEOMAwG\r\n"
		"A1UEBwwFRGVyYnkxEjAQBgNVBAoMCU1vc3F1aXR0bzELMAkGA1UECwwCQ0ExFjAU\r\n"
		"BgNVBAMMDW1vc3F1aXR0by5vcmcxHzAdBgkqhkiG9w0BCQEWEHJvZ2VyQGF0Y2hv\r\n"
		"by5vcmcwHhcNMjAwNjA5MTEwNjM5WhcNMzAwNjA3MTEwNjM5WjCBkDELMAkGA1UE\r\n"
		"BhMCR0IxFzAVBgNVBAgMDlVuaXRlZCBLaW5nZG9tMQ4wDAYDVQQHDAVEZXJieTES\r\n"
		"MBAGA1UECgwJTW9zcXVpdHRvMQswCQYDVQQLDAJDQTEWMBQGA1UEAwwNbW9zcXVp\r\n"
		"dHRvLm9yZzEfMB0GCSqGSIb3DQEJARYQcm9nZXJAYXRjaG9vLm9yZzCCASIwDQYJ\r\n"
		"KoZIhvcNAQEBBQADggEPADCCAQoCggEBAME0HKmIzfTOwkKLT3THHe+ObdizamPg\r\n"
		"UZmD64Tf3zJdNeYGYn4CEXbyP6fy3tWc8S2boW6dzrH8SdFf9uo320GJA9B7U1FW\r\n"
		"Te3xda/Lm3JFfaHjkWw7jBwcauQZjpGINHapHRlpiCZsquAthOgxW9SgDgYlGzEA\r\n"
		"s06pkEFiMw+qDfLo/sxFKB6vQlFekMeCymjLCbNwPJyqyhFmPWwio/PDMruBTzPH\r\n"
		"3cioBnrJWKXc3OjXdLGFJOfj7pP0j/dr2LH72eSvv3PQQFl90CZPFhrCUcRHSSxo\r\n"
		"E6yjGOdnz7f6PveLIB574kQORwt8ePn0yidrTC1ictikED3nHYhMUOUCAwEAAaNT\r\n"
		"MFEwHQYDVR0OBBYEFPVV6xBUFPiGKDyo5V3+Hbh4N9YSMB8GA1UdIwQYMBaAFPVV\r\n"
		"6xBUFPiGKDyo5V3+Hbh4N9YSMA8GA1UdEwEB/wQFMAMBAf8wDQYJKoZIhvcNAQEL\r\n"
		"BQADggEBAGa9kS21N70ThM6/Hj9D7mbVxKLBjVWe2TPsGfbl3rEDfZ+OKRZ2j6AC\r\n"
		"6r7jb4TZO3dzF2p6dgbrlU71Y/4K0TdzIjRj3cQ3KSm41JvUQ0hZ/c04iGDg/xWf\r\n"
		"+pp58nfPAYwuerruPNWmlStWAXf0UTqRtg4hQDWBuUFDJTuWuuBvEXudz74eh/wK\r\n"
		"sMwfu1HFvjy5Z0iMDU8PUDepjVolOCue9ashlS4EB5IECdSR2TItnAIiIwimx839\r\n"
		"LdUdRudafMu5T5Xma182OC0/u/xRlEm+tvKGGmfFcN0piqVl8OrSPBgIlb+1IKJE\r\n"
		"m/XriWr/Cq4h/JfB7NTsezVslgkBaoU=\r\n"
		"-----END CERTIFICATE-----\r\n";

/*
 * Variabili utilizzate per la ricezione e la subscribe a topic MQTT
 */
static MQTTMessage pubmsg, timemsg;
MQTTSubackData subData, subTimeData;

/*
 * Variabile che identifica l'SPI3
 * Dichiarata in un altro file, quindi definita come extern
 */
extern  SPI_HandleTypeDef hspi;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);

/* USER CODE BEGIN PFP */
/*
 * Funzioni che permettono la ricezione di due tipi di messaggi su due diversi topic, inviati dal server di Modena.
 * messageArrived - Restituisce esattamente ciò che scriviamo al server
 * messageTimeArrived - Restituisce l'orario
 */
void messageArrived(MessageData* md);
void messageTimeArrived(MessageData* md);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/*
 * Variabili utilizzate al solo scopo di debug
 * cont - Numero di messaggi arrivati (non tiene conto dei messaggi di orario)
 * timeMessaggio - Orario ricevuto dal server
 */
int cont = 0;
char* timeMessaggio;

void messageArrived(MessageData* md)
{
  MQTTMessage* m = md->message;
  TERMOUT("> Good message lengths, payloadlen was %d\n", m->payloadlen);
  cont = cont + 1;
  //TERMOUT("> Payload was %s\n", (char*)m->payload);
}

void messageTimeArrived(MessageData* md)
{
  MQTTMessage* m = md->message;
  TERMOUT("> Good time message, payloadlen was %d\n", m->payloadlen);
  timeMessaggio = m->payload;
  //TERMOUT("> Time payload was %s\n", (char*)m->payload);
}

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

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DFSDM1_Init();
  MX_I2C2_Init();
  MX_QUADSPI_Init();
  MX_SPI3_Init();
  MX_USART1_UART_Init();
  MX_USART3_UART_Init();
  MX_USB_OTG_FS_PCD_Init();
  MX_RNG_Init();
  /* USER CODE BEGIN 2 */

  /*
   * Definizione parametri UART per scrittura a terminale
   */
#if defined (TERMINAL_USE)
  /* Initialize all configured peripherals */
  hDiscoUart.Instance = DISCOVERY_COM1;
  hDiscoUart.Init.BaudRate = 115200;
  hDiscoUart.Init.WordLength = UART_WORDLENGTH_8B;
  hDiscoUart.Init.StopBits = UART_STOPBITS_1;
  hDiscoUart.Init.Parity = UART_PARITY_NONE;
  hDiscoUart.Init.Mode = UART_MODE_TX_RX;
  hDiscoUart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  hDiscoUart.Init.OverSampling = UART_OVERSAMPLING_16;
  hDiscoUart.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  hDiscoUart.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;

  BSP_COM_Init(COM1, &hDiscoUart);
#endif /* TERMINAL_USE */


  int ret;
  uint32_t flags;
  const char *pers = "ssl_client1";
  uint32_t read_timeout = WIFI_READ_TIMEOUT;

  /*
   * Funzioni di inizializzazione TLS
   */
  mbedtls_net_init( &server_fd );
  mbedtls_ssl_init( &ssl );
  mbedtls_ssl_config_init( &conf );
  mbedtls_x509_crt_init( &cacert );
  mbedtls_ctr_drbg_init( &ctr_drbg );
  mbedtls_entropy_init( &entropy );

  #if DEBUG_LEVEL > 0
  	  mbedtls_ssl_conf_dbg(&conf, my_debug, NULL);
  	  mbedtls_debug_set_threshold(DEBUG_LEVEL);
  #endif

  /*
   * Aggiunta della sorgente di entropia.
   * La sorgente di entropia serve per ottenere un numero casuale che permetta la generazione di una
   * chiave sicura nel criptaggio TLS
   */
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

  ret = mbedtls_x509_crt_parse( &cacert, certificate, sizeof( certificate ) );
  //ret = mbedtls_x509_crt_parse( &cacert, mosquitto_certificate, sizeof( mosquitto_certificate ) );

  if( ret < 0 )
  {
	  TERMOUT( " failed\n  !  mbedtls_x509_crt_parse returned -0x%x\n", -ret );
  }

  TERMOUT( " ok (%d skipped)\n", ret );

  /*
   * 1. Start the connection
   */
  TERMOUT( "> Connecting to tcp %s:%d...\n\n",SERVER_NAME,SERVER_PORT);

  if( ( ret = mbedtls_net_connect( &server_fd, (uint8_t*)SERVER_NAME, SERVER_PORT,
		  WIFI_TCP_PROTOCOL) ) != 0)
  {
	  TERMOUT( " failed\n  ! mbedtls_net_connect returned %d\n", ret );
  }

  /*
   * 2. Setup stuff
   */
  TERMOUT( "> Setting up the SSL/TLS structure..." );

  if( ( ret = mbedtls_ssl_config_defaults( &conf,
                  MBEDTLS_SSL_IS_CLIENT,
                  MBEDTLS_SSL_TRANSPORT_STREAM,
                  MBEDTLS_SSL_PRESET_DEFAULT ) ) != 0 )
  {
	  TERMOUT( " failed\n  ! mbedtls_ssl_config_defaults returned %d\n\n", ret );
  }

  TERMOUT( " ok\n" );

  /* OPTIONAL is not optimal for security,
   * but makes interop easier in this simplified example */
  /*
   * al posto di MBEDTLS_SSL_VERIFY_REQUIRED si può inserire MBEDTLS_SSL_VERIFY_OPTIONAL
   * per evitare il controllo del certificato. E' utile in fase di prova, non è accettabile
   * a codice completo
   */
  mbedtls_ssl_conf_authmode( &conf, MBEDTLS_SSL_VERIFY_REQUIRED);
  mbedtls_ssl_conf_ca_chain( &conf, &cacert, NULL );

  mbedtls_ssl_conf_read_timeout( &conf, read_timeout );
  mbedtls_ssl_conf_rng( &conf, mbedtls_ctr_drbg_random, &ctr_drbg );
  if( ( ret = mbedtls_ssl_setup( &ssl, &conf ) ) != 0 )
  {
      TERMOUT( " failed\n  ! mbedtls_ssl_setup returned %d\n", ret );
  }

  if( ( ret = mbedtls_ssl_set_hostname( &ssl, SERVER_NAME ) ) != 0 )
  {
      TERMOUT( " failed\n  ! mbedtls_ssl_set_hostname returned %d\n", ret );
  }

  /*
   * Funzione che collega le funzioni di ricezione ed invio (mbedtls_net_recv, mbedtls_net_send)
   * alla libreria TLS
   */
  mbedtls_ssl_set_bio(&ssl, &server_fd, mbedtls_net_send, NULL, mbedtls_net_recv);

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

      mbedtls_x509_crt_verify_info( vrfy_buf, sizeof( vrfy_buf ), "  ! ", flags );

      TERMOUT( "%s\n", vrfy_buf );
  }
  else
	  TERMOUT( " ok\n" );

  /*
   * Inizializzazione parametri MQTT
   */
  Network new_net;
  MQTTClient c;
  MQTTPacket_connectData options = MQTTPacket_connectData_initializer;

  options.willFlag = 0;
  options.MQTTVersion = 3;
  options.clientID.cstring = "OSO_1";
  options.username.cstring = "uniprpark";
  options.password.cstring = "uniprpass";
  options.keepAliveInterval = 60;
  options.cleansession = 1;
  /*options.will.message.cstring = "message";
  options.will.qos = 1;
  options.will.retained = 0;
  options.will.topicName.cstring = "topic";*/

  uint8_t writebuf[WRITE_BUF_SIZE];
  uint8_t readbuf[READ_BUF_SIZE];

  /*
   * subsqos - Quality Of Service della subscribe
   * qos - Quality Of Service della trasmissione
   * test_topic - Topic a cui sottoscrivere per il server Modenese
   */
  int subsqos = 2;
  char* test_topic = "PARK_MO002/OSO9CB6D0BE4F75/attrs";
  int qos = 2;

  /*
   * Variabili usate per controllare a quantità di messaggi inviati
   */
  uint8_t iterations = 1;
  uint8_t stop = 0;

  /*
   * Inizializzazione connessione MQTT e connessione al broker
   */
  NewNetwork(&new_net);
  MQTTClientInit(&c, &new_net, WIFI_WRITE_TIMEOUT, writebuf, WRITE_BUF_SIZE, readbuf, READ_BUF_SIZE);

  TERMOUT("> Connecting to MQTT Broker at %s:%d\n",SERVER_NAME,SERVER_PORT);
  ret = MQTTConnect(&c, &options);
  if (ret == 0)
  {
	  TERMOUT("> Connection established with the MQTT broker\n");
  }
  else
  {
	  TERMOUT("> Unable to connect with the MQTT broker\n");
  }
  /*
   * SOTTOSCRIZIONE AL TOPIC TIME
   */
  char* time_OSO_topic = "get_time/OSO_1";
  char* time_server_topic = "get_time/server";
  ret = MQTTSubscribeWithResults(&c, time_OSO_topic, subsqos, messageTimeArrived, &subTimeData);
  if (ret == 0)
  {
	  TERMOUT("> Subscribe to topic: %s correct\n", time_OSO_topic);
  }
  else
  {
	  TERMOUT("> Subscribe to topic: %s not correct\n", time_OSO_topic);
  }

  /*
   * SOTTOSCRIZIONE AL TOPIC IN CUI INVII I MESSAGGI
   */
  ret = MQTTSubscribeWithResults(&c, test_topic, subsqos, messageArrived, &subData);
  if (ret == 0)
  {
	  TERMOUT("> Subscribe to topic: %s correct\n", test_topic);
  }
  else
  {
	  TERMOUT("> Subscribe to topic: %s not correct\n", test_topic);
  }

  /*
   * Messaggio da inviare al server contenente i dati che vogliamo inviare
   */
  memset(&pubmsg, '\0', sizeof(pubmsg));
  pubmsg.payload = "{\"items\": [{\"measure\": \"test\",\"measure_unit\": \"none\",\"data_type\": \"test_data\",\"data_source\": \"PARK_MO001_OSO012345ABCDEF\",\"values\": [{\"value\": 1,\"data_start_time\": \"202011051100\",\"data_end_time\": \"202011051101\"},{\"value\": 2,\"data_start_time\": \"202011051101\",\"data_end_time\": \"202011051102\"},{\"value\": 3,\"data_start_time\": \"202011051102\",\"data_end_time\": \"202011051103\"},{\"value\": 4,\"data_start_time\": \"202011051103\",\"data_end_time\": \"202011051104\"},{\"value\": 5,\"data_start_time\": \"202011051104\",\"data_end_time\": \"202011051105\"}]}]}";
  pubmsg.payloadlen = strlen(pubmsg.payload);
  pubmsg.qos = qos;
  pubmsg.retained = 0;
  pubmsg.dup = 0;

  /*
   * Messaggio contenente la richiesta dell'orario al server
   */
  memset(&timemsg, '\0', sizeof(timemsg));
  timemsg.payload = "{'caller':'OSO_1'}";
  timemsg.payloadlen = strlen(timemsg.payload);
  timemsg.qos = qos;
  timemsg.retained = 0;
  timemsg.dup = 0;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  /*
   * Il programma invia un paio di messaggi normali al server, dopodiché fa una richiesta di orario.
   * La sequenza precedente si ripete 2 volte, dopodiché il programma termina.
   */
  while (1)
  {
    /* USER CODE END WHILE */

	  if (iterations <= 2)
	  {
		  TERMOUT("> Message %d at QoS %d\n", iterations, qos);
		  ret = MQTTPublish(&c, test_topic, &pubmsg);
		  if (ret == 0)
		  {
			  TERMOUT("> Correct Publish to the topic: %s\n", test_topic);
		  }
		  else
		  {
			  TERMOUT("> Unable to Publish to the topic: %s\n", test_topic);
		  }
		  iterations++;
		  HAL_Delay(1000);
	  }
	  else
	  {
		  if (stop==0)
		  {
			  iterations = 1;
			  stop = 1;

			  TERMOUT("> Time request \n");
			  ret = MQTTPublish(&c, time_server_topic, &timemsg);
			  if (ret == 0)
			  {
				  TERMOUT("> Correct Publish to the topic: %s\n", time_server_topic);
			  }
			  else
			  {
				  TERMOUT("> Unable to Publish to the topic: %s\n", time_server_topic);
			  }
			  HAL_Delay(1000);
		  }
		  else
		  {
			  TERMOUT("> Last time request \n");
			  ret = MQTTPublish(&c, time_server_topic, &timemsg);
			  if (ret == 0)
			  {
				  TERMOUT("> Correct Publish to the topic: %s\n", time_server_topic);
			  }
			  else
			  {
				  TERMOUT("> Unable to Publish to the topic: %s\n", time_server_topic);
			  }

			  HAL_Delay(1000);

			  break;
		  }
	  }

    /* USER CODE BEGIN 3 */
  }
  while(1)
  {
	  //MQTTYield(&c, 1000);
	  HAL_Delay(1000);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Configure LSE Drive Capability 
  */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE|RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 40;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1|RCC_PERIPHCLK_USART3
                              |RCC_PERIPHCLK_I2C2|RCC_PERIPHCLK_DFSDM1
                              |RCC_PERIPHCLK_USB|RCC_PERIPHCLK_RNG;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
  PeriphClkInit.Usart3ClockSelection = RCC_USART3CLKSOURCE_PCLK1;
  PeriphClkInit.I2c2ClockSelection = RCC_I2C2CLKSOURCE_PCLK1;
  PeriphClkInit.Dfsdm1ClockSelection = RCC_DFSDM1CLKSOURCE_PCLK;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLLSAI1;
  PeriphClkInit.RngClockSelection = RCC_RNGCLKSOURCE_PLLSAI1;
  PeriphClkInit.PLLSAI1.PLLSAI1Source = RCC_PLLSOURCE_MSI;
  PeriphClkInit.PLLSAI1.PLLSAI1M = 1;
  PeriphClkInit.PLLSAI1.PLLSAI1N = 24;
  PeriphClkInit.PLLSAI1.PLLSAI1P = RCC_PLLP_DIV7;
  PeriphClkInit.PLLSAI1.PLLSAI1Q = RCC_PLLQ_DIV2;
  PeriphClkInit.PLLSAI1.PLLSAI1R = RCC_PLLR_DIV2;
  PeriphClkInit.PLLSAI1.PLLSAI1ClockOut = RCC_PLLSAI1_48M2CLK;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the main internal regulator output voltage 
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Enable MSI Auto calibration 
  */
  HAL_RCCEx_EnableMSIPLLMode();
}

/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  switch (GPIO_Pin)
  {
    case (GPIO_PIN_1):
    {
      SPI_WIFI_ISR();
      break;
    }
    default:
    {
      break;
    }
  }
}

void SPI3_IRQHandler(void)
{
  HAL_SPI_IRQHandler(&hspi);
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
