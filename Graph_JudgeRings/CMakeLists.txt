cmake_minimum_required(VERSION 3.6)
project(Graph_JudgeRings)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Graph_JudgeRings ${SOURCE_FILES})