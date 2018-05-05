/*
 * file: logger.hpp
 * purpose: A utility for sending all messages to a file.
 */

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <cstdarg>
#include <fstream>

namespace SIM
{
class LOGGER
{
public:
    /*
     * Constructor. Takes a string containing a local filepath for the logfile.
     */
    explicit LOGGER(std::string const * const log_filepath);
    ~LOGGER() = default;

    /*
     * Gets a global Singleton instance of the logger.
     */
    static LOGGER * getInstance();

    /*
     * Prints a message into the log file.
     */
    void printMessage(char const * message, ...);

private:
    std::string const * const my_log_file;
};

} // namespace SIM

#endif // LOGGER_HPP