cmake_minimum_required(VERSION 3.26)
project(veriYapilari)

set(CMAKE_CXX_STANDARD 17)

add_executable(veriYapilari main.cpp
        Node.h
        Sayi.h
        Basamak.h
        Node.cpp
        Basamak.cpp
        Sayi.cpp)
