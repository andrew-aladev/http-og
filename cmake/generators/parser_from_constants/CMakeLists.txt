cmake_minimum_required (VERSION 3.9)
project ("cmake_generator_parser_from_constants" "C")

include ("../toolchain.cmake")

include_directories (${CMAKE_GENERATOR_PATH})
add_executable (
  "main"
  "${CMAKE_GENERATOR_PATH}/constants.c"
  "main.c"
)
