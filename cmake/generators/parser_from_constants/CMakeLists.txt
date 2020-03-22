cmake_minimum_required (VERSION 3.9)
project ("cmake_generator_parser_from_constants" "C")

include ("../toolchain.cmake")

include_directories (${CMAKE_GENERATOR_PATH})
add_executable (
  "main"
  "${CMAKE_GENERATOR_PATH}/constants.c"
  "alphabet.c"
  "data.c"
  "main.c"
  "max_state.c"
  "min_state_bits.c"
  "next_state_by_last_symbols.c"
  "prefix.c"
)
