#ifndef STOPWATCHKEEP_H
#define STOPWATCHKEEP_H

#include "stateAll.h"
#include "clockHandler.h"
bool isStopwatchSet = 0;
bool inStopwatch = 0;
int stateStopwatch = HOUR_SET;
int hourStopwatch=0, minStopwatch=0, secStopwatch=0, dayStopwatch = 0;
int hourCount = 0, minCount = 0, secCount = 0;

bool settingStopwatch(){ // if set pressed
    stateStopwatch += 1;
    if (stateStopwatch == SEC_SET){
        num1 = &secStopwatch;
        num2 = &secStopwatch;
    }
    if (stateStopwatch > 3){
        isStopwatchSet = 1;
        inStopwatch = 0;

        secStopwatch += sec_clock;
        minStopwatch += ((int)secStopwatch/60)+min_clock;
        hourStopwatch += ((int)minStopwatch/24)+hour_clock;
        dayStopwatch = day_clock - 1 + ((int)hourStopwatch/24);
        dayStopwatch %= 31;
        dayStopwatch += 1;

        secStopwatch %= 60;
        minStopwatch %= 60;
        hourStopwatch %= 24;
        return 1;
    }    
    return 0;
}

void upStopwatch(){ // if up pressed
    if (stateStopwatch == HOUR_SET){
       hourStopwatch += 1;
       hourStopwatch %= 24; 
    }
    else if (stateStopwatch == MIN_SET){
        minStopwatch += 1;
        minStopwatch %= 60;
    }
    else if(stateStopwatch == SEC_SET){
        secStopwatch += 1;
        secStopwatch %= 60;
    }
}

void downStopwatch(){ // if up pressed
    if (stateStopwatch == HOUR_SET){
       hourStopwatch -= 1;
       hourStopwatch += 24;
       hourStopwatch %= 24; 
    }
    else if (stateStopwatch == MIN_SET){
        minStopwatch -= 1;
        minStopwatch += 60;
        minStopwatch %= 60;
    }
    else if(stateStopwatch == SEC_SET){
        secStopwatch -= 1;
        secStopwatch += 60;
        secStopwatch %= 60;
    }
}

#endif