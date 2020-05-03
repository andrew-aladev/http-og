set (PREFIX "STATUS_DESCRIPTION_1_1")

include (GenerateConstantsFromRegistry)
generate_constants_from_registry (
  ${PREFIX}
  "${PROJECT_SOURCE_DIR}/registry/http-status-codes.xml"
  "//record/description[not(contains(text(),'Unassigned'))]"
  "${PROJECT_SOURCE_DIR}/registry/http-warn-codes.xml"
  "//record/description"
)

if (DEFINED CMAKE_CONSTANTS)
  configure_file ("${CMAKE_CURRENT_SOURCE_DIR}/options.c.in" "${CMAKE_CURRENT_SOURCE_DIR}/options.c")
endif ()

include (GenerateConstants)
generate_constants (${PREFIX})
