#include "SevSeg.h"
#include <Keypad.h>

SevSeg sevseg; //Instantiate a seven segment controller object

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] =  {
   {'1','2','3','A'},
   {'4','5','6','B'},
   {'7','8','9','C'},
   {'*','0','#','D'}
};


byte colPins[COLS] = {A4,A5,A6,A7};
byte rowPins[ROWS] = {A0,A1,A2,A3};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);


float Num1,Num2,Number;
char key,action;
boolean result = false;

void setup(){
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_CATHODE; // See README.md for options
  bool updateWithDelays = false; // Default. Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros);
  sevseg.setBrightness(90);
  
  Serial.begin(9600);
}

void loop(){


//  if (key!=NO_KEY)
  DetectButtons(); 

  if (result==true){
    CalculateResult();
  }
  
  
  DisplayResult();



  sevseg.refreshDisplay();
}



void DetectButtons(){

char key = keypad.getKey();

if (key=='*'){ //If cancel Button is pressed
    Serial.println ("Button Cancel");
    sevseg.blank();
    Number=Num1=Num2=0;
    result=false;
    }

if (key == '#')
    {Serial.println ("Button Equal");
    sevseg.setChars("eq"); 
    Num2=Number;
    result = true;
    }
  if(key == '1'){
    if (Number==0){
    Number=1;
    }
    else {
    Number = (Number*10) + 1; //Pressed twice
    }
    Serial.println(Number);
    sevseg.setNumber(Number);
  } 
if(key == '2'){
    if (Number==0){
    Number = 2;
    }
    else {
    Number = (Number*10) + 2; //Pressed twice
    }
    Serial.println(Number);
    sevseg.setNumber(Number);
  }
if(key == '3'){
    if (Number==0){
    Number = 3;
    }
    else {
    Number = (Number*10) + 3; //Pressed twice
    }
    Serial.println(Number);
    sevseg.setNumber(Number);
  }
if(key == '4'){
    if (Number==0){
    Number = 4;
    }
    else {
    Number = (Number*10) + 4; //Pressed twice
    }
    Serial.println(Number);
    sevseg.setNumber(Number);
  }
if(key == '5'){
    if (Number==0){
    Number = 5;
    }
    else {
    Number = (Number*10) + 5; //Pressed twice
    }
    Serial.println(Number);
    sevseg.setNumber(Number);
  }
if(key == '6'){
    if (Number==0){
    Number = 6;
    }
    else {
    Number = (Number*10) + 6; //Pressed twice
    }
    Serial.println(Number);
    sevseg.setNumber(Number);
  }
if(key == '7'){
    if (Number==0){
    Number = 7;
    }
    else {
    Number = (Number*10) + 7; //Pressed twice
    }
    Serial.println(Number);
    sevseg.setNumber(Number);
  }
if(key == '8'){
    if (Number==0){
    Number = 8;
    }
    else {
    Number = (Number*10) + 8; //Pressed twice
    }
    Serial.println(Number);
    sevseg.setNumber(Number);
  }
if(key == '9'){
    if (Number==0){
    Number = 9;
    }
    else {
    Number = (Number*10) + 9; //Pressed twice
    }
    Serial.println(Number);
    sevseg.setNumber(Number);
  }
if(key == '0'){
    if (Number==0){
    Number = 0;
    }
    else {
    Number = (Number*10) + 0; //Pressed twice
    }
    Serial.println(Number);
    sevseg.setNumber(Number);
  }
  
if (key == 'A' || key == 'B' || key == 'C' || key == 'D') //Detecting Buttons on Column 4
  {
    Num1 = Number;    
    Number =0;
    if (key == 'A'){
      Serial.println ("Addition");
      sevseg.setChars("plus");
      action = '+';
      }
    if (key == 'B'){
      Serial.println ("Subtraction");
      sevseg.setChars("kura");
      action = '-'; 
      }
     if (key == 'C')
    {
      Serial.println ("Multiplication"); 
      sevseg.setChars("kali");
      action = '*';}
     if (key == 'D')
    {Serial.println ("Division");
    sevseg.setChars("ba9i");
    action = '/';
    }  
    delay(100);
  }


}



void CalculateResult()
{
  if (action=='+')
    Number = Num1+Num2;

  if (action=='-')
    Number = Num1-Num2;

  if (action=='*')
    Number = Num1*Num2;

  if (action=='/')
    Number = Num1/Num2; 
}


void DisplayResult()
{  
  if (result==true){
    sevseg.setNumber(Number, 1);
  }
}
