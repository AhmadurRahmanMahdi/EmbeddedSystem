/*
 * As we push the joystick forward the servo rotates
 * counterclockwise. If we push the joystick backward the servo rotates
 * clockwise.
 */
#include <Servo.h>
#define servoPin 9
#define groundJoyPin A3 //joystick ground pin will connect to Arduino analog pin A3
#define VoutJoyPin A2 //joystick +5V pin will connect to Arduino analog pin A2
#define xJoyPin A1//joystick x-axis pin will connect to Arduino analog pin A1
Servo myServo;
void setup() {
  Serial.begin(9600);
  pinMode(groundJoyPin, OUTPUT);
  pinMode(VoutJoyPin, OUTPUT);
  pinMode(xJoyPin, INPUT);
  digitalWrite(VoutJoyPin, HIGH);
  digitalWrite(xJoyPin, LOW);
  myServo.attach(9);

}

void loop() {
  delay(200);
  int joystickXVal = analogRead(xJoyPin);
  Serial.print(joystickXVal);
  Serial.println(" = input from joystick");
  Serial.print((joystickXVal+520)/10);
  Serial.println(" = output to servo");
  Serial.println();
  myServo.write((joystickXVal+520)/10);
}
