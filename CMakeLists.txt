cmake_minimum_required(VERSION 3.20)

project(pch)

add_subdirectory(googletest)

add_library(lib STATIC pch.cpp)

add_executable(main main.cpp)
add_executable(test test.cpp)

target_link_libraries(main lib)
target_link_libraries(test lib gtest gtest_main)