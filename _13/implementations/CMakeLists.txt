cmake_minimum_required(VERSION 3.29)
project(implementations)

set(CMAKE_CXX_STANDARD 20)

add_executable(implementations main.cpp
        Stack.cpp
        Stack.h
        Queue.cpp
        Queue.h
        LinkedList.cpp
        LinkedList.h
)
