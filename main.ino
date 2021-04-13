#include "pinConfiguration.h"
#include "clockHandler.h"
#include "buttonHandler.h"
#include "handleState.h"
#include "7seg.h"
#include "interruptFunc.h"
unsigned long timeButt = 0;
unsigned long timePrint = 0;
unsigned long time7Seg = 0;
unsigned long timeAlarm = 0;

int stateButton = UNDEFINED;
bool stateLampuAlarm = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN_BUTTON_A, INPUT);
  pinMode(PIN_BUTTON_B, INPUT);
  pinMode(PIN_ALARM, OUTPUT);
  setupPin7Seg();

  setupTimerButton();
  
  // for first time, initiaote
  num1 = &day_clock;
  num2 = &hour_clock;
}

void loop() {
  // put your main code here, to run repeatedly:
  // check button
  if (millis() - timeButt > 20){
    stateButton = buttonHandler();
    handleState(stateButton);
    timeButt = millis();
  }
  // for 7 segmen
  if (millis()- time7Seg > 16){
    onAllDigit(*num1/10,*num1%10,*num2/10,*num2%10);
    time7Seg = millis();
  }
  // for alarm on
  if (isAlarmOn){
    if(millis()-timeAlarm > 500){
      digitalWrite(A4, stateLampuAlarm);
      stateLampuAlarm = !stateLampuAlarm;
      timeAlarm = millis();
    }
  }
  // debugging
  if (millis() - timePrint > 500){
    Serial.println(modeNow);
    Serial.print(hourStopwatch);
    Serial.print(minStopwatch);
    Serial.println(secStopwatch);
    timePrint = millis();
  }
  
}
