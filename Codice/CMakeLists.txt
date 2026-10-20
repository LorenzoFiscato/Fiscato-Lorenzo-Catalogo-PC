cmake_minimum_required(VERSION 4.2)
project(Codice)

set(CMAKE_CXX_STANDARD 20)

add_executable(Codice main.cpp
        Computer.h
        Catalogo.cpp
        Catalogo.h)
