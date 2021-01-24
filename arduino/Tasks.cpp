#include "Tasks.h"

DEFINE_TASK(dataSenderTask, sendData, 20000);
DEFINE_TASK(heatingSystemTask, checkHeatingSystem, 5000);
DEFINE_TASK(temperatureReaderTask, readTemperature, 5000);
DEFINE_TASK(lcdRefresherTask, refreshLCD, 5000);
