#include "HeatingSystem.h"

void initializeHeatingSystem(void)
{
    pinMode(HEATING_SYSTEM_RELAY_PIN, OUTPUT);

    disableHeatingSystem();
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
    /*
     * stopHeatingSystem() must be called before
     * heating_system_state goes on DISABLED_STATE
     */
    stopHeatingSystem();
    setHeatingSystemState(DISABLED_STATE);
}

void startHeatingSystem(void)
{
    // if heating system state is disabled or already started
    // we don't have to do nothing
    if (getHeatingSystemState() == STOPPED_STATE)
    {
        digitalWrite(HEATING_SYSTEM_RELAY_PIN, HIGH);
        setHeatingSystemState(STARTED_STATE);
    }
}

void stopHeatingSystem(void)
{
    if (getHeatingSystemState() == STARTED_STATE)
    {
        digitalWrite(HEATING_SYSTEM_RELAY_PIN, LOW);
        setHeatingSystemState(STOPPED_STATE);
    }
}

void checkHeatingSystem(void)
{
    float maxTemperature = getTargetTemperature() + getDeltaTemperature();
    float minTemperature = getTargetTemperature() - getDeltaTemperature();
    float brewingTemperature = getBrewingTemperature();

    if (brewingTemperature < minTemperature)
    {
        startHeatingSystem();
    }
    else if (brewingTemperature > maxTemperature)
    {
        stopHeatingSystem();
    }
}
