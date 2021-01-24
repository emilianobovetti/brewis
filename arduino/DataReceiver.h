#ifndef __DATA_RECEIVER_H__
#define __DATA_RECEIVER_H__

#include <SoftwareSerial.h>
#include "Global.h"
#include "Command.h"
#include "Helper.h"
#include "Const.h"

#define NO_DATA_AVAILABLE -1

/*
 * ---------------------
 * System initialization
 * ---------------------
 */

void initializeDataReceiver(void);

/*
 * Check the COMM_SERIAL for input data,
 * reads the data and builds a Command,
 * then executes it.
 *
 * If doesn't receive the COMMAND_TERMINATOR character
 * waits for DATA_RECEIVER_TIMEOUT, then sets the command key
 * to TIMEOUT_EXPIRED and executes it.
 *
 * If finds an unkown character, sets the command key to
 * UNRECOGNIZED_CHAR and executes it.
 */
void readInputData(void);

#endif // __DATA_RECEIVER_H__
