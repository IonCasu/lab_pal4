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

/**
 * @file timer_interface.h
 * @brief Timer interface definition for MQTT client.
 *
 * Defines an interface to timers that can be used by other system
 * components.  MQTT client requires timers to handle timeouts and
 * MQTT keep alive.
 * Starting point for porting the SDK to the timer hardware layer of a new platform.
 */

#ifndef __TIMER_INTERFACE_H_
#define __TIMER_INTERFACE_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * The platform specific timer header that defines the Timer struct
 */
#include "timer_platform.h"
#include "stm32l4xx_hal.h"

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Timer Type
 *
 * Forward declaration of a timer struct.  The definition of this struct is
 * platform dependent.  When porting to a new platform add this definition
 * in "timer_<platform>.h" and include that file above.
 *
 */
typedef struct Timer Timer;

char TimerIsExpired(Timer*);
void TimerCountdownMS(Timer*, unsigned int);
void TimerCountdown(Timer*, unsigned int);
int TimerLeftMS(Timer*);

void TimerInit(Timer*);
#ifdef __cplusplus
}
#endif

#endif //__TIMER_INTERFACE_H_
