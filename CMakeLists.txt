cmake_minimum_required(VERSION 3.14)
project(PortSo)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(PortSo main.cpp Ship.cpp Ship.h Dock.cpp Dock.h Cargo.cpp Cargo.h)