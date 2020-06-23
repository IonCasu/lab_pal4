/*******************************************************************************
 * Copyright (c) 2014 IBM Corp.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * and Eclipse Distribution License v1.0 which accompany this distribution.
 *
 * The Eclipse Public License is available at
 *    http://www.eclipse.org/legal/epl-v10.html
 * and the Eclipse Distribution License is available at
 *   http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * Contributors:
 *    Allan Stockdill-Mander - initial API and implementation and/or initial documentation
 *******************************************************************************/
#include "wifi.h"

#define SSID     "Rete-Fastweb"
#define PASSWORD "s1E2t3T4e5?6"
#define CONNECTION_TRIAL_MAX          3
#define LED2 						  0

#define TERMINAL_USE
#if defined (TERMINAL_USE)
#define TERMOUT(...)  printf(__VA_ARGS__)
#else
#define TERMOUT(...)
#endif

typedef struct Network Network;

struct Network
{
	int my_socket;
	int (*mqttread) (Network*, unsigned char*, int, int);
	int (*mqttwrite) (Network*, unsigned char*, int, int);
	void (*disconnect) (Network*);
};
int net_read(Network*, unsigned char*, int, int);
int net_write(Network*, unsigned char*, int, int);
void net_disconnect(Network*);
void NewNetwork(Network*);

int ConnectNetwork(Network*, uint8_t*, int);
//int TLSConnectNetwork(Network*, char*, int, SlSockSecureFiles_t*, unsigned char, unsigned int, char);
