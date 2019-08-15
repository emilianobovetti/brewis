#include <TaskScheduler.h>
#include "Settings.h"
#include "Global.h"

#include "TemperatureReader.h"
#include "ButtonsReader.h"
#include "HeatingSystem.h"
#include "LCDRefresher.h"
#include "DataReceiver.h"
#include "SystemState.h"
#include "DataSender.h"

void setup(void)
{
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
    readButtons();
    readInputData();

    runScheduledTasks();
}
