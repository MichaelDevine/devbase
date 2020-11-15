cmake_minimum_required(VERSION 3.16)

set(This library_tests)

set(Sources
    findpeak_tests.cpp
    largest_path_sum_tests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    library
)
target_include_directories(${This} PUBLIC
                      "${PROJECT_SOURCE_DIR}/library"
)

add_test(
    NAME ${This}
    COMMAND ${This}
)

