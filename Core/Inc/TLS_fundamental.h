/*
 * TLS_fundamental.h
 *
 *  Created on: 19 gen 2021
 *      Author: cocco
 */

#ifndef INC_TLS_FUNDAMENTAL_H_
#define INC_TLS_FUNDAMENTAL_H_

#include "net_mbedtls.h"
#include "mbedtls/net.h"
#include "mbedtls/ssl.h"
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/debug.h"
#include "mbedtls/certs.h"
#include "mbedtls/net_sockets.h"
#include "mbedtls/error.h"
#include "mbedtls_entropy.h"

#include "macro_def.h"
#include "mycerts.h"

/* Variabili per connessione TLS */
extern mbedtls_net_context server_fd;
extern mbedtls_entropy_context entropy;
extern mbedtls_ssl_context ssl;
extern mbedtls_ctr_drbg_context ctr_drbg;
extern mbedtls_ssl_config conf;
extern mbedtls_x509_crt cacert;
extern Network network;

/* Variabile Random Number Generator (RNG) */
extern RNG_HandleTypeDef hrng;

void Net_TLS_Init(void);
void Net_TLS_DeInit(void);
WIFI_Status_t TLS_connect(const char *, const uint16_t, const char *);

extern void network_init(Network*);
extern WIFI_Status_t ClientConnectNViaDNS(Network* n, const char *myremoteaddr, uint16_t myremoteport);

#endif /* INC_TLS_FUNDAMENTAL_H_ */
