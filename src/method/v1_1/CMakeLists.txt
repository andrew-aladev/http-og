set (PARSER_PREFIX "METHOD_v1_1")
string (TOLOWER ${PARSER_PREFIX} PARSER_PREFIX_LOWER_CASE)

include (GenerateParserFromConstants)
generate_parser_from_constants (${PARSER_PREFIX} ${PARSER_PREFIX_LOWER_CASE} ${CMAKE_CURRENT_SOURCE_DIR})

if (DEFINED CMAKE_PARSER_CONSTANTS)
  configure_file ("parser.h.in" "${CMAKE_CURRENT_SOURCE_DIR}/parser.h")
endif ()
