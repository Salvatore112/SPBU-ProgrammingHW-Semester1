cmake_minimum_required(VERSION 3.23)
project(11_02_22 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(11_02_22
        binarySearchTree.c
        binarySearchTree.h
        main.c)
