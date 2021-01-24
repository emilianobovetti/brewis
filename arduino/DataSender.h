#ifndef __DATA_SENDER_H__
#define __DATA_SENDER_H__

#include "DataReceiver.h"
#include "SystemState.h"
#include "Global.h"
#include "Helper.h"

/*
 * ---------------------
 * System initialization
 * ---------------------
 */

void initializeDataSender(void);

/*
 * ---------------------
 * System state modifier
 * ---------------------
 */

void enableDataSender(void);

void disableDataSender(void);

/*
 * Sends the measurements through COMM_SERIAL
 * as keyed comma-separated values.
 *
 * E.g.
 *  temp=19.2,dens=1020.5
 */
void sendData(void);

#endif // __DATA_SENDER_H__
