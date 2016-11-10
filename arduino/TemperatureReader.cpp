#include "TemperatureReader.h"

static OneWire oneWire(DS18B20_BUS_PIN);
static DallasTemperature sensors(&oneWire);

void initializeTemperatureReader(void)
{
    sensors.begin();

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
    sensors.requestTemperatures();
    setCurrentTemperature(sensors.getTempCByIndex(0));
}
