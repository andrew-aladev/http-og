cmake_minimum_required (VERSION 3.9)
project ("cmake_generate_constant_processor" "C")

set (GENERATOR_PATH "" CACHE STRING "generator path")
set (TARGET_PATH    "" CACHE STRING "target path")

include ("../toolchain.cmake")

include_directories (${GENERATOR_PATH})
add_executable (
  "main"
  "${TARGET_PATH}/options.c"
  "data.c"
  "main.c"
  "max_state.c"
)
