cmake_minimum_required(VERSION 3.6)
project(2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    141044070/main.cpp
    141044070/siralama.txt
    141044070/tam_karaler.txt)

add_executable(2 ${SOURCE_FILES})