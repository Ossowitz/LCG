cmake_minimum_required(VERSION 3.25)
project(lkg C)

set(CMAKE_C_STANDARD 23)

add_library(lkg main/lkg.c repository/parse_command.h)
