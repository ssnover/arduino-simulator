/*
 * file: arduino-sketch.hpp
 * purpose: Defines the function declarations for the setup and loop functions
 *          to be defined by the user's sketch.
 */

#ifndef ARDUINO_SKETCH_HPP
#define ARDUINO_SKETCH_HPP


#include "arduino-emulated-calls.hpp"


/*
 * Called once at the start of the user's sketch.
 */
void setup();


/*
 * Called repeatedly forever to execute cyclical parts of the user's sketch.
 */
void loop();


using namespace SIM;

#endif // ARDUINO_SKETCH_HPP