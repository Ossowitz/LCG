cmake_minimum_required(VERSION 3.25)
project(lkg C)

set(CMAKE_C_STANDARD 23)

add_library(lkg lkg.c repository/parse_command.h functions/get_c.h functions/get_a.h functions/lcg.h functions/test.h)
