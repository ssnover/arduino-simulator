/*
 * file: arduino-emulated-calls.hpp
 * purpose: Provide an interface similar to Arduino for the user code to call.
 */

#ifndef ARDUINO_EMULATED_CALLS_HPP
#define ARDUINO_EMULATED_CALLS_HPP


#include "USART.hpp"
#include "arduino-simulator.hpp"


namespace SIM
{

namespace
{
SIM::USART & Serial = SIM::USART::getInstance();
} // anonymous namespace

constexpr bool OUTPUT(true);
constexpr bool INPUT(false);
constexpr bool HIGH(true);
constexpr bool LOW(false);
constexpr int A0(14);
constexpr int A1(15);
constexpr int A2(16);
constexpr int A3(17);
constexpr int A4(18);
constexpr int A5(19);
constexpr int A6(20);

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
void delay(double seconds);

} // namespace SIM


#endif // ARDUINO_EMULATED_CALLS_HPP