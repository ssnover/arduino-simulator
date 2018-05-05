/*
 * file: arduino-pin-intf.hpp
 * purpose: Defines a generic pin interface for the Arduino Simulator analog and digital pins.
 */

#ifndef ARDUINO_PIN_INTF_HPP
#define ARDUINO_PIN_INTF_HPP


namespace SIM
{

class ARDUINO_PIN_INTF
{
public:

    enum class DIRECTION
    {
        INPUT = 0u,
        OUTPUT = 1u,
    };

    enum class STATE
    {
        LOW = 0u,
        HIGH = 1u,
    };

    ARDUINO_PIN_INTF() = default;
    virtual ~ARDUINO_PIN_INTF() = default;

    /*
     * Sets the direction of the GPIO pin.
     *
     * direction - Input or output, direction of current flow.
     */
    virtual void pinMode(DIRECTION direction) = 0;

    /*
     * Writes a logic level to the pin's driver.
     *
     * output_setting - The logic level to write.
     */
    virtual void digitalWrite(STATE output_setting) = 0;

    /*
     * Reads the logic level from the pin.
     *
     * Returns:
     * A logic level encoded as High or Low.
     */
    virtual STATE digitalRead() = 0;

};

} // namespace SIM


#endif // ARDUINO_PIN_INTF_HPP
