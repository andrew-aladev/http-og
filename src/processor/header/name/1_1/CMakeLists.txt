set (PREFIX "HEADER_NAME_1_1")

include (GenerateConstantsFromRegistry)
generate_constants_from_registry (
  ${PREFIX}
  "${PROJECT_SOURCE_DIR}/registry/message-headers.xml"
  "//registry[@id='perm-headers' or @id='prov-headers']/record[./protocol[contains(text(),'http')]]/value"
)

if (DEFINED CMAKE_CONSTANTS)
  configure_file ("${CMAKE_CURRENT_SOURCE_DIR}/options.c.in" "${CMAKE_CURRENT_SOURCE_DIR}/options.c")
endif ()

include (GenerateConstants)
generate_constants (${PREFIX})
