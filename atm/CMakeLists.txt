cmake_minimum_required(VERSION 3.8)
project(bank)

set(CMAKE_CXX_STANDARD 14)

file(GLOB HEADERS include/*.hpp)
file(GLOB SOURCES src/*.cpp)

add_executable(atm atm.cpp ${SOURCES} ${HEADERS})