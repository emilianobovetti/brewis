#include <TaskScheduler.h>
#include "Global.h"

#include "TemperatureReader.h"
#include "SwitchesReader.h"
#include "HeatingSystem.h"
#include "DataReceiver.h"
#include "SystemState.h"
#include "DataSender.h"
#include "LCD.h"

void setup(void)
{
    COMM_SERIAL.begin(COMM_SERIAL_BAUD_RATE);

    initializeSwitchesReader();
    initializeSystemState();
    initializeDataReceiver();
    initializeDataSender();
    initializeHeatingSystem();
    initializeTemperatureReader();
    initializeLCDRefresher();

    /*
     * Add tasks to index. To exclude a task just delete it from here.
     */
    scheduleTask(&dataSenderTask);
    scheduleTask(&heatingSystemTask);
    scheduleTask(&temperatureReaderTask);
    scheduleTask(&lcdRefresherTask);
}

void loop(void)
{
    readSwitches();
    readInputData();

    runScheduledTasks();
}
