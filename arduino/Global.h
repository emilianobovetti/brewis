#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <SoftwareSerial.h>
#include <TaskScheduler.h>
#include "LiquidCrystalImproved.h"
#include "Const.h"

#include "TemperatureReader.h"
#include "HeatingSystem.h"
#include "LCDRefresher.h"
#include "DataSender.h"

/*
 * -----------------
 * Tasks declaration
 * -----------------
 */

DECLARE_TASK(dataSenderTask);
DECLARE_TASK(heatingSystemTask);
DECLARE_TASK(temperatureReaderTask);
DECLARE_TASK(lcdRefresherTask);

/*
 * ----------------
 * Global resources
 * ----------------
 */

extern LiquidCrystalImproved lcd;

extern SoftwareSerial bluetooth;

/*
 * --------------------
 * Global string buffer
 * --------------------
 */

extern char globalBuffer[GLOBAL_STRING_BUFFER_SIZE];

/*
 * --------------
 * Common strings
 * --------------
 */

extern const char *heatingSystem;
extern const char *sendDataSystem;

extern const char *started;
extern const char *stopped;
extern const char *enabled;
extern const char *disabled;

extern const char *on;
extern const char *off;

extern const char *error;
extern const char *ack;

extern const char *unknown;

extern const char* space;

#endif // __GLOBAL_H__
