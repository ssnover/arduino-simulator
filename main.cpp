#include "arduino-simulator.hpp"
#include "logger.hpp"
#include "serial-terminal.hpp"
#include <csignal>
#include <iostream>

// TODO: Add operating system signal handling

namespace
{
std::string const DEFAULT_TERMINAL_FILE(".terminal");
SIM::SERIAL_TERMINAL my_terminal(&DEFAULT_TERMINAL_FILE);
std::string const LOG_FILE_PATH = "log.txt";
SIM::LOGGER my_logger(&LOG_FILE_PATH);
bool program_ending(false);
} // anonymous namespace

int main()
{
    // initialize the Arduino simulator
    auto & my_simulator = SIM::ARDUINO_SIMULATOR::begin(&DEFAULT_TERMINAL_FILE);
    signal(SIGINT, [](int s) {
        std::cout << "Signal Caught" << std::endl;
        program_ending = true;
    });

    // run the terminal as a Serial Terminal
    my_terminal.run(&program_ending);
    // When the terminal is quit in some way, end the program
    std::cout << "Simulator Ending" << std::endl;
    my_simulator.end();
    return 0;
}