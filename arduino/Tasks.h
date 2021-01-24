#ifndef __TASKS_H__
#define __TASKS_H__

#include <TaskScheduler.h>

#include "DataSender.h"
#include "HeatingSystem.h"
#include "TemperatureReader.h"
#include "LCD.h"

DECLARE_TASK(dataSenderTask);
DECLARE_TASK(heatingSystemTask);
DECLARE_TASK(temperatureReaderTask);
DECLARE_TASK(lcdRefresherTask);

#endif // __TASKS_H__
