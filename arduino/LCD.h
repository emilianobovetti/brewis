#ifndef __LCD_H__
#define __LCD_H__

#include <LiquidCrystal.h>
#include "SystemState.h"
#include "Tasks.h"

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

void enableLCD(void);

void disableLCD(void);

/*
 * -------------
 * Task callback
 * -------------
 */

void refreshLCD(void);

#endif // __LCD_H__
