/*
 * file: arduino-digital-pin.cpp
 * purpose: Implements digital IO function calls in the Arduino simulator.
 */

#include "arduino-digital-pin.hpp"
#include "logger.hpp"
#include <cstdlib>

namespace SIM
{
void ARDUINO_DIGITAL_PIN::pinMode(DIRECTION direction)
{
    my_direction = direction;
    LOGGER::getInstance()->printMessage(
        "DIO: Pin D%d set to Direction[%s]\r\n", my_pin,
        (static_cast<bool>(my_direction)) ? "OUTPUT" : "INPUT");
}

void ARDUINO_DIGITAL_PIN::digitalWrite(STATE output_setting)
{
    if (DIRECTION::OUTPUT == my_direction)
    {
        my_state = output_setting;
        // Log the setting of the output
        LOGGER::getInstance()->printMessage(
            "DIO: Pin D%d set to State[%s]\r\n", my_pin,
            (static_cast<bool>(my_state)) ? "HIGH" : "LOW");
    }
}

ARDUINO_PIN_INTF::STATE ARDUINO_DIGITAL_PIN::digitalRead()
{
    if (DIRECTION::OUTPUT == my_direction)
    {
        return my_state;
    }
    else
    {
        return static_cast<STATE>(std::rand() % 2);
    }
}

} // namespace SIM
