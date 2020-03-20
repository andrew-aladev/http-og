cmake_minimum_required (VERSION 3.9)
project ("cmake_generator_parser_from_constant" "C")

include ("../toolchain.cmake")

include_directories (${CMAKE_GENERATOR_PATH})
add_executable (
  "main"
  "${CMAKE_GENERATOR_PATH}/constant.c"
  "data.c"
  "main.c"
  "min_state_bits.c"
)
