include (GenerateDataFromRegistry)
generate_data_from_registry (
  "${PROJECT_SOURCE_DIR}/registry/http-methods.xml"
  "http://www.iana.org/assignments"
  "//ns:record/ns:value"
  "constants"
)

if (DEFINED CMAKE_CONSTANTS)
  configure_file ("${CMAKE_CURRENT_SOURCE_DIR}/options.c.in" "${CMAKE_CURRENT_SOURCE_DIR}/options.c")
endif ()

include (GenerateConstants)
generate_constants ("METHOD_1_1")
