cmake_minimum_required(VERSION 3.6)
project(141044070)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    computer.cpp
    computer.h
    CPUProgram.cpp
    CPUProgram.h
    main.cpp
    memory.cpp
    myCpu.cpp
    myCpu.h requiredIncs.h mainTester.cpp)

add_executable(141044070 ${SOURCE_FILES})