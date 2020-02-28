set (PARSER_PREFIX "METHOD_v0_9_STRICT")
string (TOLOWER ${PARSER_PREFIX} PARSER_PREFIX_LOWER_CASE)

include (GenerateParserFromConstant)
generate_parser_from_constant (${PARSER_PREFIX} ${PARSER_PREFIX_LOWER_CASE} ${CMAKE_CURRENT_SOURCE_DIR})

if (DEFINED CMAKE_PARSER_CONSTANT AND DEFINED CMAKE_PARSER_MIN_STATE_BITS)
  configure_file ("generated_parser.h.in" "${CMAKE_CURRENT_SOURCE_DIR}/generated_parser.h")
endif ()
