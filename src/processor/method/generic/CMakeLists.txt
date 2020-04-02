set (PREFIX "METHOD_GENERIC")
string (TOLOWER ${PREFIX} PREFIX_LOWER_CASE)

include (GenerateGenericProcessor)
generate_generic_processor (${PREFIX} ${PREFIX_LOWER_CASE} ${CMAKE_CURRENT_SOURCE_DIR})

if (DEFINED CMAKE_ALLOWED_BYTES)
  set (FILE_NAME "processor")
  file (RELATIVE_PATH SOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR} "${PROJECT_SOURCE_DIR}/src")
  set (GENERATOR_PATH "${SOURCE_PATH}/processor/generator/generic")

  configure_file ("${GENERATOR_PATH}/main.h.in" "${CMAKE_CURRENT_SOURCE_DIR}/${FILE_NAME}.h")
  configure_file ("${GENERATOR_PATH}/main.c.in" "${CMAKE_CURRENT_SOURCE_DIR}/${FILE_NAME}.c")
endif ()
