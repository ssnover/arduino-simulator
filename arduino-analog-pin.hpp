/*
 * file: arduino-analog-pin.hpp
 * purpose: Interface to a simulated Analog pin.
 */

#ifndef ARDUINO_ANALOG_PIN_HPP
#define ARDUINO_ANALOG_PIN_HPP

#include "arduino-pin-intf.hpp"
#include <cstdint>

namespace SIM
{
class ARDUINO_ANALOG_PIN : public ARDUINO_PIN_INTF
{
public:
    enum class ANALOG_PIN
    {
        A0 = 0u,
        A1,
        A2,
        A3,
        A4,
        A5,
        A6
    };

    ARDUINO_ANALOG_PIN(ANALOG_PIN pin_number)
        : my_pin(pin_number), my_pinSetAsAnalog(true), my_direction(DIRECTION::INPUT)
    {
    }
    ~ARDUINO_ANALOG_PIN() override = default;

    void pinMode(DIRECTION direction) override;

    void digitalWrite(STATE output_setting) override;

    STATE digitalRead() override;

    /*
     * Configures the pin to be used as an Analog Input.
     */
    void setAsAnalog();

    /*
     * Reads the analog pin's value from the ADC.
     *
     * Returns:
     * A 10-bit value representing the raw output from the ADC.
     */
    uint16_t analogRead();

    /*
     * Alternate interaction with reading from the analog pin.
     */
    inline uint16_t & operator>>(uint16_t & output)
    {
        output = analogRead();
        return output;
    }

private:
    ANALOG_PIN my_pin;
    bool my_pinSetAsAnalog;
    DIRECTION my_direction;
    STATE my_state;
};

} // namespace SIM

#endif // ARDUINO_ANALOG_PIN_HPP