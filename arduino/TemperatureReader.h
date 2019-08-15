#ifndef __TEMPERATURE_READER_H__
#define __TEMPERATURE_READER_H__

#include <OneWire.h>
#include <DallasTemperature.h>
#include "SystemState.h"
#include "Settings.h"
#include "Global.h"

/*
 * ---------------------
 * System initialization
 * ---------------------
 */

void initializeTemperatureReader(void);

/*
 * ---------------------
 * System state modifier
 * ---------------------
 */

void enableTemperatureReader(void);

void disableTemperatureReader(void);

/*
 * -------------
 * Task callback
 * -------------
 */

void readTemperature(void);

/*
 * ---------------
 * Helper function
 * ---------------
 */

#endif // __TEMPERATURE_READER_H__
