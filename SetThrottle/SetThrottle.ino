#include <SoftwareServo.h> 
int potentiometer=A0;
int potval;
int curval;
boolean shift;
boolean shift2;

SoftwareServo ESC;

void setup() {

  pinMode(potentiometer, INPUT);
  ESC.attach(9);  
  ESC.setMinimumPulse(800);
  ESC.setMaximumPulse(2000);  
  //Serial.begin(9600);  
  curval=0;
  delay(100);
  ESC.write(0);
  shift = false;
  shift2 = false;
}

void loop() {

  potval=analogRead(potentiometer);
  potval=map(potval,827,1010,0,179);
  
  while(curval<potval){
    potval=analogRead(potentiometer);
    potval=map(potval,827,1010,0,179);
    if(curval<90){
      if(shift == false){
        curval=curval+1;
        shift = true;
      }
      else{
        if(shift2 == false){
          shift2 = true;
        }
        else{
          shift2 = false;
          shift = false;
        }
      }
    }
    else{
      curval=curval+1;
    }
    if(curval<0){
      curval=0;
    }
    
    ESC.write(curval);
    SoftwareServo::refresh();
    //Serial.println(curval);
    delay(20);}

  while(curval>potval){
    potval=analogRead(potentiometer);
    potval=map(potval,827,1010,0,179);
    curval=curval-1;
    if(curval<0){
      curval=0;
    }
    ESC.write(curval);
    SoftwareServo::refresh();
    //Serial.println(curval);
    delay(0);}
}

