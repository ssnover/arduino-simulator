/*
 * file: USART.cpp
 * purpose: Implement the Arduino Serial API in conjunction with the simulator.
 */

#include "USART.hpp"

namespace SIM
{
USART::USART() : my_simulator(ARDUINO_SIMULATOR::getInstance())
{
    // Empty constructor
}

USART & USART::getInstance()
{
    static auto instance = USART();
    return instance;
}

unsigned int USART::available()
{
    int difference = my_simulator->my_buffer_head_position - my_simulator->my_buffer_tail_position;
    return static_cast<unsigned int>((difference + 1024) % 1024);
}

void USART::begin(unsigned int speed, unsigned int config)
{
    LOGGER::getInstance()->printMessage("SERIAL: Port opened with baud: %d\r\n", speed);
    my_baud = speed;
    my_config = config;
    my_usart_enabled = true;
}

void USART::end()
{
    my_usart_enabled = false;
}

int USART::read()
{
    if (available())
    {
        int data = my_simulator->my_serial_input_buffer[my_simulator->my_buffer_tail_position++];
        my_simulator->my_buffer_tail_position %= 1024;
        return data;
    }
    else
    {
        return -1;
    }
}

} // namespace SIM
