//Interrupts using Arduino
/*
A number is incremented from 0 and two push buttons are used to trigger Interrupt, 
each one is connected to pin 2 & 3. An LED is used to indicate the Interrupt. 
If one push button is pressed the led goes ON and display shows interrupt2 and goes off, 
and when another push button is pressed the led goes OFF and the display shows interrupt1 and goes off.
*/


#include<LiquidCrystal.h>                        // Including lcd display library

LiquidCrystal lcd (7,8,9,10,11,12);              // Define LCD display pins RS,E,D4,D5,D6,D7



volatile int output = LOW;                      

int i = 0;   


void setup()                                                      


{

  lcd.begin(16,2);                              //  setting LCD as 16x2 type

  lcd.setCursor(0,0);

  lcd.print("MAHDI");                                    

  lcd.setCursor(0,1);

  lcd.print("ArduinoInterrupt");

  delay(3000);                                                     

  lcd.clear();                                                    

  pinMode(13,OUTPUT);                                           

                                   

  attachInterrupt(digitalPinToInterrupt(2),buttonPressed1,RISING);  //  function for creating external interrupts at pin2 on Rising (LOW to HIGH)

  attachInterrupt(digitalPinToInterrupt(3),buttonPressed2,RISING);  //  function for creating external interrupts at pin3 on Rising (LOW to HIGH)   

  

}


void loop()                                                      

{  

   lcd.clear();                                                   

   lcd.print("COUNTER:");                                           

   lcd.print(i);                                                  

   ++i;                                                            

   delay(1000);   

   digitalWrite(13,output);     //Turns LED ON or OFF depending upon output value

}


void buttonPressed1()           //ISR function excutes when push button at pinD2 is pressed

{                    

   output = LOW;                //Change Output value to LOW                                

   lcd.setCursor(0,1);                                          

   lcd.print("Interrupt 1");

}


void buttonPressed2()           //ISR function excutes when push button at pinD3 is pressed                             

{                    

   output = HIGH;               //Change Output value to HIGH                                    

   lcd.setCursor(0,1);                                          

   lcd.print("Interrupt2");

}
