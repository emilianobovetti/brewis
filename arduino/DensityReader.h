#ifndef __DENSITY_READER_H__
#define __DENSITY_READER_H__

#include <Hx711.h>
#include "SystemState.h"
#include "Parameters.h"
#include "Global.h"

/*
 * ---------------------
 * System initialization
 * ---------------------
 */

void initializeDensityReader(void);

/*
 * ---------------------
 * System state modifier
 * ---------------------
 */

void enableDensityReader(void);

void disableDensityReader(void);

/*
 * Reads the wort gravity.
 *
 * Attention:
 *  At the time the density reader system does not work.
 *                                        -------------
 */
void readDensity(void);

/*
 * ---------------
 * Helper function
 * ---------------
 */

float getScaleGram(void);

#endif // __DENSITY_READER_H__
