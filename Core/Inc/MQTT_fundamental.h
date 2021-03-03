/*
 * MQTT_fundamental.h
 *
 *  Created on: 18 gen 2021
 *      Author: cocco
 */

#ifndef INC_MQTT_FUNDAMENTAL_H_
#define INC_MQTT_FUNDAMENTAL_H_

#include <string.h>
#include "MQTTClient.h"
#include "macro_def.h"

extern Network network;
extern MQTTClient c;
extern char* messageTime;
extern RTC_HandleTypeDef hrtc;
extern RTC_TimeTypeDef structureTimeGet;
extern RTC_DateTypeDef structureDateGet;

uint8_t writebuf[WRITE_BUF_SIZE];
uint8_t readbuf[READ_BUF_SIZE];

void MQTT_setup();
uint8_t request_time();
uint8_t send_data(uint8_t diff_measures, char** measures_name, char** measure_unit, char** data_type, uint8_t* values,
																		int* measures_intervals, char** timestamps);
void data_arrived(MessageData* md);
void time_arrived(MessageData* md);

#endif /* INC_MQTT_FUNDAMENTAL_H_ */
