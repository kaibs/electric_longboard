#include <SoftwareServo.h> 
int potentiometer=A0;
int potval;
int curval;
boolean shift;



SoftwareServo ESC;

void setup() {

 
  pinMode(potentiometer, INPUT);
  ESC.attach(9);  
  ESC.setMinimumPulse(800);
  ESC.setMaximumPulse(2000);  
  Serial.begin(9600);  
  curval=0;
  delay(100);
  ESC.write(0);
  shift = false;
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
        shift = false;
      }
    }
    else{
      curval=curval+1;
    }
    if(curval<0-){
      curval=0;
    }
    
    ESC.write(curval);
    //ESC.write(potval);
    SoftwareServo::refresh();
    Serial.println(curval);
    //Serial.println(potval);
    delay(20);}

  while(curval>potval){
    potval=analogRead(potentiometer);
    potval=map(potval,827,1010,0,179);
    curval=curval-1;
    if(curval<0){
      curval=0;
    }
    ESC.write(curval);
    //ESC.write(potval);
    SoftwareServo::refresh();
    Serial.println(curval);
    //Serial.println(potval);
    delay(0);}

    //ESC.write(curval);
    //ESC.write(potval);
    //SoftwareServo::refresh();
    //Serial.println(curval);
    //Serial.println(potval);
}

