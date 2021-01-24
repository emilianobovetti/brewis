#include "TemperatureReader.h"

static OneWire temp0Bus(TEMP_0_BUS_PIN);
static OneWire temp1Bus(TEMP_1_BUS_PIN);
static DallasTemperature temp0(&temp0Bus);
static DallasTemperature temp1(&temp1Bus);

void initializeTemperatureReader(void)
{
    temp0.begin();
    temp1.begin();

    enableTemperatureReader();
}

void enableTemperatureReader(void)
{
    setTaskState(&temperatureReaderTask, RUNNING);
}

void disableTemperatureReader(void)
{
    setTaskState(&temperatureReaderTask, NOT_RUNNING);
}

void readTemperature(void)
{
    temp0.requestTemperatures();
    setBrewingTemperature(temp0.getTempCByIndex(0));

    temp1.requestTemperatures();
    setRoomTemperature(temp1.getTempCByIndex(0));
}
