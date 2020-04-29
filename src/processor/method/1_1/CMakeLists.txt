# include (GenerateRegistry)
# generate_registry ("${PROJECT_SOURCE_DIR}/registry/http-methods.xml" "//record/value" "constants")

# configure_file ("${CMAKE_CURRENT_SOURCE_DIR}/options.c.in" "${CMAKE_CURRENT_SOURCE_DIR}/options.c")

include (GenerateConstants)
generate_constants ("METHOD_1_1")
