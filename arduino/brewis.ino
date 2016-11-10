#include <TaskScheduler.h>
#include "Parameters.h"
#include "Global.h"

#include "TemperatureReader.h"
#include "DensityReader.h"
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
    initializeDensityReader();
    initializeLCDRefresher();

    /*
     * Add tasks to index. To exclude a task just delete it from here.
     */
    scheduleTask(&dataSenderTask);
    scheduleTask(&heatingSystemTask);
    scheduleTask(&temperatureReaderTask);
    //scheduleTask(&densityReaderTask);
    scheduleTask(&lcdRefresherTask);
}

void loop(void)
{
    readButtons();
    readInputData();

    runScheduledTasks();
}
