/*
 * file: arduino-analog-pin.cpp
 * purpose: Implement the Analog pin action of the simulator.
 */

#include "arduino-analog-pin.hpp"
#include "logger.hpp"
#include <cstdlib>

namespace SIM
{
void ARDUINO_ANALOG_PIN::pinMode(DIRECTION direction)
{
    if (my_pinSetAsAnalog)
    {
        // Always an input in analog mode
        my_direction = DIRECTION::INPUT;
    }
    else
    {
        my_direction = direction;
        LOGGER * messageLog = LOGGER::getInstance();
        messageLog->printMessage("AIO: Pin A%d set to Direction[", static_cast<int>(my_pin));
        if (DIRECTION::OUTPUT == my_direction)
        {
            messageLog->printMessage("OUTPUT");
        }
        else
        {
            messageLog->printMessage("INPUT");
        }
        messageLog->printMessage("]\r\n");
    }
}

void ARDUINO_ANALOG_PIN::digitalWrite(STATE output_setting)
{
    if (my_pinSetAsAnalog)
    {
        // Error condition, log it
        LOGGER::getInstance()->printMessage(
            "ERROR: digitalWrite() called on ANALOG_PIN set as ANALOG\r\n");
    }
    else if (DIRECTION::OUTPUT == my_direction)
    {
        // Drive the output to the setting, log it
        my_state = output_setting;
        LOGGER::getInstance()->printMessage(
            "AIO: Pin A%d set to State[%s]\r\n", my_pin,
            (static_cast<bool>(my_state)) ? "HIGH" : "LOW");
    }
}

ARDUINO_PIN_INTF::STATE ARDUINO_ANALOG_PIN::digitalRead()
{
    if (my_pinSetAsAnalog)
    {
        // Log an error
        LOGGER::getInstance()->printMessage(
            "ERROR: digitalRead() called on ANALOG_PIN set as ANALOG\r\n");
        return STATE::HIGH;
    }
    else
    {
        return static_cast<STATE>(std::rand() % 2);
    }
}

void ARDUINO_ANALOG_PIN::setAsAnalog()
{
    my_pinSetAsAnalog = true;
    my_direction = DIRECTION::INPUT;
    LOGGER::getInstance()->printMessage("AIO: Pin A%d set as ANALOG\r\n", my_pin);
}

uint16_t ARDUINO_ANALOG_PIN::analogRead()
{
    // Arduino ADC is 10-bit -> 2^10 = 1024
    return static_cast<uint16_t>(std::rand() % 1024);
}

} // namespace SIM