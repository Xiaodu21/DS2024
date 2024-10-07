cmake_minimum_required(VERSION 3.29)
project(DS2024A)

set(CMAKE_CXX_STANDARD 14)

include_directories(exp1)
include_directories(Mylab)

add_executable(DS2024A
    exp1/Complex.cpp
    exp1/Complex.h
    exp1/main.cpp
    Mylab/List.h
    Mylab/Stack.h
    Mylab/Vector.h)
