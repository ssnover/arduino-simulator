/*
 * file: arduino-sketch.ino.cpp
 * purpose: Place for the user to put code to be run on the Arduino.
 */

#include "arduino-sketch.hpp"


void setup()
{
    Serial.begin(9600);
    pinMode(13, OUTPUT);
}


void loop()
{
    digitalWrite(13, HIGH);
    wait(0.5);
    digitalWrite(13, LOW);
    wait(0.5);
    Serial.println("Toggling my LED for dayssss");
}