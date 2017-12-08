

float voltage = 0;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  if(Serial.available() > 0){
  
  voltage = Serial.parseFloat();
}
  analogWrite(3,(voltage/5)*255);
  Serial.println((voltage/5)*255);
  
  // print out the value you read:

  delay(1);        // delay in between reads for stability
}
