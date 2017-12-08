

int pwm = 0;
double sensorvalue = 0;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(A0, INPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:

  
  
  
  analogWrite(3,pwm);
  pwm++;
  if(pwm > 255){
    pwm = 0;
  }
  sensorvalue = analogRead(A0);
  float voltage = sensorvalue * (5.0 / 1023.0);
  Serial.println(voltage);
  
  // print out the value you read:

  delay(100);        // delay in between reads for stability
}
