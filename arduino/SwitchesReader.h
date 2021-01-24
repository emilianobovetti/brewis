#ifndef __SWITCHES_READER_H__
#define __SWITCHES_READER_H__

#include "HeatingSystem.h"
#include "SystemState.h"
#include "DataSender.h"
#include "Global.h"
#include "LCD.h"

void initializeSwitchesReader(void);

/*
 * Check switches state and take action based on their states.
 */
void readSwitches(void);

#endif // __SWITCHES_READER_H__
