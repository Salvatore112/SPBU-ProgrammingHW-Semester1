cmake_minimum_required(VERSION 3.23)
project(NewTreeAVL C)

set(CMAKE_C_STANDARD 99)

add_executable(NewTreeAVL main.c avlTree.c avlTree.h)
