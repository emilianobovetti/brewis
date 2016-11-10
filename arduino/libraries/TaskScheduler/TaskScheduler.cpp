#include "TaskScheduler.h"

/*
 * ------------------------------
 * TaskScheduler global variables
 * ------------------------------
 */

static uint8_t taskCounter = 0;

static ScheduledTask *tasksIndex[TASKS_INDEX_CAPACITY];

/*
 * ---------------------
 * Task execution system
 * ---------------------
 */

/*
 * Returns 'true' if is the task's first run or its time
 * is exiperd.
 */
inline boolean timeExpired(ScheduledTask *task)
{
    time_t n = millis();
    //            time expired                   OR           is the first run
    return (task->runEvery <= n - task->lastRun) || (n < task->runEvery && task->lastRun == 0);
}

/*
 * Returns 'true' if a task is on RUNNING state
 * and its time is expired.
 */
inline boolean haveToRun(ScheduledTask *task)
{
    return task->state == RUNNING && timeExpired(task);
}

/*
 * See TaskScheduler.h
 */
void checkTask(ScheduledTask *task)
{
    if (haveToRun(task))
    {
        task->runnableTask();
        task->lastRun = millis();
    }
}

/*
 * See TaskScheduler.h
 */
void runScheduledTasks(void)
{
    uint8_t i;
    for (i = 0; i < taskCounter; i++)
    {
        checkTask(tasksIndex[i]);
    }
}

/*
 * See TaskScheduler.h
 */
time_t timeToWait(void)
{
    time_t timeToWait = ULONG_MAX;
    time_t n = millis();
    uint8_t i;

    for (i = 0; i < taskCounter; i++)
    {
        // ignore tasks that doesn't have to run
        if (tasksIndex[i]->state == NOT_RUNNING)
        {
            continue;
        }

        // when this task have to run again
        time_t nextRun = tasksIndex[i]->lastRun + tasksIndex[i]->runEvery;

        // this task should have already run
        if (nextRun < n)
        {
            timeToWait = 0;
            break;
        }
        else
        {
            nextRun -= n; // how much time to the next execution of this task

            // timeToWait = MIN(timeToWait, nextRun - n)
            timeToWait = (timeToWait < nextRun) ? timeToWait : nextRun;
        }
    }

    return timeToWait;
}

/*
 * ----------------
 * Tasks scheduling
 * ----------------
 */

/*
 * See TaskScheduler.h
 */
void scheduleTask(ScheduledTask *task)
{
    /*
     * TaskScheduler went out of memory!
     * TASKS_INDEX_CAPACITY should be increased.
     */
    if (taskCounter >= TASKS_INDEX_CAPACITY)
    {
        #if defined WARNING_ENABLED && WARNING_ENABLED
          Serial.println("WARNING: task scheduler went out of memory");
        #endif // WARNING_ENABLED

        return; // task won't be added to index.
    }

    tasksIndex[taskCounter] = task;
    taskCounter++;
}

/*
 * ------------
 * Task setters
 * ------------
 */

void setTaskState(ScheduledTask *task, enum TaskState state)
{
    task->state = state;
}

void setTaskRunEvery(ScheduledTask *task, time_t runEvery)
{
    task->runEvery = runEvery;
}
