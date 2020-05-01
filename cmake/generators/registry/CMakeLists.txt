cmake_minimum_required (VERSION 3.9)
project ("cmake_generate_methods" "C")

find_package (LibXML2 REQUIRED)

include (CheckLibXML2)
cmake_check_libxml2 ()

include ("../toolchain.cmake")

include_directories (${LIBXML2_INCLUDE_DIRS})

add_executable (
  "main"
  "alphabet.c"
  "constants.c"
  "file.c"
  "main.c"
)
target_link_libraries ("main" ${LIBXML2_LIBRARIES})
