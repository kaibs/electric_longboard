#include <Manchester.h>
#include <SoftwareServo.h>


#define RX_PIN 2

SoftwareServo ESC;

//ManchesterRF rf(MAN_1200); //link speed, try also MAN_300, MAN_600, MAN_1200, MAN_2400, MAN_4800, MAN_9600, MAN_19200, MAN_38400

//uint8_t data;
unsigned long timer = 0;
unsigned long timer2 = 0;
unsigned long timediff = 0;
int rpm;
int rpm2 = 0;
int rpmOld = 0;


void setup() {
  //pinMode(LED_PIN, OUTPUT);  
  //digitalWrite(LED_PIN, HIGH);
  Serial.begin(9600);
  //rf.RXInit(RX_PIN);
  man.setupReceive(RX_PIN, MAN_1200);
  man.beginReceive();
  
  ESC.attach(5);  
  ESC.setMinimumPulse(800);
  ESC.setMaximumPulse(2000);
  delay(100);
  ESC.write(0);
  
  Serial.println("booted: ");
}

void loop() {

  if (man.receiveComplete()) {
    uint8_t data = man.getMessage();
    man.beginReceive(); //start listening for next message right after you retrieve the message
    //do something with your message here
    rpm2 = rpmOld;
    rpm = (int)data;
    //timer = millis();
  }
  
  //timediff=millis()-timer;
  rpm2=map(rpm,12,149,0,179);
  if(rpm2 > 179){
    rpm2 = 179;
  }
  if(rpm2 < 2){
    rpm2 = 0;
  }
  ESC.write(rpm2);
  SoftwareServo::refresh();
  //delay(10); 
  //Serial.println("received: " + String(rpm) + " -> " + String(rpm2) + "  timediff: " + String(timediff));
  Serial.println("received: " + String(rpm) + " -> " + String(rpm2));
  timediff = millis() - timer;
  
  //Serial.println("Timediff: " + String(timediff) + " RPM: " + String(rpm));
  //Serial.println((int)data);

}


