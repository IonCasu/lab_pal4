/*
 * connection_fundamental.c
 *
 *  Created on: 18 gen 2021
 *      Author: cocco
 */
#include "connection_fundamental.h"

int board_wifi_init(const char* myssid, const char* mypassword)
{
	uint8_t  MAC_Addr[6];
	uint8_t  IP_Addr[4];
	char macprint[17];

	//Network Initialization
	if(WIFI_Init() ==  WIFI_STATUS_OK)
	{
		TERMOUT("> WIFI Module Initialized.\n");
		if(WIFI_GetMAC_Address(MAC_Addr) == WIFI_STATUS_OK)
		{
			snprintf(macprint,sizeof(macprint),"%X:%X:%X:%X:%X:%X",MAC_Addr[0],MAC_Addr[1],\
					 MAC_Addr[2],MAC_Addr[3],MAC_Addr[4],MAC_Addr[5]);
			TERMOUT("> es-wifi module MAC Address : %s\n",macprint);
		}
		else
		{
			TERMOUT("> ERROR : CANNOT get MAC address\n");
		}
	}
	else
	{
		TERMOUT("> ERROR : WIFI Module cannot be initialized.\n");
		return WIFI_STATUS_ERROR;
	}

	WIFI_Status_t retwifi = WIFI_Connect(myssid, mypassword, WIFI_ECN_WPA2_PSK);
	if(retwifi!=WIFI_STATUS_OK)
	{
		TERMOUT("> Error in WIFI_Connect(): retwifi=%x.\n",retwifi);
		return WIFI_STATUS_ERROR;
	}
	else
	{
		TERMOUT("> Joined WiFi network \"%s\".\n",myssid);
	}

	if(WIFI_GetIP_Address(IP_Addr) == WIFI_STATUS_OK)
	{
		TERMOUT("> WIFI module got IP Address : %d.%d.%d.%d\n",
				IP_Addr[0],IP_Addr[1],IP_Addr[2],IP_Addr[3]);
	}
	else
	{
		TERMOUT("> ERROR : I cannot obtain the IP address.\n");
		return WIFI_STATUS_ERROR;
	}

	return WIFI_STATUS_OK;
}

WIFI_Status_t ClientConnectNViaDNS(Network* n, const char *myremoteaddr, uint16_t myremoteport)
{
	uint8_t resolvedip[] = {0,0,0,0};
	WIFI_Status_t ret;

	if (WIFI_GetHostAddress(myremoteaddr, resolvedip) == WIFI_STATUS_OK)
	{
		TERMOUT("> Host address resolved\n");
	}
	else
	{
		TERMOUT("> ERROR : CANNOT get host address\n");
		ret = WIFI_STATUS_ERROR;
		return ret;
	}

	TERMOUT("> Opening TCP Connection...");
	ret = WIFI_OpenClientConnection(n->my_socket, WIFI_TCP_PROTOCOL,
				"TCP_CLIENT", resolvedip, myremoteport, 0);

	return ret;
}

void network_init(Network* n) {
	n->my_socket = (uint32_t) 0;
	n->mqttread = net_read;
	n->mqttwrite = net_write;
	n->disconnect = net_disconnect;
}

int net_read(Network* n, unsigned char* buffer, int len, int timeout_ms) {

	int ret;
	ret = mbedtls_ssl_read(&ssl, buffer,(size_t)len);
	return ret;
}

int net_write(Network* n, unsigned char* buffer, int len, int timeout_ms) {

	int ret;
	ret = mbedtls_ssl_write(&ssl, buffer,(size_t)len);
	return ret;
}

void net_disconnect(Network* n) {

	WIFI_CloseClientConnection(n->my_socket);
	return;
}
