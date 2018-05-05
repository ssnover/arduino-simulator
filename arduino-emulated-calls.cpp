/*
 * file: arduino-emulated-calls.cpp
 * purpose: Implementation of the Arduino API for the simulator.
 */

#include <chrono>
#include <thread>
#include "arduino-emulated-calls.hpp"

namespace SIM
{

/*
 * Sets a pin as an input or output.
 */
void pinMode(int pin_number, bool direction)
{
    ARDUINO_PIN_INTF * pin = ARDUINO_SIMULATOR::getInstance()->getPin(pin_number);
    pin->pinMode(static_cast<ARDUINO_PIN_INTF::DIRECTION>(direction));
}


/*
 * Sets a digital pin to a high or low logic state.
 */
void digitalWrite(int pin_number, bool output_setting)
{
    // Get the Digital Pin
    ARDUINO_PIN_INTF * pin = ARDUINO_SIMULATOR::getInstance()->getPin(pin_number);
    pin->digitalWrite(static_cast<ARDUINO_PIN_INTF::STATE>(output_setting));
}


/*
 * Gets the logic state of a digital pin.
 */
bool digitalRead(int pin_number)
{
    // Get the Digital Pin
    ARDUINO_PIN_INTF * pin = ARDUINO_SIMULATOR::getInstance()->getPin(pin_number);
    return static_cast<bool>(pin->digitalRead());
}


/*
 * Pause application flow for a time period.
 */
void delay(double seconds)
{
    std::this_thread::__sleep_for(std::chrono::seconds(0), std::chrono::nanoseconds(static_cast<long int>(seconds * 1e9)));
}

} // namespace SIM