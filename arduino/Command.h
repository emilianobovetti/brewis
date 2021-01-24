#ifndef __COMMAND_H__
#define __COMMAND_H__

#include <Arduino.h>
#include <TaskScheduler.h>
#include "HeatingSystem.h"
#include "SystemState.h"
#include "DataSender.h"
#include "Global.h"
#include "Helper.h"
#include "Const.h"

/*
 * A command consists in a string of positive integers
 * separated by COMMAND_FIELD_SEPARATOR character
 * and ending with COMMAND_TERMINATOR.
 *
 * The first value is the command key and specifies
 * the command to run.
 *
 * Following values (optionals) are the command's
 * parameters.
 */

/*
 * ------------
 * Command keys
 * ------------
 *
 * All the values that a command key may take.
 *
 * Negative ones are control keys.
 */
enum CommandKey
{
    TIMEOUT_EXPIRED               = -3,
    UNRECOGNIZED_CHAR             = -2,
    NULL_COMMAND_KEY              = -1,

    GET_ACK                       = 0,

    GET_HEATING_SYSTEM_STATE      = 1,
    GET_DATA_SENDER_STATE         = 2,
    GET_TARGET_TEMPERATURE        = 3,
    GET_DELTA_TEMPERATURE         = 4,
    GET_LCD_STATE                 = 5,
    GET_CURRENT_TEMPERATURE       = 6,

    SET_HEATING_SYSTEM_STATE      = 11,
    SET_DATA_SENDER_STATE         = 12,
    SET_TARGET_TEMPERATURE        = 13,
    SET_DELTA_TEMPERATURE         = 14,
    SET_LCD_STATE                 = 15,

    SET_HEATING_SYSTEM_TIMING     = 21,
    SET_DATA_SENDER_TIMING        = 22,
    SET_LCD_REFRESHER_TIMING      = 25,
    SET_TEMPERATURE_READER_TIMING = 26
};

/*
 * ----------------
 * Command settings
 * ----------------
 */
#define COMMAND_FIELD_SEPARATOR ','
#define COMMAND_TERMINATOR '\r'

/*
 * Maximum number of parameters.
 */
#define PARAMETERS_LENGTH 2
#define COMMAND_ARRAY_LENGTH PARAMETERS_LENGTH + 1

typedef int Command[COMMAND_ARRAY_LENGTH];

/*
 * Given a Command, executes it, send to
 * COMM_SERIAL a response, then sleep
 * for a while to be sure that the response
 * was received.
 */
void runCommand(Command cmd);

void flushCommand(Command cmd);

#endif // __COMMAND_H__
