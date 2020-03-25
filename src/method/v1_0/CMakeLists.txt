set (PARSER_PREFIX "METHOD_v1_0")
string (TOLOWER ${PARSER_PREFIX} PARSER_PREFIX_LOWER_CASE)

include (GenerateParserFromConstants)
generate_parser_from_constants (${PARSER_PREFIX} ${PARSER_PREFIX_LOWER_CASE} ${CMAKE_CURRENT_SOURCE_DIR})

if (DEFINED CMAKE_PARSER_CONSTANTS)
  set (PARSER_FILE_NAME "parser")
  file (RELATIVE_PATH PARSER_PATH ${CMAKE_CURRENT_SOURCE_DIR} "${PROJECT_SOURCE_DIR}/src/parser/constants")

  configure_file ("${PARSER_PATH}/main.h.in" "${CMAKE_CURRENT_SOURCE_DIR}/${PARSER_FILE_NAME}.h")
  configure_file ("${PARSER_PATH}/main.c.in" "${CMAKE_CURRENT_SOURCE_DIR}/${PARSER_FILE_NAME}.c")
endif ()
