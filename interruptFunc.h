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

    num1 = &day_clock;
    num2 = &hour_clock;
}

ISR(TIMER1_COMPA_vect){
    clockHandler();
    if (hourAlarm = hour_clock && minAlarm == min_clock && secAlarm == sec_clock){
        isAlarmOn = 1;
    }
    else if (hourStopwatch = hour_clock && minStopwatch == min_clock && secStopwatch == sec_clock){
        isAlarmOn = 1;
    }
    
}

#endif