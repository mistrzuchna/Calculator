cmake_minimum_required(VERSION 3.9)
project(Calculator C)

set(CMAKE_C_STANDARD 11)

add_executable(Calculator main.c ONPCalculate.h algebraicHandle.h stackHandle.h ONPCalculate.c algebraicHandle.c stackHandle.c necessaryLibraries.h validation.c validation.h menu.c menu.h fileHandle.c fileHandle.h)