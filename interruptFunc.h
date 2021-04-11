#ifndef INNT_H
#define INNT_H

#include "stateAll.h"
#include "clockHandler.h"
#include "alarm.h"
#include "stopwatch.h"
void setupTimerButton(){
    cli();
    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1  = 0;
    // set compare match register for 1hz increments
    OCR1A = 15624;
    // turn on CTC mode
    TCCR1B |= (1 << WGM12);
    TCCR1B |= (1 << CS12) | (1 << CS10);  // 1024 
    TIMSK1 |= (1 << OCIE1A);
    sei();

    // for first time, initiaote
    num1 = &day_clock;
    num2 = &hour_clock;
}

ISR(TIMER1_COMPA_vect){
    clockHandler();
    if (hourAlarm == hour_clock && minAlarm == min_clock && secAlarm == sec_clock && isAlarmSet){
        isAlarmOn = 1;
    }
    else if (dayStopwatch == day_clock && hourStopwatch == hour_clock && minStopwatch == min_clock && secStopwatch == sec_clock && isStopwatchSet){
        isAlarmOn = 1;
        isStopwatchSet = 0;
    }
    if (isStopwatchSet){
        if (dayStopwatch != day_clock){
            hourCount = 24 + hourStopwatch - hour_clock;
        }
        else hourCount = hourStopwatch - hour_clock;

        if (minStopwatch < min_clock){
            hourCount -= 1;
            minCount = 60 + minStopwatch - min_clock;
        }
        else {
            minCount = minStopwatch - min_clock;
        }

        if (secStopwatch < sec_clock){
            if (minCount == 0){
                minCount = 59;
                hourCount -= 1;
            }
            secCount = 60 + secStopwatch - sec_clock;
        }
        else {
            secCount = secStopwatch - sec_clock;
        }
    }else{
        hourCount = 0;
        minCount = 0;
        secCount = 0;
    }

    
}

#endif