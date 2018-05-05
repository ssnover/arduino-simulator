/*
 * file: serial-terminal.hpp
 * purpose: Interface the USART interface of the Arduino Simulator similar to
 *
 */

#ifndef SERIAL_TERMINAL_HPP
#define SERIAL_TERMINAL_HPP

#include <fstream>
#include <string>

namespace SIM
{
class SERIAL_TERMINAL
{
public:
    /*
     * Constructor.
     *
     * terminal_filepath - The local file used for communication between the two
     * threads.
     */
    SERIAL_TERMINAL(std::string const * terminal_filepath);

    /*
     * Destructor.
     */
    ~SERIAL_TERMINAL();

    /*
     * Runs the Serial terminal until a program flag marks that the program
     * should exit.
     *
     * Returns:
     * True.
     */
    bool run(bool * program_end_flag);

private:
    std::string const * my_filepath;
    std::ofstream my_terminal_file;
};

} // namespace SIM

#endif // SERIAL_TERMINAL_HPP