cmake_minimum_required(VERSION 3.23)
project(Hash C)

set(CMAKE_C_STANDARD 99)

add_executable(Hash main.c hashTable.c hashTable.h linkedList.c linkedList.h)
