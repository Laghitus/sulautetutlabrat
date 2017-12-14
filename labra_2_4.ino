#include "TimerOne.h"
int analogValue;
 
void setup()
{
  pinMode(A1, INPUT);
  Timer1.initialize(1000); 
  Timer1.attachInterrupt(callback);
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
 
