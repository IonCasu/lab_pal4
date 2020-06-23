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
  
void sleep(int DelaySec);
void TimerCountdownMS(Timer* timer, uint32_t timeout_ms);
void TimerCountdown(Timer* timer, uint32_t timeout);
uint32_t TimerLeftMS(Timer* timer);
bool TimerIsExpired(Timer* timer);
void TimerInit(Timer* timer);


  
bool TimerIsExpired(Timer *timer) {
  return (TimerLeftMS(timer) > 0) ? false : true;
}

void TimerCountdownMS(Timer *timer, uint32_t timeout) {
  uint32_t tickstart = 0;

 // __disable_irq();

  tickstart = HAL_GetTick();
  timer->end_time = tickstart + timeout;

 // __enable_irq();
}

uint32_t TimerLeftMS(Timer *timer) {
  uint32_t tickstart = 0;

 // __disable_irq();

  tickstart = HAL_GetTick();
  long left = timer->end_time - tickstart;

  //__enable_irq();

  return (left < 0) ? 0 : left;
}

void TimerCountdown(Timer *timer, uint32_t timeout) {
  uint32_t tickstart = 0;

  //__disable_irq();
 
  tickstart = HAL_GetTick();
  timer->end_time = tickstart + (timeout * 1000);
 
 // __enable_irq();
} 

void TimerInit(Timer *timer) {
  timer->end_time = 0;
}


#ifdef __cplusplus
}
#endif
