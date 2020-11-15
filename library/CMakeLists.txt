cmake_minimum_required(VERSION 3.16)

set(This library)
project(${This} VERSION 1.0.0)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)

set(Headers 
    findpeak.hpp
    largest_path_sum.hpp
)

add_library(${This} INTERFACE)

