/*
 * Network.h
 *
 *  Created on: 19 gen 2021
 *      Author: cocco
 */

#ifndef INC_NETWORK_H_
#define INC_NETWORK_H_

typedef struct Network Network;
struct Network
{
	int my_socket;
	int (*mqttread) (Network*, unsigned char*, int, int);
	int (*mqttwrite) (Network*, unsigned char*, int, int);
	void (*disconnect) (Network*);
};

#endif /* INC_NETWORK_H_ */
