cmake_minimum_required(VERSION 3.16)

set(This devine-samples)
project(${This} VERSION 0.1.0)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_subdirectory(library)
add_subdirectory(test)
add_subdirectory(googletest)

add_executable(${This} main.cpp )

target_link_libraries(${This} PUBLIC library)

target_include_directories(${This} PUBLIC
                      "${PROJECT_SOURCE_DIR}/library"
)
                           

