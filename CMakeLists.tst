cmake_minimum_requiered(3.10)

project(time-control version 1.0)

add_executable(time-control main.cpp src/)

target_include_directories(time-control PRIVATE time-control/include)
