#include <iostream>
#include <thread>
#include "arduino-sketch.hpp"
#include "arduino-simulator.hpp"


namespace
{

constexpr std::string CIRCUIT_FILE("circuit.txt");
bool simulator_running;
SERIAL_TERMINAL my_terminal(SERIAL_TERMINAL::ECHO::ON);

} // anonymous namespace


int main() {

    // initialize the Arduino simulator
    SIM::ARDUINO_SIMULATOR::begin(CIRCUIT_FILE);
    // run the application firmware
    std::thread application_code([simulator_running]
                {
                    setup();
                    while (simulator_running)
                    {
                        loop();
                    }
                });

    // run the terminal as a Serial Terminal
    my_terminal.run();
    return 0;
}