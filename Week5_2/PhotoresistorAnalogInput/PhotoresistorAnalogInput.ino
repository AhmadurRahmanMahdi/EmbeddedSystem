//The photoresistor is an electronic component which resistivity varies according to the amount of light received ( the resistance decreases when exposed to the light ).

//The photoresistor is made of cadmium sulphide tape, a semiconductor.

//When photons hit the tapes, electrons can pass through the semiconductor.

//The main use of the photoresistor is the measurement of the luminous intensity ( camera, detection systems, … ).

void setup() {
  Serial.begin(9600);
}


void loop() {
  int value = analogRead(A0);
  Serial.println("Analog value : ");
  Serial.println(value);
  delay(250);
}
