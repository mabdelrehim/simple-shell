cmake_minimum_required(VERSION 3.12)
project(simple_shell C)

set(CMAKE_C_STANDARD 11)

add_executable(simple_shell main.c parser.h execute.h parser.c execute.c sig-handler.c sig-handler.h)