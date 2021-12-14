cmake_minimum_required(VERSION 3.20)
project(mavlinktest)

set(CMAKE_CXX_STANDARD 14)

add_executable(mavlinktest main.cpp generic_port.h serial_port.cpp serial_port.h)
