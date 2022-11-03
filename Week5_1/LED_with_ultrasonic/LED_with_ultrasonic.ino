/* The ultrasonic sensor will detect if any object is within 30 cm.
   If the object is within 30 cm distance, the red light will blink 
   else the green light will keep blinking.
 */

#define Trigpin 7
#define Echopin 8
#define low_led 9
#define high_led 10
float distance;
int duration;
int ll = 700;

void setup() {
  pinMode (Trigpin, OUTPUT);
  pinMode (low_led, OUTPUT);
  pinMode (high_led, OUTPUT);
  pinMode (Echopin, INPUT);
  Serial.begin(9600);
  Serial.println ("Welcome To Distance Meter");
  Serial.println ("Coded By Mohammad Ahmudur Rahman Mahdi");
  digitalWrite (low_led, LOW);
  digitalWrite (high_led, LOW);
}

void loop() {
  digitalWrite(Trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigpin, LOW);
  duration = pulseIn(Echopin, HIGH);
  distance = duration * 0.034 / 2;
  delay (ll);
  Serial.println (" ");
  Serial.print ("Distance = ");
  Serial.print (distance);
  Serial.print (" CM");
  Serial.println (" ");

  if (distance>=30)
  {
    Serial.println ("Nobody Is Infront Of the Sensor");
    digitalWrite (low_led, HIGH);
    delay (500);
    digitalWrite (low_led, LOW);
    delay (500);
    digitalWrite (low_led, HIGH);
  }
  else 
  {
    Serial.println ("Someone Is Infront Of the Sensor");
    digitalWrite (high_led, HIGH);
    delay (100);
    digitalWrite (high_led, LOW);
    delay (100);
    digitalWrite (high_led, HIGH);
    delay (100);
  }
}
