#include "TimerOne.h"
int analogValue;
 
void setup()
{
  pinMode(A1, INPUT);
  Timer1.initialize(1000000); 
  Timer1.attachInterrupt(callback);
  Serial.begin(9600);
}
 
void callback()
{
  analogValue = analogRead(A1);
  Serial.print("RX arvo: ");
  Serial.println(analogValue);
}
 
void loop()
{
  // your program here...
}
 
