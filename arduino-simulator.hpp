/*
 * file: arduino-simulator.hpp
 * purpose: A singleton class to manage the simulator and handle calls to Arduino hardware.
 */

#ifndef ARDUINO_SIMULATOR_HPP
#define ARDUINO_SIMULATOR_HPP


#include <string>


namespace SIM
{

class ARDUINO_SIMULATOR
{

public:

    //TODO: Define functions for getting pins available from the simulator
    //TODO: Define ARDUINO_PIN_INTF, ARDUINO_DIGITAL_PIN, ARDUINO_ANALOG_PIN

    /*
     * Initializes the class.
     */
    static void begin(std::string const & circuit_config_file);

private:

    static bool my_instance_initialized;
    std::string const & my_config_file;
    std::thread my_simulator_thread;

    ARDUINO_SIMULATOR(std::string const & config);
    ~ARDUINO_SIMULATOR();

    void simulator_context();

};

} // namespace SIM


#endif // ARDUINO_SIMULATOR_HPP