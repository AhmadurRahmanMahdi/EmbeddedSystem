//Security Alarm with Ultrasonic Sensor
/*
 * The buzzer will ring and the LED will lit up if someone
 * is within 50 cm distance from the ultrasonic sensor.
 */
#define trigPin 6
#define echoPin 7
#define buzzer 3
#define bluePin 9
float new_delay;
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(bluePin, OUTPUT);
}
void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)/29.1;
  new_delay = (distance*3)+30;
  Serial.print(distance);
  Serial.println(" cm");
  if(distance < 50) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(bluePin, HIGH);
  }
  else {
    digitalWrite(buzzer, LOW);
    digitalWrite(bluePin, LOW);
  }
  delay(200);
  
}
