cmake_minimum_required(VERSION 3.10)
project(obj_projektas)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
    src/main.cpp
    src/Stud.cpp
)

set(HEADERS
    src/Stud.h
    src/Mylib.h
    src/timer.h
)

add_executable(obj_projektas ${SOURCES} ${HEADERS})