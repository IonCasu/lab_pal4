/*
 * Copyright 2010-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

/**  
 * @file timer.c
 * @brief Linux implementation of the timer interface.
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "timer_interface.h"
  
unsigned long MilliTimer;
unsigned long sysSeconds=0;
unsigned long sysMinutes=0;
unsigned long sysHours=0;

void HAL_IncTick(void)
{
	uwTick += uwTickFreq;
	MilliTimer++;

	if(uwTick % 1000 ==0){
		sysSeconds++;
		if(sysSeconds % 60 == 0){
			sysMinutes++;
			sysSeconds = 0;
			if(sysMinutes % 60 == 0){
				sysHours++;
				sysMinutes = 0;
			}
		}
	}
}
  
char TimerIsExpired(Timer* timer)
{
	long left = timer->end_time - MilliTimer;
	return (left < 0);
}

void TimerCountdownMS(Timer* timer, unsigned int timeout)
{
	timer->end_time = MilliTimer + timeout;
}

int TimerLeftMS(Timer* timer)
{
	long left = timer->end_time - MilliTimer;
	return (left < 0) ? 0 : left;
}


void TimerCountdown(Timer* timer, unsigned int timeout)
{
	timer->end_time = MilliTimer + (timeout * 1000);
}

void TimerInit(Timer* timer)
{
	timer->end_time = 0;
}


#ifdef __cplusplus
}
#endif
