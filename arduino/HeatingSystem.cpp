#include "HeatingSystem.h"

void initializeHeatingSystem(void)
{
    pinMode(HEATING_SYSTEM_RELAY_PIN, OUTPUT);

    disableHeatingSystem();
}

void forceStartHeatingSystem(void)
{
    digitalWrite(HEATING_SYSTEM_RELAY_PIN, LOW);
    setHeatingSystemState(STARTED_STATE);
}

void startHeatingSystem(void)
{
    // if heating system state is disabled or already started
    // we don't have to do nothing
    if (getHeatingSystemState() == STOPPED_STATE)
    {
        forceStartHeatingSystem();
    }
}

void forceStopHeatingSystem(void)
{
    digitalWrite(HEATING_SYSTEM_RELAY_PIN, HIGH);
    setHeatingSystemState(STOPPED_STATE);
}

void stopHeatingSystem(void)
{
    if (getHeatingSystemState() == STARTED_STATE)
    {
        forceStopHeatingSystem();
    }
}

void enableHeatingSystem(void)
{
    setTaskState(&heatingSystemTask, RUNNING);
    setHeatingSystemState(STOPPED_STATE);
    checkHeatingSystem();
}

void disableHeatingSystem(void)
{
    setTaskState(&heatingSystemTask, NOT_RUNNING);
    forceStopHeatingSystem();
    setHeatingSystemState(DISABLED_STATE);
}

void checkHeatingSystem(void)
{
    float brewingTemperature = getBrewingTemperature();
    bool isTemperatureInvalid = !isValidTemperature(brewingTemperature);
    bool isHeatingSystemDisabled = getHeatingSystemState() == DISABLED_STATE;

    if (isTemperatureInvalid || isHeatingSystemDisabled)
    {
        return;
    }

    float maxTemperature = getTargetTemperature() + getDeltaTemperature();
    float minTemperature = getTargetTemperature() - getDeltaTemperature();

    if (brewingTemperature < minTemperature)
    {
        startHeatingSystem();
    }
    else if (brewingTemperature > maxTemperature)
    {
        stopHeatingSystem();
    }
}
