#ifndef __HELPER_H__
#define __HELPER_H__

#include <Arduino.h>
#include "Parameters.h"
#include "Global.h"

void initializeSerial(void);

void emptyString(char *str, uint8_t dim);

void emptyGlobalBuffer(void);

#endif // __HELPER_H__