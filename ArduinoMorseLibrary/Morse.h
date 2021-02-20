/*
  Morse.h - Library for flashing Morse code.
  Created by Canberk ŞAHİN. 
  Released into the public domain.
*/

/*Protect Multiple Inclusion Guard*/
#ifndef Morse_h
#define Morse_h

#include "Arduino.h"

//Create Morse Class
class Morse
{
  public:
    Morse(int pin);
    void dot();
    void dash();
  private:
    int _pin;
};

#endif
