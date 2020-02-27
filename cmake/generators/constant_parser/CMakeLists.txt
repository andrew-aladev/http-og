cmake_minimum_required (VERSION 3.9)
project ("cmake_generator_constant_parser" "C")

include ("../toolchain.cmake")

include_directories (${INCLUDE_DIRECTORIES})
add_executable ("main" "main.c")
