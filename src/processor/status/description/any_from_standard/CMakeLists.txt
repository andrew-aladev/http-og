include (GenerateDataFromRegistry)
generate_data_from_registry (
  "${PROJECT_SOURCE_DIR}/registry/http-status-codes.xml"
  "//record/description"
  "alphabet"
)

if (DEFINED CMAKE_ALPHABET)
  configure_file ("${CMAKE_CURRENT_SOURCE_DIR}/options.c.in" "${CMAKE_CURRENT_SOURCE_DIR}/options.c")
endif ()

include (GenerateGeneric)
generate_generic ("STATUS_DESCRIPTION_ANY_FROM_STANDARD")
