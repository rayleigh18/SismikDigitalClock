#ifndef HANDLE_STATE_H
#define HANDLE_STATE_H

#include "buttonHandler.h"
#include "stateAll.h"

void handleState(int state){
    if (state == MODE_EVT){
        Serial.println("M");
    }
    else if (state == UP_EVT){
        Serial.println("U");
    }
    else if (state == DOWN_EVT){
        Serial.println("D");
    }
    else if (state == SET_EVT){
        Serial.println("S");
    }
}
int modeNow = MIN_SEC;
void handleMode(){
    
}
#endif