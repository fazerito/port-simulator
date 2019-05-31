cmake_minimum_required(VERSION 3.14)
project(PortSo)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(PortSo main.cpp Ship.cpp Ship.h Dock.cpp Dock.h Cargo.cpp Cargo.h Window.cpp Window.h)
target_link_libraries(PortSo ${CURSES_LIBRARIES})