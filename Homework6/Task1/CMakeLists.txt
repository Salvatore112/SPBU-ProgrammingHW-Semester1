cmake_minimum_required(VERSION 3.23)
project(Task1 C)

set(CMAKE_C_STANDARD 99)

add_executable(Task1 main.c stack.c stack.h stackTests.c stackTests.h)
