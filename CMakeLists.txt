cmake_minimum_required(VERSION 3.6)
project(SortedHuffman)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Test.cpp Test.h BinaryNode.cpp BinaryNode.h)
add_executable(SortedHuffman ${SOURCE_FILES})