cmake_minimum_required (VERSION 3.9)
project ("cmake_generate_generic_processor" "C")

set (CMAKE_GENERATOR_PATH "" CACHE STRING "generator path")
set (CMAKE_TARGET_PATH    "" CACHE STRING "target path")

include ("../toolchain.cmake")

include_directories (${CMAKE_GENERATOR_PATH})
add_executable (
  "main"
  "${CMAKE_TARGET_PATH}/options.c"
  "alphabet.c"
  "data.c"
  "main.c"
  "max_state.c"
)
