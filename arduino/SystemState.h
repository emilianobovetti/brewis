#ifndef __SYSTEM_STATE_H__
#define __SYSTEM_STATE_H__

#include <Arduino.h>
#include "Global.h"

#define DATA_SENDER_STATE_TYPE enum OnOffState
#define HEATING_SYSTEM_STATE_TYPE enum StartStopDisabledState
#define TEMPERATURE_TYPE float

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

TEMPERATURE_TYPE getTargetTemperature(void);

TEMPERATURE_TYPE getDeltaTemperature(void);

TEMPERATURE_TYPE getBrewingTemperature(void);

TEMPERATURE_TYPE getRoomTemperature(void);

/*
 * -------------------
 * System state setter
 * -------------------
 */

void setDataSenderState(DATA_SENDER_STATE_TYPE);

void setHeatingSystemState(HEATING_SYSTEM_STATE_TYPE);

void setTargetTemperature(TEMPERATURE_TYPE);

void setDeltaTemperature(TEMPERATURE_TYPE);

void setBrewingTemperature(TEMPERATURE_TYPE);

void setRoomTemperature(TEMPERATURE_TYPE);

#endif // __SYSTEM_STATE_H__
