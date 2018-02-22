cmake_minimum_required(VERSION 3.8)
project(NourishClient)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Client.h Client.cpp ProtocolMessage.h ProtocolMessage.cpp MyThread.h MyThread.cpp)
add_executable(NourishClient ${SOURCE_FILES})