/*
 * file: arduino-emulated-calls.cpp
 * purpose: Implementation of the Arduino API for the simulator.
 */

#include <chrono>
#include <thread>
#include "arduino-emulated-calls.hpp"
#include "arduino-simulator.hpp"

namespace SIM
{

/*
 * Sets a digital pin as an input or output.
 */
void pinMode(int pin_number, bool direction)
{
    // TODO: Make this take an Arduino Sim Pin
    // Make a call to the Arduino Simulator
    ARDUINO_SIMULATOR::pinMode(pin_number, direction);
}


/*
 * Sets a digital pin to a high or low logic state.
 */
void digitalWrite(int pin_number, bool output_setting)
{
    // Get the Digital Pin
}


/*
 * Gets the logic state of a digital pin.
 */
bool digitalRead(int pin_number)
{
    // Get the Digital Pin
}


/*
 * Pause application flow for a time period.
 */
void wait(double seconds)
{
    auto time_seconds = std::chrono_literals::operator""s(0);
    auto time_nanoseconds = std::chrono_literals::operator""ns(seconds * 1e9);
    std::this_thread::__sleep_for(time_seconds, time_nanoseconds);
}

} // namespace SIM