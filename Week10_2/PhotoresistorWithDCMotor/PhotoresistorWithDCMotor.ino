/*
 * For a reference value of 150 of the photresistor, the
 * DC motor turns on if the light value is greater than 150 else
 * the motor remains off.
 */
void setup()
{
  Serial.begin(9600);
  pinMode(11,OUTPUT);
  pinMode(A0,INPUT);
}

void loop()
{
  //digitalWrite(11,1);
  int a = analogRead(A0);
  Serial.println(a);
  /*int b = map(a,6,679,0,255);
  Serial.println(b);*/
  if(a<150)
  {
    digitalWrite(11,0);
  }
  else
  {
    analogWrite(11,a);
  }
}
