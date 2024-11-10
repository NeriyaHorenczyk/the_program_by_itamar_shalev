cmake_minimum_required(VERSION 3.29)
project(ImpGraph)

set(CMAKE_CXX_STANDARD 20)

add_executable(ImpGraph main.cpp
        Graph.cpp
        Graph.h)
