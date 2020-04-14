function (generate_constant PREFIX)
  string (TOLOWER ${PREFIX} PREFIX_LOWER_CASE)

  set (TARGET_PATH ${CMAKE_CURRENT_SOURCE_DIR})
  set (GENERATOR_PATH "${SOURCE_PATH}/processor/generator/constant")

  include (GenerateConstantProcessor)
  generate_constant_processor (${PREFIX} ${PREFIX_LOWER_CASE} ${TARGET_PATH} ${GENERATOR_PATH})

  if (DEFINED CMAKE_CONSTANT_SYMBOLS)
    set (FILE_NAME "processor")
    file (RELATIVE_PATH RELATIVE_SOURCE_PATH ${TARGET_PATH} ${SOURCE_PATH})

    configure_file ("${GENERATOR_PATH}/main.h.in" "${TARGET_PATH}/${FILE_NAME}.h")
    configure_file ("${GENERATOR_PATH}/main.c.in" "${TARGET_PATH}/${FILE_NAME}.c")
  endif ()
endfunction ()
