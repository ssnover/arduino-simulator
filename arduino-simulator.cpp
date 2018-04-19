/*
 * file: arduino-simulator.cpp
 * purpose: Implementation of the ARDUINO_SIMULATOR functions for managing the hardware.
 */

#include <thread>
#include "arduino-simulator.hpp"


namespace SIM
{

ARDUINO_SIMULATOR::ARDUINO_SIMULATOR(std::string const & config) : my_config_file(config)
{
    my_simulator_thread = std::thread([this] {this->simulator_context();});
}


ARDUINO_SIMULATOR::~ARDUINO_SIMULATOR()
{
    // Empty destructor
}


void ARDUINO_SIMULATOR::begin(std::string const & circuit_config_file)
{
    static auto instance = ARDUINO_SIMULATOR(circuit_config_file);
    my_instance_initialized = true;
}


void ARDUINO_SIMULATOR::simulator_context()
{
    // do some initialization

    // TODO: Change this check a flag
    while (true)
    {
        // Check all inputs
    }
}

} // namespace SIM