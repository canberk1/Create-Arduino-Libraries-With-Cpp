//Include Morse.h Header File
#include "Morse.h"

//Initialize 13.Pin 
Morse morse(13);

void setup() {
  

}

void loop() {
  // SOS Code
  morse.dot(); morse.dot(); morse.dot();
  morse.dash(); morse.dash(); morse.dash();
  morse.dot(); morse.dot(); morse.dot();
  delay(3000);
}
