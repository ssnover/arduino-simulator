/*
 * file: arduino-digital-pin.hpp
 * purpose: Implement an interface to digital pins on the Arduino Simulator.
 */

#ifndef ARDUINO_DIGITAL_PIN_HPP
#define ARDUINO_DIGITAL_PIN_HPP

#include "arduino-pin-intf.hpp"

namespace SIM
{
class ARDUINO_DIGITAL_PIN : public ARDUINO_PIN_INTF
{
public:
    explicit ARDUINO_DIGITAL_PIN(int pin_number)
        : my_pin(pin_number), my_direction(DIRECTION::INPUT), my_state(STATE::LOW)
    {
    }
    ~ARDUINO_DIGITAL_PIN() override = default;

    void pinMode(DIRECTION direction) override;

    void digitalWrite(STATE output_setting) override;

    STATE digitalRead() override;

private:
    int my_pin;
    DIRECTION my_direction;
    STATE my_state;
};

} // namespace SIM

#endif // ARDUINO_DIGITAL_PIN_HPP
