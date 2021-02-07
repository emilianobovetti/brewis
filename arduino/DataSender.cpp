#include "DataSender.h"

void initializeDataSender(void)
{
    disableDataSender();
}

void enableDataSender(void)
{
    setTaskState(&dataSenderTask, RUNNING);
    setDataSenderState(ON_STATE);
}

void disableDataSender(void)
{
    setTaskState(&dataSenderTask, NOT_RUNNING);
    setDataSenderState(OFF_STATE);
}

void writeTempInGlobalBuffer(char *label, TEMPERATURE_TYPE temp)
{
    strcat(globalBuffer, label);

    if (temp == UNKNOWN_TEMPERATURE)
    {
        strcat(globalBuffer, unknown);
    }
    else
    {
        char tmp[8];

        dtostrf(temp, 4, 2, tmp);
        strcat(globalBuffer, tmp);
    }
}

void sendData(void)
{
    emptyGlobalBuffer();

    writeStringInGlobalBuffer("temp0=");
    writeTemperatureInGlobalBuffer(getBrewingTemperature());
    writeStringInGlobalBuffer(",temp1=");
    writeTemperatureInGlobalBuffer(getRoomTemperature());

    // if there are bytes to read, process the input
    // before send data
    if (COMM_SERIAL.available() > 0)
    {
        readInputData();

        // response sent after command execution
        // emptied the global buffer, so we can't
        // send buffered data
        return;
    }

    COMM_SERIAL.println(globalBuffer);
}
