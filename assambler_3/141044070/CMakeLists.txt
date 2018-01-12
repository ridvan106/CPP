cmake_minimum_required(VERSION 3.6)
project(141044070)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp myCpu.h myCpu.cpp CPUProgram.h CPUProgram.cpp)
add_executable(141044070 ${SOURCE_FILES} myCpu.h myCpu.cpp CPUProgram.h CPUProgram.cpp)