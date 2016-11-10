#include "Command.h"

char tmp[8];

/*
 * -----------------------
 * Buffer writer functions
 * -----------------------
 */

inline void writeStrInBuffer(const char *str)
{
    strcat(globalBuffer, str);
}

inline void writeFloatInBuffer(float f)
{
    emptyString(tmp, 8);
    dtostrf(f, 4, 2, tmp);
    writeStrInBuffer(tmp);
}

/*
 * ----------------
 * Helper functions
 * ----------------
 */

char handleOnOffCommand(Command cmd)
{
    if (cmd[1] == 1)
    {
        writeStrInBuffer(ack);
        writeStrInBuffer(space);
        writeStrInBuffer(on);

        return 1;
    }
    else if (cmd[1] == 0)
    {
        writeStrInBuffer(ack);
        writeStrInBuffer(space);
        writeStrInBuffer(off);

        return 0;
    }
    else
    {
        writeStrInBuffer(error);

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
        writeStrInBuffer(error);

        return NAN;
    }
    else
    {
        value += cmd[1];

        writeStrInBuffer(ack);
        writeStrInBuffer(space);
        writeFloatInBuffer(value);

        return value;
    }

}

void handleTimingCommand(Command cmd, ScheduledTask *task)
{
    if (cmd[1] == NULL_COMMAND_KEY)
    {
        writeStrInBuffer(error);
    }
    else
    {
        setTaskRunEvery(task, cmd[1]);
        writeStrInBuffer(ack);
        writeStrInBuffer(space);
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
        writeStrInBuffer(started);
    }
    else if (getHeatingSystemState() == STOPPED_STATE)
    {
        writeStrInBuffer(stopped);
    }
    else
    {
        writeStrInBuffer(disabled);
    }
}

void handleGetDataSenderState(void)
{
    if (getDataSenderState() == ON_STATE)
    {
        writeStrInBuffer(on);
    }
    else
    {
        writeStrInBuffer(off);
    }
}

void handleGetStartingTemperature(void)
{
    writeFloatInBuffer(getStartingTemperature());
}

void handleGetStoppingTemperature(void)
{
    writeFloatInBuffer(getStoppingTemperature());
}

void handleGetLCDState(void)
{
    if (lcd.getState() == LCD_OFF)
    {
        writeStrInBuffer(off);
    }
    else
    {
        writeStrInBuffer(on);
    }
}

void handleGetCurrentTemperature(void)
{
    if (getCurrentTemperature() == UNKNOWN_TEMPERATURE)
    {
        writeStrInBuffer(unknown);
    }
    else
    {
        writeFloatInBuffer(getCurrentTemperature());
    }
}

void handleGetCurrentDensity(void)
{
    if (getCurrentDensity() == UNKNOWN_DENSITY)
    {
        writeStrInBuffer(unknown);
    }
    else
    {
        writeFloatInBuffer(getCurrentDensity());
    }
}

void handleGetCurrentScaleGram(void)
{
    writeFloatInBuffer(getScaleGram());
}

/*
 * -------------------
 * SET state functions
 * -------------------
 */

void handleSetHeatingSystemState(Command cmd)
{
    char res = handleOnOffCommand(cmd);

    if (res == 1)
    {
        enableHeatingSystem();
    }
    else if (res == 0)
    {
        disableHeatingSystem();
    }
}

void handleSetDataSenderState(Command cmd)
{
    char res = handleOnOffCommand(cmd);

    if (res == 1)
    {
        enableDataSender();
    }
    else if (res == 0)
    {
        disableDataSender();
    }
}

void handleSetStartingTemperature(Command cmd)
{
    float startingTemperature = handleFloatCommand(cmd);

    if (startingTemperature == NAN)
    {
        return;
    }

    setStartingTemperature(startingTemperature);

    if (getStoppingTemperature() < startingTemperature)
    {
        setStoppingTemperature(startingTemperature);
    }
}

void handleSetStoppingTemperature(Command cmd)
{
    float stoppingTemperature = handleFloatCommand(cmd);

    if (stoppingTemperature == NAN)
    {
        return;
    }

    setStoppingTemperature(stoppingTemperature);

    if (getStartingTemperature() > stoppingTemperature)
    {
        setStartingTemperature(stoppingTemperature);
    }
}

void handleSetLCDState(Command cmd)
{
    char res = handleOnOffCommand(cmd);

    if (res == 1)
    {
        lcd.on();
    }
    else if (res == 0)
    {
        lcd.off();
    }
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

void handleSetDensityReaderTiming(Command cmd)
{
    handleTimingCommand(cmd, &densityReaderTask);
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
            writeStrInBuffer(ack);
            break;
        case GET_HEATING_SYSTEM_STATE:
            handleGetHeatingSystemState();
            break;
        case GET_DATA_SENDER_STATE:
            handleGetDataSenderState();
            break;
        case GET_STARTING_TEMPERATURE:
            handleGetStartingTemperature();
            break;
        case GET_STOPPING_TEMPERATURE:
            handleGetStoppingTemperature();
            break;
        case GET_LCD_STATE:
            handleGetLCDState();
            break;
        case GET_CURRENT_TEMPERATURE:
            handleGetCurrentTemperature();
            break;
        case GET_CURRENT_DENSITY:
            handleGetCurrentDensity();
            break;
        case GET_CURRENT_SCALE_GRAM:
            handleGetCurrentScaleGram();
            break;

        case SET_HEATING_SYSTEM_STATE:
            handleSetHeatingSystemState(cmd);
            break;
        case SET_DATA_SENDER_STATE:
            handleSetDataSenderState(cmd);
            break;
        case SET_STARTING_TEMPERATURE:
            handleSetStartingTemperature(cmd);
            break;
        case SET_STOPPING_TEMPERATURE:
            handleSetStoppingTemperature(cmd);
            break;
        case SET_LCD_STATE:
            handleSetLCDState(cmd);
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
        case SET_DENSITY_READER_TIMING:
            handleSetDensityReaderTiming(cmd);
            break;

        case TIMEOUT_EXPIRED:
            writeStrInBuffer("TE");
            break;
        case UNRECOGNIZED_CHAR:
            writeStrInBuffer("UC");
            break;
        case NULL_COMMAND_KEY:
            writeStrInBuffer("NCK");
            break;
        default:
            writeStrInBuffer(error);
    }

    COMM_SERIAL.println(globalBuffer);

    // wait a bit to be sure that the response was read
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
