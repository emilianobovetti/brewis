#include "DataSender.h"

void initializeDataSender(void)
{
    initializeSerial();

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

void sendData(void)
{
    emptyGlobalBuffer();
    strcat(globalBuffer, "temp=");

    char tmp[8];

    if (getCurrentTemperature() == UNKNOWN_TEMPERATURE)
    {
        strcat(globalBuffer, unknown);
    }
    else
    {
        dtostrf(getCurrentTemperature(), 4, 2, tmp);
        strcat(globalBuffer, tmp);
    }

    //////////////////////////
    // TODO: density reader //
    //////////////////////////
    /*
    strcat(globalBuffer, ",dens=");
    if (getCurrentDensity() == UNKNOWN_DENSITY)
    {
        strcat(globalBuffer, unknown);
    }
    else
    {
        dtostrf(getCurrentDensity(), 4, 2, tmp);
        strcat(globalBuffer, tmp);
    }
    */
    //////////////////////////
    //       end TODO       //
    //////////////////////////

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
