#ifndef __LCD_REFRESHER_H__
#define __LCD_REFRESHER_H__

#include "LiquidCrystalImproved.h"
#include "SystemState.h"
#include "Parameters.h"
#include "Global.h"

/*
 * ---------------------
 * System initialization
 * ---------------------
 */

void initializeLCDRefresher(void);

/*
 * ---------------------
 * System state modifier
 * ---------------------
 */

void enableLCDRefresher(void);

void disableLCDRefresher(void);

/*
 * -------------
 * Task callback
 * -------------
 */

void refreshLCD(void);

#endif // __LCD_REFRESHER_H__
