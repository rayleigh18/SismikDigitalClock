#ifndef CLOCK_H
#define CLOCK_H
#include "stateAll.h"
int sec_clock = 0;
int min_clock = 0;
int hour_clock = 0;
int day_clock = 0;

// called every 1 second
void clockHandler(){
    sec_clock++;
    if (sec_clock == 60){
        min_clock += 1;
        sec_clock = 0;
    }

    if (min_clock == 60){
        hour_clock+= 1;
        min_clock = 0;
    }

    if (hour_clock == 24){
        day_clock += 1;
        day_clock %= 31;
        day_clock += 1;
        hour_clock = 0;
    }
    
}



int sec_clock_temp = 0;
int min_clock_temp = 0;
int hour_clock_temp = 0;
int day_clock_temp = 0;
bool isClockSet = 0;
bool inClock = 0;
int stateClock = 0;

bool settingClock(){ // if set pressed
    stateClock += 1;
    if (stateClock == MIN_SET){
        num1 = &min_clock_temp;
        num2 = &sec_clock_temp;

    }
    if (stateClock > 3){
        isClockSet = 1;
        inClock = 0;

        sec_clock = sec_clock_temp;
        min_clock = min_clock_temp;
        hour_clock = hour_clock_temp;
        day_clock = day_clock_temp;

        return 1;
    }
        
    return 0;
}



void upClock(){ // if up pressed
    if (stateClock == HOUR_SET){
       hour_clock_temp += 1;
       hour_clock_temp %= 24; 
    }
    else if (stateClock == MIN_SET){
        min_clock_temp += 1;
        min_clock_temp %= 60;
    }
    else if(stateClock == SEC_SET){
        sec_clock_temp += 1;
        sec_clock_temp %= 60;
    }
    else{
        day_clock_temp += 1;
        day_clock_temp %= 31;
    }
}

void downClock(){ // if up pressed
    if (stateClock == HOUR_SET){
       hour_clock_temp -= 1;
       hour_clock_temp += 24;
       hour_clock_temp %= 24; 
    }
    else if (stateClock == MIN_SET){
        min_clock_temp -= 1;
        min_clock_temp += 60;
        min_clock_temp %= 60;
    }
    else if(stateClock == SEC_SET){
        sec_clock_temp -= 1;
        sec_clock_temp += 60;
        sec_clock_temp %= 60;
    }
    else{
        day_clock_temp -= 1;
        day_clock_temp += 31;
        day_clock_temp %=31;
    }
}

#endif