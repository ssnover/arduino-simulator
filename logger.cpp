/*
 * file: logger.cpp
 * purpose: Logs messages to a logfile.
 */

#include "logger.hpp"


namespace SIM
{

namespace
{
LOGGER * instance_ptr = nullptr;
} // anonymous namespace

LOGGER::LOGGER(std::string const * const log_filepath) : my_log_file(log_filepath)
{
    static bool initialized(false);
    if (!initialized)
    {
        instance_ptr = this;
        initialized = true;
        std::remove(my_log_file->c_str());
    }
}

LOGGER * LOGGER::getInstance()
{
    return instance_ptr;
}

void LOGGER::printMessage(char const *message, ...)
{
    va_list args;
    va_start(args, message);
    char message_buffer[2048];
    vsprintf(message_buffer, message, args);
    va_end(args);
    std::ofstream log_filestream;
    log_filestream.open(my_log_file->c_str(), std::ios_base::app);
    log_filestream << message_buffer;
    log_filestream.close();
}

} // namespace SIM
