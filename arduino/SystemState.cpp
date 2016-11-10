#include "SystemState.h"

#define STARTING_EEPROM_ADDRESS 0

#define DATA_SENDER_STATE_EEPROM_ADDRESS \
    STARTING_EEPROM_ADDRESS
#define STARTING_TEMPERATURE_EEPROM_ADDRESS \
    DATA_SENDER_STATE_EEPROM_ADDRESS + sizeof (DATA_SENDER_STATE_TYPE)
#define STOPPING_TEMPERATURE_EEPROM_ADDRESS \
    STARTING_TEMPERATURE_EEPROM_ADDRESS + sizeof (STARTING_TEMPERATURE_TYPE)

static struct
{
    DATA_SENDER_STATE_TYPE dataSenderState;

    HEATING_SYSTEM_STATE_TYPE heatingSystemState;

    STARTING_TEMPERATURE_TYPE startingTemperature;

    STOPPING_TEMPERATURE_TYPE stoppingTemperature;

    CURRENT_TEMPERATURE_TYPE currentTemperature;

    CURRENT_DENSITY_TYPE currentDensity;

} system;

void initializeSystemState(void)
{
    EEPROM.get(DATA_SENDER_STATE_EEPROM_ADDRESS, system.dataSenderState);
    EEPROM.get(STARTING_TEMPERATURE_EEPROM_ADDRESS, system.startingTemperature);
    EEPROM.get(STOPPING_TEMPERATURE_EEPROM_ADDRESS, system.stoppingTemperature);

    if (system.dataSenderState != OFF_STATE && system.dataSenderState != ON_STATE)
    {
        setDataSenderState(OFF_STATE);
    }

    // TODO
    // warning: dereferencing type-punned pointer will break strict-aliasing rules [-Wstrict-aliasing]
    unsigned int ones = -1;
    unsigned int startingTemperature = *((unsigned int*) &system.startingTemperature);
    unsigned int stoppingTemperature = *((unsigned int*) &system.stoppingTemperature);

    if (startingTemperature == ones)
    {
        setStartingTemperature(DEFAULT_HS_STARTING_TEMPERATURE);
    }

    if (stoppingTemperature == ones)
    {
        setStoppingTemperature(DEFAULT_HS_STOPPING_TEMPERATURE);
    }

    system.heatingSystemState = DISABLED_STATE;
    system.currentTemperature = UNKNOWN_TEMPERATURE;
    system.currentDensity = UNKNOWN_DENSITY;
}

/*
 * -------------------
 * System state getter
 * -------------------
 */

DATA_SENDER_STATE_TYPE getDataSenderState(void)
{
    return system.dataSenderState;
}

HEATING_SYSTEM_STATE_TYPE getHeatingSystemState(void)
{
    return system.heatingSystemState;
}

STARTING_TEMPERATURE_TYPE getStartingTemperature(void)
{
    return system.startingTemperature;
}

STOPPING_TEMPERATURE_TYPE getStoppingTemperature(void)
{
    return system.stoppingTemperature;
}

CURRENT_TEMPERATURE_TYPE getCurrentTemperature(void)
{
    return system.currentTemperature;
}

CURRENT_DENSITY_TYPE getCurrentDensity(void)
{
    return system.currentDensity;
}

/*
 * -------------------
 * System state setter
 * -------------------
 */

void setDataSenderState(DATA_SENDER_STATE_TYPE state)
{
    system.dataSenderState = state;
    EEPROM.put(DATA_SENDER_STATE_EEPROM_ADDRESS, system.dataSenderState);
}

void setHeatingSystemState(HEATING_SYSTEM_STATE_TYPE state)
{
    system.heatingSystemState = state;
}

void setStartingTemperature(STARTING_TEMPERATURE_TYPE temperature)
{
    system.startingTemperature = temperature;
    EEPROM.put(STARTING_TEMPERATURE_EEPROM_ADDRESS, system.startingTemperature);
}

void setStoppingTemperature(STOPPING_TEMPERATURE_TYPE temperature)
{
    system.stoppingTemperature = temperature;
    EEPROM.put(STOPPING_TEMPERATURE_EEPROM_ADDRESS, system.stoppingTemperature);
}

void setCurrentTemperature(CURRENT_TEMPERATURE_TYPE temperature)
{
    system.currentTemperature = temperature;
}

void setCurrentDensity(CURRENT_DENSITY_TYPE density)
{
    system.currentDensity = density;
}
