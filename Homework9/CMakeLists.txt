cmake_minimum_required(VERSION 3.23)
project(brandNewAVL C)

set(CMAKE_C_STANDARD 99)

add_executable(brandNewAVL main.c avlTree.c avlTree.h)
