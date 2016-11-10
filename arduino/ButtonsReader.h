#ifndef __BUTTONS_READER_H__
#define __BUTTONS_READER_H__

#include "LiquidCrystalImproved.h"
#include "HeatingSystem.h"
#include "LCDRefresher.h"
#include "SystemState.h"
#include "DataSender.h"
#include "Global.h"
/*
 * Check buttons state and take action if one
 * is pressed.
 */
void readButtons(void);

#endif // __BUTTONS_READER_H__
