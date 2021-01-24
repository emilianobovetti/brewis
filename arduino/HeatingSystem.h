#ifndef __HEATING_SYSTEM_H__
#define __HEATING_SYSTEM_H__

#include <Arduino.h>
#include "SystemState.h"
#include "Tasks.h"

/*
 * ---------------------
 * System initialization
 * ---------------------
 */

void initializeHeatingSystem(void);

/*
 * ---------------------
 * System state modifier
 * ---------------------
 */

void enableHeatingSystem(void);

void disableHeatingSystem(void);

void startHeatingSystem(void);

void stopHeatingSystem(void);

/*
 * -------------
 * Task callback
 * -------------
 */

void checkHeatingSystem(void);

#endif // __HEATING_SYSTEM_H__
