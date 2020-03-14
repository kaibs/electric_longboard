
#include  <Servo.h>

Servo esc;
int potpin = 0;
int val=0;
void setup()
{
esc.attach(9);
Serial.begin(9600);
esc.write(40); 
}
void loop()
{
val = analogRead(potpin);
//val = map(val, 0, 1023, 0, 180);
val= map(val, 0, 1023,1250,2500);
Serial.println(val);
esc.writeMicroseconds(val);
}
