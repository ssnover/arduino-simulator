/*
 * file: arduino-emulated-calls.hpp
 * purpose: Provide an inteface similar to Arduino for the user code to call.
 */

#ifndef ARDUINO_EMULATED_CALLS_HPP
#define ARDUINO_EMULATED_CALLS_HPP


#include "USART.hpp"


namespace SIM
{

constexpr bool OUTPUT(true);
constexpr bool INPUT(false);
constexpr bool HIGH(true);
constexpr bool LOW(true);
USART & Serial = USART::getInstance();

/*
 * Sets a digital pin as an input or output.
 *
 * pin_number - The pin to change.
 * direction - The direction to set the pin to.
 */
void pinMode(int pin_number, bool direction);

/*
 * Sets a digital pin to a high or low logic state.
 *
 * pin_number - The pin to change.
 * output_setting - The state to set the pin to.
 */
void digitalWrite(int pin_number, bool output_setting);

/*
 * Gets the logic state of a digital pin.
 *
 * pin_number - The pin to read.
 *
 * Returns: A boolean representing the pin's electrical state.
 */
bool digitalRead(int pin_number);


/*
 * Pause application flow for a time period.
 *
 * seconds - The length of time to pause the application for.
 */
void wait(double seconds);

} // namespace SIM


#endif // ARDUINO_EMULATED_CALLS_HPP