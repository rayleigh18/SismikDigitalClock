#include "pinConfiguration.h"
#include "clockHandler.h"
#include "buttonHandler.h"
#include "handleState.h"
#include "7seg.h"
unsigned long timeButt = 0;
unsigned long timePrint = 0;

int stateButton = UNDEFINED;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN_BUTTON_A, INPUT);
  pinMode(PIN_BUTTON_B, INPUT);
  setupPin7Seg();

  setupTimerButton();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - timeButt > 20){
    stateButton = buttonHandler();
    handleState(stateButton);
    timeButt = millis();
  }
  onAllDigit(1,2,3,4);
}
