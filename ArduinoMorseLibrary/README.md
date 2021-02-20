Firstly the library was written for the Morse Alphabet (Cited and Referanced by : https://www.arduino.cc/en/Hacking/libraryTutorial)

/* Library Name : ArduinoMorseLibrary */

1. We start with a sketch that does simple Morse code:

ABOUT

Writing a Library for Arduino
This document explains how to create a library for Arduino. It starts with a sketch for flashing Morse code and explains how to convert its functions into a library. This allows other people to easily use the code that you've written and to easily update it as you improve the library.

For more information, see the API Style Guide for information on making a good Arduino-style API for your library.

We start with a sketch that does simple Morse code:

int pin = 13;

void setup()
{
  pinMode(pin, OUTPUT);
}

void loop()
{
  dot(); dot(); dot();
  dash(); dash(); dash();
  dot(); dot(); dot();
  delay(3000);
}

void dot()
{
  digitalWrite(pin, HIGH);
  delay(250);
  digitalWrite(pin, LOW);
  delay(250);
}

void dash()
{
  digitalWrite(pin, HIGH);
  delay(1000);
  digitalWrite(pin, LOW);
  delay(250);
}

If you run this sketch, it will flash out the code for SOS (a distress call) on pin 13.

The sketch has a few different parts that we'll need to bring into our library. First, of course, we have the dot() and dash() functions that do the actual blinking. Second, there's the ledPin variable which the functions use to determine which pin to use. Finally, there's the call to pinMode() that initializes the pin as an output.

Let's start turning the sketch into a library!

You need at least two files for a library: a header file (w/ the extension .h) and the source file (w/ extension .cpp). The header file has definitions for the library: basically a listing of everything that's inside; while the source file has the actual code. We'll call our library "Morse", so our header file will be Morse.h. Let's take a look at what goes in it. It might seem a bit strange at first, but it will make more sense once you see the source file that goes with it.

The core of the header file consists of a line for each function in the library, wrapped up in a class along with any variables you need:

/* We create Class for Morse */
class Morse
{
  public:
    Morse(int pin);
    void dot();
    void dash();
  private:
    int _pin;
};

A class is simply a collection of functions and variables that are all kept together in one place. These functions and variables can be public, meaning that they can be accessed by people using your library, or private, meaning they can only be accessed from within the class itself. Each class has a special function known as a constructor, which is used to create an instance of the class. The constructor has the same name as the class, and no return type.

You need a couple of other things in the header file. One is an #include statement that gives you access to the standard types and constants of the Arduino language (this is automatically added to normal sketches, but not to libraries). It looks like this (and goes above the class definition given previously):

#include "Arduino.h"

Finally, it's common to wrap the whole header file up in a weird looking construct:

#ifndef Morse_h
#define Morse_h

// the #include statment and code go here...

#endif

Basically, this prevents problems if someone accidently #include's your library twice.

Finally, you usually put a comment at the top of the library with its name, a short description of what it does, who wrote it, the date, and the license.

Let's take a look at the complete header file:

/*
  Morse.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/
#ifndef Morse_h
#define Morse_h

#include "Arduino.h"

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

Now let's go through the various parts of the source file, Morse.cpp.
First comes a couple of #include statements. These give the rest of the code access to the standard Arduino functions, and to the definitions in your header file:

#include "Arduino.h"
#include "Morse.h"

Then comes the constructor. Again, this explains what should happen when someone creates an instance of your class. In this case, the user specifies which pin they would like to use. We configure the pin as an output save it into a private variable for use in the other functions:

Morse::Morse(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

There are a couple of strange things in this code. First is the Morse:: before the name of the function. This says that the function is part of the Morse class. You'll see this again in the other functions in the class. The second unusual thing is the underscore in the name of our private variable, _pin. This variable can actually have any name you want, as long as it matches the definition in the header file. Adding an underscore to the start of the name is a common convention to make it clear which variables are private, and also to distinguish the name from that of the argument to the function (pin in this case).

Next comes the actual code from the sketch that you're turning into a library (finally!). It looks pretty much the same, except with Morse:: in front of the names of the functions, and _pin instead of pin:

void Morse::dot()
{
  digitalWrite(_pin, HIGH);
  delay(250);
  digitalWrite(_pin, LOW);
  delay(250);  
}

void Morse::dash()
{
  digitalWrite(_pin, HIGH);
  delay(1000);
  digitalWrite(_pin, LOW);
  delay(250);
}

Finally, it's typical to include the comment header at the top of the source file as well. Let's see the whole thing:

#include "Arduino.h"
#include "Morse.h"

Morse::Morse(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void Morse::dot()
{
  digitalWrite(_pin, HIGH);
  delay(250);
  digitalWrite(_pin, LOW);
  delay(250);  
}

void Morse::dash()
{
  digitalWrite(_pin, HIGH);
  delay(1000);
  digitalWrite(_pin, LOW);
  delay(250);
}

And that's all you need (there's some other nice optional stuff, but we'll talk about that later). Let's see how you use the library.

First, make a Morse directory inside of the libraries sub-directory of your sketchbook directory. Copy or move the Morse.h and Morse.cpp files into that directory. Now launch the Arduino environment. If you open the Sketch > Import Library menu, you should see Morse inside. The library will be compiled with sketches that use it. If the library doesn't seem to build, make sure that the files really end in .cpp and .h (with no extra .pde or .txt extension, for example).

Let's see how we can replicate our old SOS sketch using the new library

#include <Morse.h>

Morse morse(13);

void setup()
{
}

void loop()
{
  morse.dot(); morse.dot(); morse.dot();
  morse.dash(); morse.dash(); morse.dash();
  morse.dot(); morse.dot(); morse.dot();
  delay(3000);
}



