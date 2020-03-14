#include "ManchesterRF.h" //https://github.com/cano64/ManchesterRF

#define TX_PIN 9 //any pin can transmit

int potentiometer=A0;
int potval;
int curval;
boolean shift;
uint8_t data = 0;

ManchesterRF rf(MAN_4800); //link speed, try also MAN_300, MAN_600, MAN_1200, MAN_2400, MAN_4800, MAN_9600, MAN_19200, MAN_38400

void setup() {

  Serial.begin(9600);
  pinMode(potentiometer, INPUT);
  rf.TXInit(TX_PIN);
  curval=0;
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
    if(curval<0){
      curval=0;
    }
    
  data = (byte)curval;
  rf.transmitByte(data);
  Serial.println(data);
  delay(30);
  }

  while(curval>potval){
    potval=analogRead(potentiometer);
    potval=map(potval,827,1010,0,179);
    curval=curval-2;
    if(curval<0){
      curval=0;
    }
  
  data = (uint8_t)curval;
  rf.transmitByte(data);
  Serial.println(String(data));
  delay(30);
  }
}


