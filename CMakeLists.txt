cmake_minimum_required(VERSION 3.5)
project(simduino)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        main.cpp
        arduino-emulated-calls.cpp
        arduino-simulator.cpp
        arduino-sketch.ino.cpp
        USART.cpp)

set(HEADER_FILES
        arduino-emulated-calls.hpp
        arduino-simulator.hpp
        arduino-sketch.hpp
        USART.hpp)

add_executable(simduino ${SOURCE_FILES} ${HEADER_FILES})