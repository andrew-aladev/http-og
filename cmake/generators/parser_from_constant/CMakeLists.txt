cmake_minimum_required (VERSION 3.9)
project ("cmake_generator_parser_from_constant" "C")

include ("../toolchain.cmake")

include_directories (${CMAKE_INCLUDE_PATH})
add_executable ("main" "main.c")
