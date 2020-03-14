#include <Servo.h> 
int potentiometer=A0;
int potval;
int curval;



Servo ESC;

void setup() {

 
  //pinMode(potentiometer, INPUT);
  ESC.attach(9);  
  //ESC.setMinimumPulse(800);
 // ESC.setMaximumPulse(2000);  
  Serial.begin(9600);  
  curval=0;
  delay(100);
  ESC.write(0);
}

void loop() {

  potval=analogRead(potentiometer);
  potval=map(potval,827,1010,0,2000);
  
  while(curval<potval){
    potval=analogRead(potentiometer);
    potval=map(potval,827,1015,0,2000);
    curval=curval+2;
    ESC.write(curval);
    //SoftwareServo::refresh();
    Serial.println(curval);
    delay(0);}

  while(curval>potval){
    potval=analogRead(potentiometer);
    potval=map(potval,827,1010,0,2000);
    curval=curval-2;
    ESC.write(curval);
    //SoftwareServo::refresh();
    Serial.println(curval);
    delay(0);}

    ESC.write(curval);
    //SoftwareServo::refresh();
    Serial.println(curval);
}

