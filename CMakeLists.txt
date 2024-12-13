cmake_minimum_required(VERSION 3.25)
project(obj_projektas)

include_directories(Include)

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