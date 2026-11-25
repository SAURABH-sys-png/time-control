cmake_minimum_required(VERSION 3.10)


project(time-control VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(time-control main.cpp src/functions.cpp)

target_include_directories(time-control PRIVATE include)
