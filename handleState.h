#ifndef HANDLE_STATE_H
#define HANDLE_STATE_H

#include "buttonHandler.h"
#include "stateAll.h"
#include "clockHandler.h"
#include "alarm.h"
#include "stopwatch.h"
void handleMode();
void handleSet();
void handleUp();
void handleDown();

int zero = 0;

void handleState(int state){
    if (state == MODE_EVT){
        handleMode();
    }
    else if (state == UP_EVT){
        if (isAlarmOn){
            isAlarmOn = 0;
        }
        handleUp();
    }
    else if (state == DOWN_EVT){
        handleDown();
    }
    else if (state == SET_EVT){
        handleSet();
    }
}

void handleMode(){
    if (modeNow != SETTING_TIME && modeNow != SETTING_ALARM && modeNow != SETTING_STOPWATCH){
        modeNow += 1;
    }
    else{
        if (modeNow == SETTING_TIME){
            if (stateClock == 0 || stateClock > 3){
                modeNow += 1;
            }
            else{
                return;
            }
        }
        else if (modeNow == SETTING_ALARM){
            if (stateAlarm == HOUR_SET|| stateAlarm > 3){
                modeNow += 1;
            }
            else{
                return;
            }
        }
        else if (modeNow == SETTING_STOPWATCH){
            if (stateStopwatch == HOUR_SET|| stateStopwatch > 3){
                modeNow += 1;
            }
            else{
                return;
            }
        }

    }

    modeNow %= 7;
    
    if (modeNow == MIN_SEC){
        num1 = &min_clock;
        num2 = &sec_clock;
    }
    else if (modeNow == HOUR_DATE){
        num1 = &day_clock;
        num2 = &hour_clock;
    }
    else if (modeNow == SETTING_TIME){
        stateClock = DATE_SET;
        num1 = &day_clock_temp;
        num2 = &hour_clock_temp;
    }
    else if (modeNow == SETTING_ALARM){
        stateAlarm = HOUR_SET;
        num1 = &hourAlarm;
        num2 = &minAlarm;
    }
    else if (modeNow == SETTING_STOPWATCH){
        stateStopwatch = HOUR_SET;
        num1 = &hourStopwatch;
        num2 = &minStopwatch;
    }
    else if (modeNow == SEE_STOPWATCH_HOUR){
        num1 = &hourCount;
        num2 = &minCount;
        
    }
    else if (modeNow == SEE_STOPWATCH_SEC){
        num1 = &minCount;
        num2 = &secCount;
        
    }
    
}

void handleSet(){
    if (modeNow == SETTING_TIME){
        if (settingClock()){
            handleMode();
        }
    }
    else if (modeNow == SETTING_ALARM){
        if (settingAlarm()){
            handleMode();
        }
    }
    else if (modeNow == SETTING_STOPWATCH){
        if (settingStopwatch()){
            handleMode();
        }
    }
}

void handleUp(){
    if (modeNow == SETTING_TIME){
        upClock();
    }
    else if (modeNow == SETTING_ALARM){
        upAlarm();
    }
    else if (modeNow == SETTING_STOPWATCH){
        upStopwatch();
    }
}

void handleDown(){
    if (modeNow == SETTING_TIME){
        downClock();
    }
    else if (modeNow == SETTING_ALARM){
        downAlarm();
    }
    else if (modeNow == SETTING_STOPWATCH){
        downStopwatch();
    }
}
#endif