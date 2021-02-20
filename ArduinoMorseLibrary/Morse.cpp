/*
  Morse.cpp - Library for flashing Morse code.
  Created by Canberk ŞAHİN
  Released into the public domain.
*/

#include "Arduino.h"
#include "Morse.h"

//create morse ctor 
Morse::Morse(int pin)
{
    pinMode(pin,OUTPUT);
    _pin = pin;
}

//create dot function
void Morse::dot()
{
  digitalWrite(_pin, HIGH);
  delay(250);
  digitalWrite(_pin, LOW);
  delay(250);
}

//create dash function
void Morse::dash()
{
  digitalWrite(_pin, HIGH);
  delay(1000);
  digitalWrite(_pin, LOW);
  delay(250);
}

