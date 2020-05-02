include (GenerateDataFromRegistry)
generate_data_from_registry (
  "${PROJECT_SOURCE_DIR}/registry/http-methods.xml"
  "//record/value"
  "alphabet"
)

if (DEFINED CMAKE_ALPHABET)
  configure_file ("${CMAKE_CURRENT_SOURCE_DIR}/options.c.in" "${CMAKE_CURRENT_SOURCE_DIR}/options.c")
endif ()

include (GenerateGeneric)
generate_generic ("METHOD_ANY_FROM_STANDARD")
