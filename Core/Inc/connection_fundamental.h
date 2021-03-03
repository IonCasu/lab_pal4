/*
 * connection_fundamental.h
 *
 *
 *  Created on: 18 gen 2021
 *      Author: cocco
 */

#ifndef INC_FUNDAMENTAL_H_
#define INC_FUNDAMENTAL_H_

#include "net_mbedtls.h"
#include "macro_def.h"

/* Variabili per connessione TLS*/
extern mbedtls_ssl_context ssl;
extern Network network;

int board_wifi_init(const char*, const char*);
WIFI_Status_t ClientConnectNViaDNS(Network* n, const char *myremoteaddr, uint16_t myremoteport);
int net_read(Network*, unsigned char*, int, int);
int net_write(Network*, unsigned char*, int, int);
void network_init(Network*);
void net_disconnect(Network*);

#endif /* INC_FUNDAMENTAL_H_ */

