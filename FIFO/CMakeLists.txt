cmake_minimum_required(VERSION 3.17)
project(FIFO)

set(CMAKE_CXX_STANDARD 14)

add_executable(FIFO main.cpp deque.h deque.cpp)