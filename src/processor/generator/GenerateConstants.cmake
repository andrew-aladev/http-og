function (generate_constants PREFIX)
  string (TOLOWER ${PREFIX} PREFIX_LOWER_CASE)

  set (GENERATOR_PATH "${SOURCE_PATH}/processor/generator/constants")
  set (TARGET_PATH ${CMAKE_CURRENT_SOURCE_DIR})

  include (GenerateConstantsProcessor)
  generate_constants_processor (${PREFIX} ${PREFIX_LOWER_CASE} ${TARGET_PATH})

  if (DEFINED CMAKE_CONSTANTS_LENGTH)
    file (RELATIVE_PATH RELATIVE_SOURCE_PATH ${TARGET_PATH} ${SOURCE_PATH})

    configure_file ("${GENERATOR_PATH}/main.h.in" "${TARGET_PATH}/main.h")
    configure_file ("${GENERATOR_PATH}/main.c.in" "${TARGET_PATH}/main.c")
  endif ()
endfunction ()
