cmake_minimum_required(VERSION 3.6)
project(ExpressionTree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp MyStack.h MyTree.h TreeNode.h)
add_executable(ExpressionTree ${SOURCE_FILES})