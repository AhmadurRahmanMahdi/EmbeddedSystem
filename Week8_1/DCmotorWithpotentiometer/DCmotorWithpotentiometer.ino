// Motor A
int enA = 9;
int in1=8;
int in2=7;
int SpeedControl1 = A0;
int MotorSpeed1 = 0;


void setup() {
  // put your setup code here, to run once:
pinMode(enA,OUTPUT);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  MotorSpeed1 = analogRead(SpeedControl1);
  MotorSpeed1 = map(MotorSpeed1,0,1023,0,255);
  if(MotorSpeed1<8)MotorSpeed1 = 0;
  analogWrite(enA, MotorSpeed1);
}
