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

#include "Network.h"
extern mbedtls_ssl_context ssl;

uint16_t nlen;

int net_read(Network* n, unsigned char* buffer, int len, int timeout_ms) {

	int ret;
	//ret = mbedtls_net_recv(0, buffer,(size_t)len,(uint32_t)timeout_ms);
	ret = mbedtls_ssl_read(&ssl, buffer,(size_t)len);
	return ret;
}


int net_write(Network* n, unsigned char* buffer, int len, int timeout_ms) {

	int ret;
	ret = mbedtls_ssl_write(&ssl, buffer,(size_t)len);
	return ret;
}


/*void net_disconnect(Network* n) {
	sl_Close(n->my_socket);
}*/


void NewNetwork(Network* n) {
	n->my_socket = 0;
	n->mqttread = net_read;
	n->mqttwrite = net_write;
	//n->disconnect = net_disconnect;
}

/*int TLSConnectNetwork(Network *n, char* addr, int port, SlSockSecureFiles_t* certificates, unsigned char sec_method, unsigned int cipher, char server_verify) {
	SlSockAddrIn_t sAddr;
	int addrSize;
	int retVal;
	unsigned long ipAddress;

	retVal = sl_NetAppDnsGetHostByName(addr, strlen(addr), &ipAddress, AF_INET);
	if (retVal < 0) {
		return -1;
	}

	sAddr.sin_family = AF_INET;
	sAddr.sin_port = sl_Htons((unsigned short)port);
	sAddr.sin_addr.s_addr = sl_Htonl(ipAddress);

	addrSize = sizeof(SlSockAddrIn_t);

	n->my_socket = sl_Socket(SL_AF_INET,SL_SOCK_STREAM, SL_SEC_SOCKET);
	if (n->my_socket < 0) {
		return -1;
	}

	SlSockSecureMethod method;
	method.secureMethod = sec_method;
	retVal = sl_SetSockOpt(n->my_socket, SL_SOL_SOCKET, SL_SO_SECMETHOD, &method, sizeof(method));
	if (retVal < 0) {
		return retVal;
	}

	SlSockSecureMask mask;
	mask.secureMask = cipher;
	retVal = sl_SetSockOpt(n->my_socket, SL_SOL_SOCKET, SL_SO_SECURE_MASK, &mask, sizeof(mask));
	if (retVal < 0) {
		return retVal;
	}

	if (certificates != NULL) {
		retVal = sl_SetSockOpt(n->my_socket, SL_SOL_SOCKET, SL_SO_SECURE_FILES, certificates->secureFiles, sizeof(SlSockSecureFiles_t));
		if(retVal < 0)
		{
			return retVal;
		}
	}

	retVal = sl_Connect(n->my_socket, ( SlSockAddr_t *)&sAddr, addrSize);
	if( retVal < 0 ) {
		if (server_verify || retVal != -453) {
			sl_Close(n->my_socket);
			return retVal;
		}
	}

	SysTickIntRegister(SysTickIntHandler);
	SysTickPeriodSet(80000);
	SysTickEnable();

	return retVal;
}*/

int ConnectNetwork(Network* n, uint8_t* RemoteIP, int RemotePORT)
{
	uint8_t  MAC_Addr[6];
	uint8_t  IP_Addr[4];
	int32_t Socket = -1;
	int16_t Trials = CONNECTION_TRIAL_MAX;

	TERMOUT("****** WIFI Module in TCP Client mode demonstration ****** \n\n");
	TERMOUT("TCP Client Instructions :\n");
	TERMOUT("1- Make sure your Phone is connected to the same network that\n");
	TERMOUT("   you configured using the Configuration Access Point.\n");
	TERMOUT("2- Create a server by using the android application TCP Server\n");
	TERMOUT("   with port(8002).\n");
	TERMOUT("3- Get the Network Name or IP Address of your Android from the step 2.\n\n");

	if(WIFI_Init() ==  WIFI_STATUS_OK)
	{
		TERMOUT("> WIFI Module Initialized.\n");
	    if(WIFI_GetMAC_Address(MAC_Addr) == WIFI_STATUS_OK)
	    {
	      TERMOUT("> es-wifi module MAC Address : %X:%X:%X:%X:%X:%X\n",
	               MAC_Addr[0],
	               MAC_Addr[1],
	               MAC_Addr[2],
	               MAC_Addr[3],
	               MAC_Addr[4],
	               MAC_Addr[5]);
	    }
	    else
	    {
	      TERMOUT("> ERROR : CANNOT get MAC address\n");
	      //BSP_LED_On(LED2);
	    }

	    if( WIFI_Connect(SSID, PASSWORD, WIFI_ECN_WPA2_PSK) == WIFI_STATUS_OK)
	    {
	      TERMOUT("> es-wifi module connected \n");
	      if(WIFI_GetIP_Address(IP_Addr) == WIFI_STATUS_OK)
	      {
	        TERMOUT("> es-wifi module got IP Address : %d.%d.%d.%d\n",
	               IP_Addr[0],
	               IP_Addr[1],
	               IP_Addr[2],
	               IP_Addr[3]);

	        TERMOUT("> Trying to connect to Server: %d.%d.%d.%d:%d ...\n",
	               RemoteIP[0],
	               RemoteIP[1],
	               RemoteIP[2],
	               RemoteIP[3],
				   RemotePORT);

	        while (Trials--)
	        {
	          if( WIFI_OpenClientConnection(0, WIFI_TCP_PROTOCOL, "TCP_CLIENT", RemoteIP, RemotePORT, 0) == WIFI_STATUS_OK)
	          {
	            TERMOUT("> TCP Connection opened successfully.\n");
	            Socket = 0;
	            break;
	          }
	        }
	        if(Socket == -1)
	        {
	          TERMOUT("> ERROR : Cannot open Connection\n");
	          //BSP_LED_On(LED2);
	        }

	      }
	      else
	      {
	        TERMOUT("> ERROR : es-wifi module CANNOT get IP address\n");
	        //BSP_LED_On(LED2);
	      }
	    }
	    else
	    {
	      TERMOUT("> ERROR : es-wifi module NOT connected\n");
	      //BSP_LED_On(LED2);
	    }
	}
	else
	{
		TERMOUT("> ERROR : WIFI Module cannot be initialized.\n");
	    //BSP_LED_On(LED2);
	}
return 0;
}
