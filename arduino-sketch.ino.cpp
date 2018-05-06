/*
 * file: arduino-sketch.ino.cpp
 * purpose: Place for the user to put code to be run on the Arduino.
 */

#ifdef ARDUINO_SIMULATOR_FLAG
  #include "arduino-sketch.hpp"
#endif // ARDUINO_SIMULATOR_FLAG


void setup()
{
    Serial.begin(9600);
    pinMode(13, OUTPUT);
}


void loop()
{
    digitalWrite(13, HIGH);
    delay(0.5);
    digitalWrite(13, LOW);
    delay(0.5);
    Serial.println("Toggling my LED for dayssss");
}