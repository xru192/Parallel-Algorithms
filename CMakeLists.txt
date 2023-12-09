cmake_minimum_required(VERSION 3.26)
project(ParallelAlgorithms)

set(CMAKE_CXX_STANDARD 20)

include_directories(Algorithms_lib)
add_subdirectory(Algorithms_lib)

add_executable(ParallelAlgorithms main.cpp)

add_subdirectory(Google_tests)
