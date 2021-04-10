#ifndef BUTTON_HANDLER_H
#define BUTTON_HANDLER_H
#include "pinConfiguration.h"

#define DEBOUNCE_PERIOD 5 // 5*20ms = 100ms
#define SHORT_PERIOD 25 // 25*20ms = 500ms
#define LONG_PERIOD 250 // 250*20ms = 5s

#define SET_EVT 0
#define MODE_EVT 1
#define UP_EVT 2
#define DOWN_EVT 3
#define UNDEFINED_EVT 4

#define ZERO 0
#define SHORT 1
#define LONG 2
#define UNDEFINED 3

bool buttonA;
bool buttonB;

unsigned int stateA = 0, stateB = 0;

unsigned int countA = 0, countB = 0;



int buttonHandler(){
    buttonA = digitalRead(PIN_BUTTON_A);
    buttonB = digitalRead(PIN_BUTTON_B);

    //  handle button a
    if (buttonA == 0){
        if (countA <DEBOUNCE_PERIOD){
            stateA = ZERO;
        }
        else if (countA < SHORT_PERIOD){
            stateA = SHORT;
        }
        else if (countA < LONG_PERIOD){
            stateA = LONG;
        }
    }
    else{
        countA += 1;
        countA = countA % LONG_PERIOD;
        stateA = UNDEFINED;
    }

    // handle button b
    if (buttonB == 0){
        if (countB <DEBOUNCE_PERIOD){
            stateB = ZERO;
        }
        else if (countB < SHORT_PERIOD){
            stateB = SHORT;
        }
        else if (countB < LONG_PERIOD){
            stateB = LONG;
        }
    }
    else{
        countB += 1;
        countB = countB % LONG_PERIOD;
        stateB = UNDEFINED;
    }

    if (stateA == UNDEFINED || stateB == UNDEFINED || (stateA == ZERO && stateB == ZERO)){
        return UNDEFINED_EVT;
    }
    else if (stateA ==  SHORT && stateB == ZERO){
        return DOWN_EVT;
    }
    else if (stateA == ZERO && stateB == SHORT){
        return UP_EVT;
    }
    else if (stateA == SHORT && stateB == SHORT){
        return MODE_EVT;
    }
    else if (stateA == LONG && stateB == LONG){
        return MODE_EVT;
    }
    else if (stateA == LONG){
        return SET_EVT;
    }
    else if (stateB == LONG){
        return MODE_EVT;
    }
}


#endif