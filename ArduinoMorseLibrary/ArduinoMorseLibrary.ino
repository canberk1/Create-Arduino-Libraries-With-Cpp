#include "Morse.h"

//13. Pin initialize
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
