/*
 * macro_def.h
 *
 *  Created on: 19 gen 2021
 *      Author: cocco
 */

#ifndef MACRO_DEF_H_
#define MACRO_DEF_H_

#include "mbedtls/net.h"
#include "mbedtls/ssl.h"
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/debug.h"
#include "mbedtls/certs.h"
#include "mbedtls/net_sockets.h"
#include "mbedtls/error.h"
#include "mbedtls_entropy.h"
#include "Network.h"

/* Debug */
#define TERMINAL_USE
#define DEBUG_LEVEL 0

/* Collegamento tra la funzione TERMOUT e la printf per la visualizzazione su console di debug */
#if defined (TERMINAL_USE)
#define TERMOUT(...)  printf(__VA_ARGS__)
#else
#define TERMOUT(...)
#endif

/* Connection */
#define SSID_RETE   "AndroidAP5781"
#define PASSWORD 	"ioncasu12"

#define CONNECTION_TRIAL_MAX 10
#define RECONNECT_DELAY 2000
#define SEND_MSG_DELAY	4000
#define WIFI_WRITE_TIMEOUT 10000
#define WIFI_READ_TIMEOUT  10000
#define WRITE_BUF_SIZE	2000
#define READ_BUF_SIZE	2000

/* TLS */
#define SERVER_MODENA
#if defined (SERVER_MODENA)
#define SERVER_NAME "94.177.167.141"
#define SERVER_PORT 8883
#define SERVER_CN SERVER_NAME
#else
#define SERVER_NAME "test.mosquitto.org"
#define SERVER_PORT 8883
#define SERVER_CN "test.mosquitto.org"
#endif

/* MQTT */
#if defined (SERVER_MODENA)
#define TOPIC_OSO "PARK_MO001/OSO012345ABCDEF/attrs"
#define USERNME_MQTT "uniprpark"
#define PASSW_MQTT "uniprpass"
#define ID_OSO "OSO_1"
#define TOPIC_RECV_TIME "get_time/OSO_1"
#define TOPIC_REQ_TIME "get_time/server"
#define QOS_PUB 2
#define QOS_SUB 2
#else
#define TOPIC_OSO "test_data_unipr_obj"
#define USERNME_MQTT ""
#define PASSW_MQTT ""
#define ID_OSO "test_obj_unipr_0"
#define TOPIC_RECV_TIME "test_data_unipr_obj"
#define TOPIC_REQ_TIME "test_data_unipr_obj"
#define QOS_PUB 2
#define QOS_SUB 2
#endif

/*Parametri relativi alla generazione di interrupt del timer TIM16, immagazzinamento e pubblicazione dei dati */


#define TIM16_IRQ_INTERVAL		5	//l'intervallo di tempo, espresso in secondi, che intercorre fra due interrupt consecutivi del timer
									//TIM16; NOTA: valore massimo ammissibile = 4166, che equivale a circa 69,6 minuti.

#define DATA_COLLECT_INTERVAL	1	//intervallo di tempo, espresso in multipli di TIME16_IRQ_INTERVAL, che intercorre fra due letture
									//consecutive dei sensori

#define DATA_SEND_INTERVAL		5	//intervallo di tempo, espresso in multipli di DATA_COLLECT_INTERVAL, che intercorre fra due invii
									//consecutivi di dati dei sensori


#endif /* MACRO_DEF_H_ */

