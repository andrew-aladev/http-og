set (PREFIX "METHOD_1_1")

include (GenerateConstantsFromRegistry)
generate_constants_from_registry (
  ${PREFIX}
  "${PROJECT_SOURCE_DIR}/registry/http-methods.xml"
  "//record/value"
)

if (DEFINED CMAKE_CONSTANTS)
  configure_file ("${CMAKE_CURRENT_SOURCE_DIR}/options.c.in" "${CMAKE_CURRENT_SOURCE_DIR}/options.c")
endif ()

include (GenerateConstants)
generate_constants (${PREFIX})
