#ifndef STATE_ALL_H
#define STATE_ALL_H

// for mode evt
#define MIN_SEC 1
#define HOUR_DATE 0
#define SETTING_TIME 2
#define SETTING_ALARM 3
#define SETTING_STOPWATCH 4
#define SEE_STOPWATCH_HOUR 5
#define SEE_STOPWATCH_SEC 6

// for set evt
#define DATE_SET 0
#define HOUR_SET 1
#define MIN_SET 2
#define SEC_SET 3
#define NONE_SET 99

bool isAlarmOn = 0;
int modeNow = HOUR_DATE;
unsigned int * num1;
unsigned int * num2;

#endif