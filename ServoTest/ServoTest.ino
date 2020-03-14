#include <Servo.h>

#define MOTOR_PIN 9
Servo motor;
int potpin = 0;
int val=0;

void setup() {
  Serial.begin(9600);
  motor.attach(MOTOR_PIN);
  motor.writeMicroseconds(1000);
  delay(5000);
}

void loop() {
  val = analogRead(potpin);
//val = map(val, 0, 1023, 0, 180);
val= map(val, 830, 1023,1000,2500);
Serial.println(val);
motor.writeMicroseconds(val);
}
