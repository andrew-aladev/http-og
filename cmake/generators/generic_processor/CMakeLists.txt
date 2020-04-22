cmake_minimum_required (VERSION 3.9)
project ("cmake_generate_generic_processor" "C")

set (GENERATOR_PATH "" CACHE STRING "generator path")
set (TARGET_PATH    "" CACHE STRING "target path")

include ("../toolchain.cmake")

include_directories (${GENERATOR_PATH})
add_executable (
  "main"
  "${TARGET_PATH}/options.c"
  "alphabet.c"
  "data.c"
  "main.c"
  "max_state.c"
)
