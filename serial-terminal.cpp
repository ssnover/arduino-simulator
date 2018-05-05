/*
 * file; serial-terminal.cpp
 * purpose: Implement reads and writes to the Arduino Simulator's Serial
 * peripheral.
 */

#include <sstream>
#include <iostream>
#include "serial-terminal.hpp"

namespace SIM
{
SERIAL_TERMINAL::SERIAL_TERMINAL(std::string const * terminal_filepath)
    : my_filepath(terminal_filepath), my_terminal_file(my_filepath->c_str(), std::ios_base::trunc)
{
    // Touch the file and make sure it exists
    my_terminal_file.open(my_filepath->c_str(), std::ios_base::out);
    my_terminal_file.close();
}

SERIAL_TERMINAL::~SERIAL_TERMINAL()
{
    // Delete the file
    std::remove(my_filepath->c_str());
}


bool SERIAL_TERMINAL::run(bool * end_flag)
{
    std::string input_string;

    do
    {
        my_terminal_file.open(my_filepath->c_str(), std::ios_base::app);
        my_terminal_file << input_string;
        my_terminal_file << "\r\n";
        my_terminal_file.close();
        std::cin >> input_string;
        if (*end_flag)
        {
            return true;
        }
    }
    while (input_string.find("\\exit") == std::string::npos && !(*end_flag));

    size_t exit_string_position = input_string.find("\\exit");
    my_terminal_file.open(my_filepath->c_str(), std::ios_base::app);

    for (unsigned int i = 0; i < static_cast<unsigned int>(exit_string_position); ++i)
    {
        my_terminal_file << input_string.at(i);
    }

    my_terminal_file.close();

    return true;
}

} // namespace SIM