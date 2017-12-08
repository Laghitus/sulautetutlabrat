

int pwm = 0;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(6,INPUT);
  pinMode(3,OUTPUT);

  // set the ACSR Register - analog comparator

  ACSR |= (0 << ACD); // Analog Comparator: Enabled
  ACSR |= (0 << ACBG); // Analog Comparator Bandgap off
  ACSR |= (0 << ACO); // Analog Comparator Output: Off
  ACSR |= (1 << ACI); // Analog Comparator Interrupt Flag
  ACSR |= (1 << ACIE); // Analog Comparator Interrupt Enable
  ACSR |= (0 << ACIC); // Analog Comparator Input Capture: Disabled
  ACSR |= (0 << ACIS1); // Comparator Interrupt on Rising Output Edge
  ACSR |= (0 << ACIS0); // Comparator Interrupt on Rising Output Edge
  ADCSRB = 0x0;



  
}

// the loop routine runs over and over again forever:
void loop() {
  analogWrite(3,pwm);
  pwm++;
  if(pwm > 255){
    pwm = 0;
    
}
  
  float voltage = ((float)pwm / 255)*5;
  Serial.println(voltage);
  


  delay(100);        // delay in between reads for stability
}
 ISR(ANALOG_COMP_vect)
{
  pwm = 0;
  analogWrite(3,pwm);
  Serial.println("Keskeytys");
  
}

