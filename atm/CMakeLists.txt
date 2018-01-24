cmake_minimum_required(VERSION 3.8)
project(bank)

set(CMAKE_CXX_STANDARD 14)



file(GLOB_RECURSE HEADERS include/*.hpp)
file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(atm atm.cpp ${SOURCES} ${HEADERS})
target_include_directories(atm PRIVATE include)