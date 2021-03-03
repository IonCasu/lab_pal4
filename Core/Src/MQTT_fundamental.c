/*
 * MQTT_fundamental.c
 *
 *  Created on: 18 gen 2021
 *      Author: cocco
 */

#include "MQTT_fundamental.h"

void MQTT_setup()
{
	/* Inizializzazione parametri MQTT */
	uint8_t ret;

	MQTTPacket_connectData options = MQTTPacket_connectData_initializer;
	options.willFlag = 0;
	options.MQTTVersion = 3;
	options.clientID.cstring = ID_OSO;
	options.username.cstring = USERNME_MQTT;
	options.password.cstring = PASSW_MQTT;
	options.keepAliveInterval = 600;
  	options.cleansession = 1;
  	/*options.will.message.cstring = "message";
  	  options.will.qos = 1;
  	  options.will.retained = 0;
  	  options.will.topicName.cstring = "topic";*/

  	/* Inizializzazione connessione MQTT e connessione al broker */
	MQTTClientInit(&c, &network, WIFI_WRITE_TIMEOUT, writebuf, WRITE_BUF_SIZE, readbuf, READ_BUF_SIZE);
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

    /* SOTTOSCRIZIONE AL TOPIC TIME */
	MQTTSubackData subTime;
    char* time_recv_topic = TOPIC_RECV_TIME;
    uint8_t subsqos = QOS_SUB;

    ret = MQTTSubscribeWithResults(&c, time_recv_topic, subsqos, time_arrived, &subTime);
    if (ret == 0)
    {
    	TERMOUT("> Subscribe to topic: %s correct\n", time_recv_topic);
    }
    else
    {
    	TERMOUT("> Subscribe to topic: %s not correct\n", time_recv_topic);
    }

    /* SOTTOSCRIZIONE AL TOPIC OSO */
	MQTTSubackData subData;
    char* topic_oso = TOPIC_OSO;

    ret = MQTTSubscribeWithResults(&c, topic_oso, subsqos, data_arrived, &subData);
    if (ret == 0)
    {
    	TERMOUT("> Subscribe to topic: %s correct\n", time_recv_topic);
    }
    else
    {
    	TERMOUT("> Subscribe to topic: %s not correct\n", time_recv_topic);
    }

}

uint8_t request_time()
{
	/* Messaggio contenente la richiesta dell'orario al server */
	MQTTMessage time_msg;
    uint8_t qos = QOS_PUB;
    int ret = 0;
    char* time_req_topic = TOPIC_REQ_TIME;

    time_msg.payload = "{'caller':'OSO_1'}";
    time_msg.payloadlen = strlen(time_msg.payload);
    time_msg.qos = qos;
    time_msg.retained = 0;
    time_msg.dup = 0;

	ret = MQTTPublish(&c, time_req_topic, &time_msg);

	return ret;
}

uint8_t send_data(uint8_t diff_measures,char** measures_name, char** measure_unit, char** data_type, uint8_t* values,
																			int* measures_intervals, char** timestamps)
{
	MQTTMessage data_msg;
    uint8_t qos = QOS_PUB;
    int ret = 0;
    char* data_send_topic = TOPIC_OSO;

	char buffer[2000];
	char temp[2000];
	sprintf(buffer,"{\"items\":[");

    uint8_t count = 0;
    uint8_t count_intervals = 0;
    uint8_t index_value = 0;
    while (count!=diff_measures)
    {
    	sprintf(temp, "{\"measure\": \"%s\","
    			"\"measure_unit\": \"%s\","
    			"\"data_type\": \"%s\","
    			"\"data_source\": \"PARK_MO001_OSO012345ABCDEF\","
    			"\"values\":[",
				measures_name[count],
				measure_unit[count],
				data_type[count]);
    	strcat(buffer, temp);

    	while (count_intervals!=measures_intervals[count])
    	{
			sprintf(temp, "{\"value\": %d,"
					"\"data_start_time\": \"%s\","
					"\"data_end_time\": \"%s\"}",
					values[index_value], timestamps[index_value], timestamps[index_value]
					);

        	strcat(buffer, temp);
        	if (count_intervals!=measures_intervals[count]-1)
        	{
            	strcat(buffer, ",");
        	}

    		index_value++;
			count_intervals++;
    	}
    	count_intervals = 0;
    	index_value=0;//TEST
    	strcat(buffer, "]}");

    	if (count!=diff_measures-1)
    	{
        	strcat(buffer, ",");
    	}

    	count++;
    }

	strcat(buffer, "]}");

    /* Messaggio da inviare al server contenente i dati che vogliamo inviare */
	data_msg.payload = buffer;
    data_msg.payloadlen = strlen(data_msg.payload);
    data_msg.qos = qos;
    data_msg.retained = 0;
    data_msg.dup = 0;

	ret = MQTTPublish(&c, data_send_topic, &data_msg);

	return ret;
}

void data_arrived(MessageData* md)
{
	char message[md->message->payloadlen+2];
	memset(message, '\0', sizeof(message));
	strncpy(message, (char*)md->message->payload, md->message->payloadlen);
	TERMOUT("> Good message lengths, payloadlen was %d\n", md->message->payloadlen);
//	TERMOUT("> Data payload was %s\n", (char*)md->message->payload);
}

void time_arrived(MessageData* md)
{
	char* messageTime;
	char timeString[md->message->payloadlen+2];
	memset(timeString, '\0', sizeof(timeString));
	strncpy(timeString, (char*)md->message->payload, md->message->payloadlen);
	TERMOUT("> Good time message, payloadlen was %d\n", md->message->payloadlen);
	TERMOUT("> Time payload was %s\n", timeString);

	messageTime = md->message->payload;

	/*Aggiorno l'RTC*/
	/*Aggiornamento dell'RTC*/
	uint8_t server_year[4];
	uint8_t server_month[2];
	uint8_t server_date[2];
	uint8_t server_hour[2];
	uint8_t server_minutes[2];
	uint8_t server_seconds[2];
	int i;

    //scompatto il messaggio col tempo/data
    for(i=0;i<2;i++){
    	server_year[i]=(uint8_t)messageTime[11+i];
		server_month[i] = (uint8_t)messageTime[14+i];
		server_date[i] = (uint8_t)messageTime[17+i];
		server_hour[i] = (uint8_t)messageTime[20+i];
		server_minutes[i] = (uint8_t)messageTime[23+i];
		server_seconds[i] =(uint8_t) messageTime[26+i];
    }

    //definisco e popolo due strutture con le informazioni relative alla data e al tempo
    RTC_TimeTypeDef sTime = {0};
    RTC_DateTypeDef sDate = {0};
    sDate.Year = (uint8_t)atoi((char*)&server_year);
    sDate.Month = (uint8_t)atoi((char*)&server_month);
    sDate.Date = (uint8_t)atoi((char*)&server_date);

    sTime.Hours = (uint8_t)atoi((char*)&server_hour);
    sTime.Minutes = (uint8_t)atoi((char*)&server_minutes);
    sTime.Seconds = (uint8_t)atoi((char*)&server_seconds);

    //configuro e avvio l'RTC
    HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
    HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
}
