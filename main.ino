#include "pinConfiguration.h"
#include "clockHandler.h"
#include "buttonHandler.h"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN_BUTTON_A, INPUT);
  pinMode(PIN_BUTTON_B, INPUT);

  setupTimerButton();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(sec_clock);
  Serial.print(' ');
  Serial.print(min_clock);
  Serial.println();
  delay(1000);
}
