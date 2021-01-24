#ifndef __SYSTEM_STATE_H__
#define __SYSTEM_STATE_H__

#include <Arduino.h>
#include "Const.h"

#define DATA_SENDER_STATE_TYPE enum OnOffState
#define HEATING_SYSTEM_STATE_TYPE enum StartStopDisabledState
#define TARGET_TEMPERATURE_TYPE float
#define DELTA_TEMPERATURE_TYPE float
#define CURRENT_TEMPERATURE_TYPE float

/*
 * Only the user can switch ON/OFF state
 */
enum OnOffState { OFF_STATE, ON_STATE };

/*
 * The system could start or stop some subsystems automatically,
 * but the user can can always disable them
 */
enum StartStopDisabledState { DISABLED_STATE, STOPPED_STATE, STARTED_STATE };

/*
 * ---------------------
 * System initialization
 * ---------------------
 */

void initializeSystemState(void);

/*
 * -------------------
 * System state getter
 * -------------------
 */

DATA_SENDER_STATE_TYPE getDataSenderState(void);

HEATING_SYSTEM_STATE_TYPE getHeatingSystemState(void);

TARGET_TEMPERATURE_TYPE getTargetTemperature(void);

DELTA_TEMPERATURE_TYPE getDeltaTemperature(void);

CURRENT_TEMPERATURE_TYPE getCurrentTemperature(void);

/*
 * -------------------
 * System state setter
 * -------------------
 */

void setDataSenderState(DATA_SENDER_STATE_TYPE);

void setHeatingSystemState(HEATING_SYSTEM_STATE_TYPE);

void setTargetTemperature(TARGET_TEMPERATURE_TYPE);

void setDeltaTemperature(DELTA_TEMPERATURE_TYPE);

void setCurrentTemperature(CURRENT_TEMPERATURE_TYPE);

#endif // __SYSTEM_STATE_H__
