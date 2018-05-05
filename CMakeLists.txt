cmake_minimum_required(VERSION 3.5)
project(simduino)

set(CMAKE_CXX_STANDARD 14)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(SOURCE_FILES
        main.cpp
        arduino-analog-pin.cpp
        arduino-digital-pin.cpp
        arduino-emulated-calls.cpp
        arduino-simulator.cpp
        arduino-sketch.ino.cpp
        logger.cpp
        serial-terminal.cpp
        USART.cpp)

set(HEADER_FILES
        arduino-analog-pin.hpp
        arduino-digital-pin.hpp
        arduino-emulated-calls.hpp
        arduino-pin-intf.hpp
        arduino-simulator.hpp
        arduino-sketch.hpp
        logger.hpp
        serial-terminal.hpp
        USART.hpp)

add_executable(simduino ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(simduino LINK_PUBLIC Threads::Threads)