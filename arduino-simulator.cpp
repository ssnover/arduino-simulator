/*
 * file: arduino-simulator.cpp
 * purpose: Implementation of the ARDUINO_SIMULATOR functions for managing the
 * hardware.
 */

#include "arduino-simulator.hpp"
#include "arduino-sketch.hpp"
#include "logger.hpp"
#include <fstream>

namespace SIM
{

namespace
{
ARDUINO_SIMULATOR * instance_ptr = nullptr;
}  // anonymous namespace

ARDUINO_SIMULATOR::ARDUINO_SIMULATOR(std::string const * terminal_file)
    : my_serial_terminal_file(terminal_file), my_status(true)
{
    if (instance_ptr == nullptr)
    {
        instance_ptr = this;
    }
    // Initialize all the pins
    for (int i = 0; i < my_pins.size(); ++i)
    {
        if (i <= 13)
        {
            my_pins[i] = new ARDUINO_DIGITAL_PIN(i);
        }
        else
        {
            my_pins[i] = new ARDUINO_ANALOG_PIN(static_cast<ARDUINO_ANALOG_PIN::ANALOG_PIN>(i - 14));
        }
    }

    my_simulator_thread = std::thread([this] { this->simulator_context(); });
    my_usart_thread = std::thread([this] { this->uart_rx_isr_context(); });
}


ARDUINO_SIMULATOR::~ARDUINO_SIMULATOR()
{
    for (auto i : my_pins)
    {
        delete i;
    }
}

ARDUINO_SIMULATOR & ARDUINO_SIMULATOR::begin(std::string const * serial_terminal_file)
{
    static ARDUINO_SIMULATOR instance(serial_terminal_file);
    instance_ptr = &instance;
    return instance;
}

void ARDUINO_SIMULATOR::end()
{
    my_status = false;
    my_usart_thread.join();
    my_simulator_thread.join();
}

ARDUINO_SIMULATOR * ARDUINO_SIMULATOR::getInstance()
{
    return instance_ptr;
}

void ARDUINO_SIMULATOR::simulator_context()
{
    LOGGER::getInstance()->printMessage("INFO: Simulator Starting\r\n");
    setup();

    while (my_status)
    {
        loop();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    LOGGER::getInstance()->printMessage("INFO: Simulator Shutting Down\r\n");
}

void ARDUINO_SIMULATOR::uart_rx_isr_context()
{
    while (my_status)
    {
        std::ifstream serial_tx_input;
        std::string most_recent_input;
        // Check the file
        serial_tx_input.open(my_serial_terminal_file->c_str(), std::ios_base::in);
        serial_tx_input >> most_recent_input;
        serial_tx_input.close();
        // Delete to remove the contents, this will be recreated by the Serial
        // Terminal
        std::remove(my_serial_terminal_file->c_str());
        // If there's new data, put it into buffer
        if (!most_recent_input.empty())
        {
            LOGGER::getInstance()->printMessage("SERIAL_RX: %s\r\n", most_recent_input.c_str());
            for (unsigned long i = 0; i < most_recent_input.length(); ++i)
            {
                // Copy the character in
                my_serial_input_buffer[my_buffer_head_position++] =
                    static_cast<unsigned char>(most_recent_input.at(i));
                // Advance the header position of the ring buffer
                my_buffer_head_position %= 1024;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}


ARDUINO_PIN_INTF * ARDUINO_SIMULATOR::getPin(int pin_number)
{
    if (pin_number < 0 || pin_number > 20)
    {
        LOGGER::getInstance()->printMessage("ERROR: Invalid pin specified\r\n");
        my_status = false;
        exit(EXIT_FAILURE);
    }

    return my_pins[pin_number];
}

} // namespace SIM