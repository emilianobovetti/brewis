#ifndef __TASK_SCHEDULER_H__
#define __TASK_SCHEDULER_H__

#include <inttypes.h>
#include <stdio.h>
#include <limits.h>

#if ARDUINO >= 100
#   include <Arduino.h>
#else
#   include <WProgram.h>
#endif

/*
 * Maximum number of tasks that can be scheduled with
 * 'scheduleTask' function.
 */
#define TASKS_INDEX_CAPACITY 15

/*
 * If setted to 1 TaskScheduler will produce warnings
 * on 'Serial' when tasks overflow.
 * Default is 0.
 */
#define WARNING_ENABLED 0

typedef unsigned long time_t;

/*
 * --------------------
 * Task data structures
 * --------------------
 */
enum TaskState { NOT_RUNNING, RUNNING };

typedef void (*Runnable)(void);

typedef struct
{
    time_t lastRun;

    time_t runEvery;

    enum TaskState state;

    Runnable runnableTask;

} ScheduledTask;

/*
 * ---------------------
 * Task execution system
 * ---------------------
 */

/*
 * Checks if a task has to run.
 * If it has to do, 'checkTask' will run it
 * and update its lastRun field.
 */
void checkTask(ScheduledTask *task);

/*
 * Runs all scheduled tasks that have to run.
 */
void runScheduledTasks(void);

/* Returns the shortest time after a task has
 * to run again.
 */
time_t timeToWait(void);

/*
 * ----------------
 * Tasks scheduling
 * ----------------
 */

/*
 * Schedules a task adding it to 'tasksIndex' and
 * incrementing 'taskCounter'.
 *
 * If 'tasksIndex' is full, 'scheduleTask' does not
 * schedule the given task.
 * WARNING: In this case the task won't run!
 *
 * If WARNING_ENABLED is set to 1 will send a warning
 * message on 'Serial'.
 */
void scheduleTask(ScheduledTask *task);

/*
 * ------------
 * Task setters
 * ------------
 */

/*
 * Sets the state of task.
 * E.g. setTaskState(task, RUNNING); setTaskState(task, NOT_RUNNING);
 */
void setTaskState(ScheduledTask *task, enum TaskState state);

/*
 * Sets task's 'runEvery'.
 */
void setTaskRunEvery(ScheduledTask *task, time_t runEvery);

/*
 * ----------------
 * Task declaration
 * ----------------
 */
#define DECLARE_RUNNABLE_TASK(RUNNABLE_TASK)                \
    void RUNNABLE_TASK(void)

#define DECLARE_TASK(TASK_NAME)                             \
    extern ScheduledTask TASK_NAME

#define DEFINE_TASK(TASK_NAME, RUNNABLE_TASK, EVERY_MILLIS) \
    ScheduledTask TASK_NAME = {                             \
        .lastRun = 0,                                       \
        .runEvery = EVERY_MILLIS,                           \
        .state = RUNNING,                                   \
        .runnableTask = RUNNABLE_TASK                       \
    }

/*
 * Given the task name, the name of a callback function with type
 * 'void function(void)' and how often the task has to run,
 * defines a new task with given parameters and declares
 * the signature of the callback function.
 */
#define NEW_TASK(TASK_NAME, RUNNABLE_TASK, EVERY_MILLIS)    \
    DECLARE_RUNNABLE_TASK(RUNNABLE_TASK);                   \
    DEFINE_TASK(TASK_NAME, RUNNABLE_TASK, EVERY_MILLIS)

#endif // __TASK_SCHEDULER_H__
