#ifndef AlarmKEEP_H
#define AlarmKEEP_H

#include "stateAll.h"
#include "clockHandler.h"
bool isAlarmSet = 0;
bool inAlarm = 0;
int stateAlarm = 99;
int hourAlarm=0, minAlarm=0, secAlarm=0, dayAlarm = 0;

bool settingAlarm(){ // if set pressed
    if (inAlarm == 0){
        inAlarm = 1;
        stateAlarm = NONE_SET;
        hourAlarm = 0;
        minAlarm = 0;
        secAlarm = 0;
    }
    stateAlarm += 1;
    if (stateAlarm > 3){
        isAlarmSet = 1;
        inAlarm = 0;

        return 1;
    }    
    return 0;
}

void upAlarm(){ // if up pressed
    if (stateAlarm == HOUR_SET){
       hourAlarm += 1;
       hourAlarm %= 24; 
    }
    else if (stateAlarm == MIN_SET){
        minAlarm += 1;
        minAlarm %= 60;
    }
    else if(stateAlarm == SEC_SET){
        secAlarm += 1;
        secAlarm %= 60;
    }
}

void downAlarm(){ // if up pressed
    if (stateAlarm == HOUR_SET){
       hourAlarm -= 1;
       hourAlarm %= 24; 
    }
    else if (stateAlarm == MIN_SET){
        minAlarm -= 1;
        minAlarm %= 60;
    }
    else if(stateAlarm == SEC_SET){
        secAlarm -= 1;
        secAlarm %= 60;
    }
}
#endif