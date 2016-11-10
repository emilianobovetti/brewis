#include "DataReceiver.h"

static Command cmd;

void initializeDataReceiver(void)
{
    initializeSerial();

    flushCommand(cmd);
}

inline bool timeoutExpired(time_t noDataSince)
{
    return noDataSince > 0 && millis() - noDataSince > DATA_RECEIVER_TIMEOUT;
}

void readInputData(void)
{
    // there aren't bytes to read
    if (COMM_SERIAL.available() == 0)
    {
        return;
    }

    char input;
    time_t noDataSince = 0;
    uint8_t cmdIndex = 0;

    while (true)
    {
        input = COMM_SERIAL.read();

        if (input == NO_DATA_AVAILABLE)
        {
            if (noDataSince == 0) noDataSince = millis();
        }
        else if (input == COMMAND_FIELD_SEPARATOR)
        {
            cmdIndex++;
            noDataSince = 0;
            continue;
        }
        else if (input >= '0' && input <= '9')
        {
            if (cmd[cmdIndex] == NULL_COMMAND_KEY)
            {
                cmd[cmdIndex] = 0;
            }

            //                                    char to int
            cmd[cmdIndex] = cmd[cmdIndex] * 10 + (input - '0');
            noDataSince = 0;
            continue;
        }
        else if (input == COMMAND_TERMINATOR)
        {
            break;
        }
        else
        {
            cmd[0] = UNRECOGNIZED_CHAR;
            break;
        }

        if (timeoutExpired(noDataSince))
        {
            cmd[0] = TIMEOUT_EXPIRED;
            break;
        }
    }

    runCommand(cmd);
    flushCommand(cmd);

    // if there are bytes to read, process immediatly
    if (COMM_SERIAL.available() > 0)
    {
        readInputData();
    }
}
