# Create-Arduino-Libraries-With-Cpp

As you know, Arduino is an open source microcontroller platform developed for anyone who is interested in electronics to use it easily.Using Arduino, it can read signals from various sensors, turn lights on and off, and start motors; In short, all electronic applications you can think of can be done.At this point, the arduino platform supports users at many points.For example, many sensors and shields have been produced for Arduino in the style of plug and play. In addition, many ready-made libraries are offered by Arduino for many sensors.Thus, Arduino users can easily develop projects without having knowledge about software and hardware. However, in some cases, ready-made software libraries are insufficient, for example you want to make your own independent project etc. In this case, you have to create our own library. If we want to write our own library for Arduino, we need to use C ++ language.

In this project, we created our own libraries with simple codes for Arduino.C ++ language was used in the projects.So you can improve yourself in creating libraries for Arduino.

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

