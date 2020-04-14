cmake_minimum_required (VERSION 3.9)
project ("cmake_generate_constant_processor" "C")

include ("../toolchain.cmake")

include_directories (${CMAKE_GENERATOR_PATH})
add_executable (
  "main"
  "${CMAKE_TARGET_PATH}/options.c"
  "data.c"
  "main.c"
  "max_state.c"
)
