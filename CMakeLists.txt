cmake_minimum_required(VERSION 3.10)
project(myStdAlgorithms CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(
    -Werror
    -Wall
    -fpermissive
    -pedantic
    -std=c++1z
)

message("=== My implementation of std::algorithms ===")


add_library(algorithms INTERFACE)
add_library(my::std::algorithms ALIAS algorithms)

target_include_directories(algorithms INTERFACE inc)

add_subdirectory(tst)