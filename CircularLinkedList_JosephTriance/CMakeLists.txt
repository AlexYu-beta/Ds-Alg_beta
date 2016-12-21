cmake_minimum_required(VERSION 3.6)
project(CircularLinkedList_JosephTriance)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp CircularLinkedList.h)
add_executable(CircularLinkedList_JosephTriance ${SOURCE_FILES})