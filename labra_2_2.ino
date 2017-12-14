// Muuttujat
int analogValue1;
int analogValue2;
float voltage;
float voltage1;
float voltage2;
float resistance;

void setup(){
  
  // Pinnit
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  Serial.begin(9600);

  cli();

  TCCR0A = 0;// set entire TCCR2A register to 0
  TCCR0B = 0;// same for TCCR2B
  TCNT0  = 0;//initialize counter value to 0
  OCR0A = 124;// = (16*10^6) / (2000*64) - 1 (must be <256)
  TCCR0A |= (1 << WGM01);
  TCCR0B |= (1 << CS01) | (1 << CS00);   
  TIMSK0 |= (1 << OCIE0A);

  sei();

}

ISR(TIMER0_COMPA_vect){
  analogValue1 = analogRead(A0);
  analogValue2 = analogRead(A1);
  Serial.print("Arvo 1: ");
  Serial.print(analogValue1);
  Serial.print("  Arvo 2: ");
  Serial.println(analogValue2);
}


void loop(){
  //do other things here
}
