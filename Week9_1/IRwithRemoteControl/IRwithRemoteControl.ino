/*
 * If any button in the remote controller is pressed the
 * hex value of that button is showed in the 
 * Serial Monitor.
 */
#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results   results;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void   loop(){
  if (irrecv.decode(&results)){
        Serial.println(results.value,   HEX);
        irrecv.resume();
  }
}
