cmake_minimum_required(VERSION 3.18)

project(simple-console-chat)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W --std=c++11")

set(SOURCE_FILES main.cpp
                 chatman.cpp
                 dataman.cpp)

add_executable(chat ${SOURCE_FILES})
