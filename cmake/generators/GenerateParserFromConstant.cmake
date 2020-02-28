function (generate_parser_from_constant PREFIX PREFIX_LOWER_CASE INCLUDE_PATH)
  set (OUTPUT_CONSTANT "CMAKE_PARSER_CONSTANT")
  set (OUTPUT_MIN_STATE_BITS "CMAKE_PARSER_MIN_STATE_BITS")

  set (BINARY_DIR "${PROJECT_BINARY_DIR}/CMakeTmp/generator_parser_from_constant")
  set (SOURCE_DIR "${PROJECT_SOURCE_DIR}/cmake/generators/parser_from_constant")
  set (NAME "cmake_generator_parser_from_constant")

  set (MESSAGE_PREFIX "${PREFIX_LOWER_CASE} parser from constant")

  try_compile (
    COMPILE_RESULT ${BINARY_DIR} ${SOURCE_DIR} ${NAME}
    CMAKE_FLAGS
      "-DCMAKE_VERBOSE_MAKEFILE=${CMAKE_VERBOSE_MAKEFILE}"
      "-DCMAKE_INCLUDE_PATH=${INCLUDE_PATH}"
    OUTPUT_VARIABLE COMPILE_OUTPUT
  )
  if (CMAKE_VERBOSE_MAKEFILE)
    message (STATUS ${COMPILE_OUTPUT})
  endif ()

  if (COMPILE_RESULT)
    execute_process (
      COMMAND "${BINARY_DIR}/main"
      RESULT_VARIABLE RUN_RESULT
      OUTPUT_VARIABLE RUN_OUTPUT
    )

    if (RUN_RESULT EQUAL 0)
      list (GET RUN_OUTPUT 0 CONSTANT)
      set (${OUTPUT_CONSTANT} ${CONSTANT} PARENT_SCOPE)
      list (GET RUN_OUTPUT 1 MIN_STATE_BITS)
      set (${OUTPUT_MIN_STATE_BITS} ${MIN_STATE_BITS} PARENT_SCOPE)
      message (STATUS "${MESSAGE_PREFIX} - generated")
    else ()
      unset (${OUTPUT_CONSTANT} PARENT_SCOPE)
      unset (${OUTPUT_MIN_STATE_BITS} PARENT_SCOPE)
      message (STATUS "${MESSAGE_PREFIX} - failed to generate, using default")
    endif ()
  else ()
    unset (${OUTPUT_CONSTANT} PARENT_SCOPE)
    unset (${OUTPUT_MIN_STATE_BITS} PARENT_SCOPE)
    message (STATUS "${MESSAGE_PREFIX} - compilation failed, using default")
  endif ()

  FILE (REMOVE_RECURSE ${BINARY_DIR})

  mark_as_advanced (${OUTPUT_CONSTANT} ${OUTPUT_MIN_STATE_BITS})
endfunction ()
