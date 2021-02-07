#include "Command.h"

/*
 * ----------------
 * Helper functions
 * ----------------
 */

char handleOnOffCommand(Command cmd)
{
    if (cmd[1] == 1)
    {
        writeStringInGlobalBuffer(ack);
        writeStringInGlobalBuffer(space);
        writeStringInGlobalBuffer(on);

        return 1;
    }
    else if (cmd[1] == 0)
    {
        writeStringInGlobalBuffer(ack);
        writeStringInGlobalBuffer(space);
        writeStringInGlobalBuffer(off);

        return 0;
    }
    else
    {
        writeStringInGlobalBuffer(error);

        return -1;
    }
}

float handleFloatCommand(Command cmd)
{
    float value;

    if (cmd[2] == NULL_COMMAND_KEY)
    {
        value = 0;
    }
    else
    {
        value = cmd[2];
    }

    while (value >= 1.0)
    {
        value /= 10.0;
    }

    if (cmd[1] == NULL_COMMAND_KEY)
    {
        writeStringInGlobalBuffer(error);

        return NAN;
    }
    else
    {
        value += cmd[1];

        writeStringInGlobalBuffer(ack);
        writeStringInGlobalBuffer(space);
        writeFloatInGlobalBuffer(value, 4, 2);

        return value;
    }

}

void handleTimingCommand(Command cmd, ScheduledTask *task)
{
    if (cmd[1] == NULL_COMMAND_KEY)
    {
        writeStringInGlobalBuffer(error);
    }
    else
    {
        setTaskRunEvery(task, cmd[1]);
        writeStringInGlobalBuffer(ack);
        writeStringInGlobalBuffer(space);
    }
}

/*
 * -------------
 * GET functions
 * -------------
 */

void handleGetHeatingSystemState(void)
{
    if (getHeatingSystemState() == STARTED_STATE)
    {
        writeStringInGlobalBuffer(started);
    }
    else if (getHeatingSystemState() == STOPPED_STATE)
    {
        writeStringInGlobalBuffer(stopped);
    }
    else
    {
        writeStringInGlobalBuffer(disabled);
    }
}

void handleGetDataSenderState(void)
{
    if (getDataSenderState() == ON_STATE)
    {
        writeStringInGlobalBuffer(on);
    }
    else
    {
        writeStringInGlobalBuffer(off);
    }
}

void handleGetTargetTemperature(void)
{
    writeFloatInGlobalBuffer(getTargetTemperature(), 4, 2);
}

void handleGetDeltaTemperature(void)
{
    writeFloatInGlobalBuffer(getDeltaTemperature(), 4, 2);
}

void handleGetLCDState(void)
{
    if (getLCDState() == OFF_STATE)
    {
        writeStringInGlobalBuffer(off);
    }
    else
    {
        writeStringInGlobalBuffer(on);
    }
}

void handleGetBrewingTemperature(void)
{
    if (getBrewingTemperature() == UNKNOWN_TEMPERATURE)
    {
        writeStringInGlobalBuffer(unknown);
    }
    else
    {
        writeFloatInGlobalBuffer(getBrewingTemperature(), 4, 2);
    }
}

void handleGetRoomTemperature(void)
{
    if (getRoomTemperature() == UNKNOWN_TEMPERATURE)
    {
        writeStringInGlobalBuffer(unknown);
    }
    else
    {
        writeFloatInGlobalBuffer(getRoomTemperature(), 4, 2);
    }
}

/*
 * -------------------
 * SET state functions
 * -------------------
 */

void handleSetTargetTemperature(Command cmd)
{
    float targetTemperature = handleFloatCommand(cmd);

    if (targetTemperature == NAN)
    {
        return;
    }

    setTargetTemperature(targetTemperature);
}

void handleSetDeltaTemperature(Command cmd)
{
    float deltaTemperature = handleFloatCommand(cmd);

    if (deltaTemperature == NAN)
    {
        return;
    }

    setDeltaTemperature(deltaTemperature);
}

/*
 * --------------------
 * SET timing functions
 * --------------------
 */

void handleSetHeatingSystemTiming(Command cmd)
{
    handleTimingCommand(cmd, &heatingSystemTask);
}

void handleSetDataSenderTiming(Command cmd)
{
    handleTimingCommand(cmd, &dataSenderTask);
}

void handleSetLCDRefresherTiming(Command cmd)
{
    handleTimingCommand(cmd, &lcdRefresherTask);
}

void handleSetTemperatureReaderTiming(Command cmd)
{
    handleTimingCommand(cmd, &temperatureReaderTask);
}

/*
 * -----------
 * Run command
 * -----------
 */

void runCommand(Command cmd)
{
    emptyGlobalBuffer();

    switch (cmd[0])
    {
        case GET_ACK:
            writeStringInGlobalBuffer(ack);
            break;
        case GET_HEATING_SYSTEM_STATE:
            handleGetHeatingSystemState();
            break;
        case GET_DATA_SENDER_STATE:
            handleGetDataSenderState();
            break;
        case GET_TARGET_TEMPERATURE:
            handleGetTargetTemperature();
            break;
        case GET_DELTA_TEMPERATURE:
            handleGetDeltaTemperature();
            break;
        case GET_LCD_STATE:
            handleGetLCDState();
            break;
        case GET_BREWING_TEMPERATURE:
            handleGetBrewingTemperature();
            break;
        case GET_ROOM_TEMPERATURE:
            handleGetRoomTemperature();
            break;

        case SET_TARGET_TEMPERATURE:
            handleSetTargetTemperature(cmd);
            break;
        case SET_DELTA_TEMPERATURE:
            handleSetDeltaTemperature(cmd);
            break;

        case SET_HEATING_SYSTEM_TIMING:
            handleSetHeatingSystemTiming(cmd);
            break;
        case SET_DATA_SENDER_TIMING:
            handleSetDataSenderTiming(cmd);
            break;
        case SET_LCD_REFRESHER_TIMING:
            handleSetLCDRefresherTiming(cmd);
            break;
        case SET_TEMPERATURE_READER_TIMING:
            handleSetTemperatureReaderTiming(cmd);
            break;

        case TIMEOUT_EXPIRED:
            writeStringInGlobalBuffer("TE");
            break;
        case UNRECOGNIZED_CHAR:
            writeStringInGlobalBuffer("UC");
            break;
        case NULL_COMMAND_KEY:
            writeStringInGlobalBuffer("NCK");
            break;
        default:
            writeStringInGlobalBuffer(error);
    }

    COMM_SERIAL.println(globalBuffer);

    // wait a bit to be sure that the response was read
    // don't delete this delay!
    delay(1000);
}

void flushCommand(Command cmd)
{
    uint8_t i;

    for (i = 0; i < COMMAND_ARRAY_LENGTH; i++)
    {
        cmd[i] = NULL_COMMAND_KEY;
    }
}
