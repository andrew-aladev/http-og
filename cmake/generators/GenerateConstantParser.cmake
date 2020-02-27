function (generate_constant_parser PREFIX INCLUDE_DIRECTORIES)
  set (OUTPUT_PREFIX "CMAKE_${PREFIX}_CONSTANT_PARSER")
  if (DEFINED ${OUTPUT_PREFIX})
    return ()
  endif ()

  string (TOLOWER ${PREFIX} PREFIX_LOWER_CASE)

  set (BINARY_DIR "${PROJECT_BINARY_DIR}/CMakeTmp/generator_${PREFIX_LOWER_CASE}_constant_parser")
  set (SOURCE_DIR "${PROJECT_SOURCE_DIR}/cmake/generators/constant_parser")
  set (NAME "cmake_generator_${PREFIX_LOWER_CASE}_constant_parser")

  set (MESSAGE_PREFIX "${PREFIX_LOWER_CASE} constant parser")

  try_compile (
    COMPILE_RESULT ${BINARY_DIR} ${SOURCE_DIR} ${NAME}
    CMAKE_FLAGS
      "-DCMAKE_VERBOSE_MAKEFILE=${CMAKE_VERBOSE_MAKEFILE}"
      "-DINCLUDE_DIRECTORIES=${INCLUDE_DIRECTORIES}"
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

    list (GET RUN_OUTPUT 0 CONSTANT)
    list (GET RUN_OUTPUT 1 MIN_STATE_TYPE)

    # if (RUN_RESULT EQUAL 0)
    #   set (${OUTPUT_VARIABLE} ${RUN_OUTPUT} PARENT_SCOPE)
    #   message (STATUS "${MESSAGE_PREFIX} - generated")
    # else ()
    #   unset (${OUTPUT_VARIABLE} PARENT_SCOPE)
    #   message (STATUS "${MESSAGE_PREFIX} - failed to generate, using default")
    # endif ()
  else ()
    # unset (${OUTPUT_VARIABLE} PARENT_SCOPE)
    # message (STATUS "${MESSAGE_PREFIX} - compilation failed, using default")
  endif ()

  FILE (REMOVE_RECURSE ${BINARY_DIR})

  # mark_as_advanced (${OUTPUT_VARIABLE})
endfunction ()
