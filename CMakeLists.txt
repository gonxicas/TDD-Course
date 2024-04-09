cmake_minimum_required(VERSION 3.28)
project(TDD_Course)

set(CMAKE_CXX_STANDARD 26)
add_subdirectory(Tests)
add_executable(TDD_Course maian.cpp
        src/Dollar.cpp
        src/Dollar.h
        src/Euro.cpp
        src/Euro.h
        src/Money.cpp
        src/Money.h)
