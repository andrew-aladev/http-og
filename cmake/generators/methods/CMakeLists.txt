cmake_minimum_required (VERSION 3.9)
project ("cmake_generate_methods" "C")

include ("../toolchain.cmake")

include_directories (${CMAKE_LIBXML2_INCLUDE_DIRS})

add_executable (
  "main"
  "data.c"
  "file.c"
  "main.c"
)
target_link_libraries ("main" ${CMAKE_LIBXML2_LIBRARIES})
