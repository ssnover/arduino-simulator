/*
 * file: arduino-simulator.hpp
 * purpose: A singleton class to manage the simulator and handle calls to
 * Arduino hardware.
 */

#ifndef ARDUINO_SIMULATOR_HPP
#define ARDUINO_SIMULATOR_HPP

#include <array>
#include <string>
#include <thread>
#include "arduino-analog-pin.hpp"
#include "arduino-digital-pin.hpp"

namespace SIM
{
/*
 * Forward declaration to allow USART to be a friend of ARDUINO_SIMULATOR.
 */
class USART;

class ARDUINO_SIMULATOR
{
public:

    /*
     * Objects available to the sketch as Arduino API need access to the simulator "hardware".
     */
    friend class USART;
    friend void pinMode(int pin_number, bool direction);
    friend void digitalWrite(int pin_number, bool output_setting);
    friend bool digitalRead(int pin_number);

    /*
     * Initializes the class and sets some shared files used for communication
     * and returns an instance of the simulator.
     *
     * serial_terminal_file: A local filepath string for the file to read in
     *                       user serial data from.
     */
    static ARDUINO_SIMULATOR & begin(std::string const * serial_terminal_file);

    /*
     * Signals to the simulator threads to end execution and join.
     */
    void end();

    /*
     * Returns a pointer to a Singleton instance of the simulator, or nullptr if
     * it does not exist.
     */
    static ARDUINO_SIMULATOR * getInstance();

private:
    std::string const * my_serial_terminal_file;
    std::thread my_simulator_thread;
    std::thread my_usart_thread;
    bool my_status;
    std::array<uint8_t, 1024> my_serial_input_buffer;
    unsigned int my_buffer_head_position;
    unsigned int my_buffer_tail_position;
    std::array<ARDUINO_PIN_INTF *, 20> my_pins;

    /*
     * Constructor is hidden to enforce the singleton pattern. Spawns two
     * threads for the execution of the simulator.
     */
    explicit ARDUINO_SIMULATOR(std::string const * serial_terminal_file);

    /*
     * Deallocates all of the pin objects.
     */
    ~ARDUINO_SIMULATOR();

    /*
     * Runs the Arduino code written by the user. Sleeps for 1 millisecond
     * between runs of loop().
     */
    void simulator_context();

    /*
     * Runs the context for checking if new data is available to be read in by
     * Serial and emplaces it into the ring buffer.
     */
    void uart_rx_isr_context();

    /*
     * Gets the pin from the array.
     */
    ARDUINO_PIN_INTF * getPin(int pin_number);
};

} // namespace SIM

#endif // ARDUINO_SIMULATOR_HPP