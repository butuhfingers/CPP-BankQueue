cmake_minimum_required(VERSION 3.8)
project(BankQueue)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Client.cpp Client.h)
add_executable(BankQueue ${SOURCE_FILES})