set (PREFIX "METHOD_v1_1")
string (TOLOWER ${PREFIX} PREFIX_LOWER_CASE)

include (GenerateConstantsProcessor)
generate_constants_processor (${PREFIX} ${PREFIX_LOWER_CASE} ${CMAKE_CURRENT_SOURCE_DIR})

if (DEFINED CMAKE_CONSTANTS_LENGTH)
  set (FILE_NAME "processor")
  file (RELATIVE_PATH SOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR} "${PROJECT_SOURCE_DIR}/src")
  set (GENERATOR_PATH "${SOURCE_PATH}/processor/generator/constants")

  configure_file ("${GENERATOR_PATH}/main.h.in" "${CMAKE_CURRENT_SOURCE_DIR}/${FILE_NAME}.h")
  configure_file ("${GENERATOR_PATH}/main.c.in" "${CMAKE_CURRENT_SOURCE_DIR}/${FILE_NAME}.c")
endif ()
