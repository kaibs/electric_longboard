#include "ManchesterRF.h" //https://github.com/cano64/ManchesterRF
#include <SoftwareServo.h>


#define RX_PIN 2 //any pin can receive
//#define LED_PIN 13

SoftwareServo ESC;

ManchesterRF rf(MAN_4800); //link speed, try also MAN_300, MAN_600, MAN_1200, MAN_2400, MAN_4800, MAN_9600, MAN_19200, MAN_38400

uint8_t data;
unsigned long timer = 0;
unsigned long timer2 = 0;
unsigned long timediff = 0;
int rpm;


void setup() {
  //pinMode(LED_PIN, OUTPUT);  
  //digitalWrite(LED_PIN, HIGH);
  Serial.begin(9600);
  rf.RXInit(RX_PIN);

  ESC.attach(5);  
  ESC.setMinimumPulse(800);
  ESC.setMaximumPulse(2000);
  delay(100);
  ESC.write(0);
  Serial.println("booted");
}

void loop() {

  if (rf.available()) { //something is in RX buffer
    if (rf.receiveByte(data)) {
      
      ESC.write((int)data);
      SoftwareServo::refresh();
      delay(10);
      rpm = (int)data;
      timer = millis();
    }
  }
  
  timediff = millis() - timer;
  if(timediff > 100){
    
    while(rpm > 0){
      
    rpm = rpm-1;
      
      
    if(rpm<0){
      rpm=0;
    }
    ESC.write(rpm);
    SoftwareServo::refresh();
    delay(10);
    }
    
    //data = 0;
  }

  Serial.println("Timediff: " + String(timediff) + " RPM: " + String(rpm));
  //Serial.println((int)data);

}


