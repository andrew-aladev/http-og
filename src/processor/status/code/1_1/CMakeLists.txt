include (GenerateConstantsFromRegistry)
generate_constants_from_registry (
  "${PROJECT_SOURCE_DIR}/registry/http-status-codes.xml"
  "//record[not(./description[contains(text(),'Unassigned')])]/value"
)

if (DEFINED CMAKE_CONSTANTS)
  configure_file ("${CMAKE_CURRENT_SOURCE_DIR}/options.c.in" "${CMAKE_CURRENT_SOURCE_DIR}/options.c")
endif ()

include (GenerateConstants)
generate_constants ("STATUS_CODE_1_1")
