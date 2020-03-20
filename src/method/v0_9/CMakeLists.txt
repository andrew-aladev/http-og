set (PARSER_PREFIX "METHOD_v0_9")
string (TOLOWER ${PARSER_PREFIX} PARSER_PREFIX_LOWER_CASE)

include (GenerateParserFromConstant)
generate_parser_from_constant (${PARSER_PREFIX} ${PARSER_PREFIX_LOWER_CASE} ${CMAKE_CURRENT_SOURCE_DIR})

if (DEFINED CMAKE_PARSER_CONSTANT)
  configure_file ("parser.h.in" "${CMAKE_CURRENT_SOURCE_DIR}/parser.h")
endif ()
