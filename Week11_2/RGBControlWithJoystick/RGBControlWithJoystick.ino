/*
 * For different position of the joystick handle we get different
 * colored lights from RGB LED
 */
const int SW_pin = 2; //joystick SW pin connected to digital pin 2
const int X_pin = A0; //joystick VRx pin connected to analog pin A0
const int Y_pin = A1; //joystick VRy pin connected to analog pin A1
int redPin = 9; //RGB red pin connected to digital 9
int greenPin = 10; //RGB green pin connected to digital 9
int bluePin = 11; //RGB blue pin connected to digital 9
int YPIN; //Declaring integers for letter
int XPIN;
int SWPIN;

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
}
void setColor(int red, int green, int blue) //sets up format for colors
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void loop() {
  YPIN = analogRead(Y_pin); //sets the number that comes out of joystick VRy pin
  XPIN = analogRead(X_pin);
  SWPIN = digitalRead(SW_pin);

  Serial.print("Switch: ");
  Serial.println(SWPIN);
  Serial.print(" ");
  Serial.print("X-axis: ");
  Serial.println(XPIN);
  Serial.print(" ");
  Serial.print("Y-axis: ");
  Serial.println(YPIN);
  if(YPIN == 0) {
    setColor(100, 80, 0); 
    delay(100);
    }   //if YPIN is equal to 0, set the color
 else {
  setColor(0, 0, 0);
  }
  
 if(YPIN == 1023) {
  setColor(225, 0, 225); 
  delay(100);
  }
 else {
  setColor(0, 0, 0);
  }
    
if(XPIN == 0) {
  setColor(0, 0, 225); 
  delay(100);
  }
else   {
  setColor(0, 0, 0);
  }

if(XPIN == 1023) {
  setColor(0, 225, 0); 
  delay(100);
  }
 else {
  setColor(0, 0, 0);
  }

if(SWPIN == LOW) {
  setColor(80, 20, 0); 
  delay(100);
  }   //if SWPIN is low set color
 else {
  setColor(0, 0, 0);
  }

}
