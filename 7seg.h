
#ifdef COMMON_ANODE
  #define SEG_ON 0
  #define DIG_ON 1
#else
  #define SEG_ON 1
  #define DIG_ON 0
#endif

#include <TimerOne.h>
bool getDigitVal(bool value){
  return !(value^DIG_ON);
}

bool getSegmentVal(bool value){
  return !(value^SEG_ON);
}
int pin_7Seg[8] = {3,6,12,10,9,4,13,11}; // 7 segment pin

#define TOTAL_DIGIT 4
int pin_Digit[TOTAL_DIGIT] = {2,7,8,A2}; // digit pin

int num_array[10][7] = {  { 1,1,1,1,1,1,0 },    // 0
                          { 0,1,1,0,0,0,0 },    // 1
                          { 1,1,0,1,1,0,1 },    // 2
                          { 1,1,1,1,0,0,1 },    // 3
                          { 0,1,1,0,0,1,1 },    // 4
                          { 1,0,1,1,0,1,1 },    // 5
                          { 1,0,1,1,1,1,1 },    // 6
                          { 1,1,1,0,0,0,0 },    // 7
                          { 1,1,1,1,1,1,1 },    // 8
                          { 1,1,1,1,0,1,1 }};   // 9


void setupPin7Seg(){
  for (int i = 0; i < 8; i++){ // initiate 7 seg
    pinMode(pin_7Seg[i], OUTPUT);
    digitalWrite(pin_7Seg[i], getSegmentVal(0));
  }
  for (int i = 0; i <TOTAL_DIGIT; i++){ // initiate digit
    pinMode(pin_Digit[i], OUTPUT);
    digitalWrite(pin_Digit[i], getDigitVal(0));
  }
}
void setDigit(int pinSeg, int numValue){
  for (int i = 0; i < TOTAL_DIGIT; i++){
    digitalWrite(pin_Digit[i], getDigitVal(pin_Digit[i]==pinSeg));
  }

  for (int i = 0; i < 7; i++){
    digitalWrite(pin_7Seg[i], getSegmentVal(num_array[numValue][i]));
  }

  delay(1);
  for (int i = 0; i < TOTAL_DIGIT; i++){
    digitalWrite(pin_Digit[i], getDigitVal(0));
  }
}

void onAllDigit(int num1, int num2, int num3, int num4){
  num1 = num1%10;
  num2 = num2%10;
  num3 = num3%10;
  num4 = num4%10;

  setDigit(pin_Digit[0], num1);
  setDigit(pin_Digit[1], num2);
  setDigit(pin_Digit[2], num3);
  setDigit(pin_Digit[3], num4);  
}




