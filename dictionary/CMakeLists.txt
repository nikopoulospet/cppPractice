cmake_minimum_required(VERSION 3.17)
project(dictionary)

set(CMAKE_CXX_STANDARD 14)

add_executable(dictionary main.cpp dict.cpp dict.h)