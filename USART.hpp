/*
 * file: USART.hpp
 * purpose: Interface for the Arduino Simulator's USART to match the Arduino
 * Serial API.
 */

#ifndef USART_HPP
#define USART_HPP

#include <iostream>
#include "arduino-simulator.hpp"
#include "logger.hpp"

namespace SIM
{
enum SERIAL_CONFIG
{
    SERIAL_8N1 = 0,
};

class USART
{
public:

    /*
     * Returns a singleton instance of the USART driver.
     */
    static USART & getInstance();

    /*
     * Get the number of bytes available for reading from the serial port.
     *
     * Returns:
     * The number of bytes available to read.
     */
    unsigned int available();

    /*
     * Sets the data rate in bits per second for serial data transmission. An
     * option second argument configures the data, parity, and stop bits.
     */
    void begin(unsigned int speed, unsigned int config = SERIAL_8N1);


    /*
     * Disables Serial communication.
     */
    void end();

    template<typename T>
    size_t print(T value)
    {
        if (my_usart_enabled)
        {
            LOGGER::getInstance()->printMessage("SERIAL_TX: %s\r\n", value);
            std::cout << value;
        }
    }

    template<typename T>
    size_t println(T value)
    {
        if (my_usart_enabled)
        {
            LOGGER::getInstance()->printMessage("SERIAL_TX: %s\r\n", value);
            std::cout << value << std::endl;
        }
    }

    int read();

private:

    /*
     * Constructor.
     */
    USART();
    /*
     * Destructor.
     */
    ~USART() = default;

    ARDUINO_SIMULATOR * my_simulator;
    unsigned int my_baud;
    unsigned int my_config;
    bool my_usart_enabled;

}; // class USART

} // namespace SIM

#endif // USART_HPP