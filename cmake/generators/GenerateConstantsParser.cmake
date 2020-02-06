function (generate_constants_parser TARGET OUTPUT_VARIABLE)
  if (DEFINED ${OUTPUT_VARIABLE})
    return ()
  endif ()

  set (BINARY_DIR "${PROJECT_BINARY_DIR}/CMakeTmp/generator_constants_parser")
  set (SOURCE_DIR "${PROJECT_SOURCE_DIR}/cmake/generators/constants_parser")
  set (NAME "cmake_generator_constants_parser")

  set (MESSAGE_PREFIX "Constants parser for ${TARGET}")

  try_compile (
    COMPILE_RESULT ${BINARY_DIR} ${SOURCE_DIR} ${NAME}
    CMAKE_FLAGS "-DCMAKE_VERBOSE_MAKEFILE=${CMAKE_VERBOSE_MAKEFILE}"
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
      set (${OUTPUT_VARIABLE} ${RUN_OUTPUT} PARENT_SCOPE)
      message (STATUS "${MESSAGE_PREFIX} - generated")
    else ()
      unset (${OUTPUT_VARIABLE} PARENT_SCOPE)
      message (STATUS "${MESSAGE_PREFIX} - failed to generate, using default")
    endif ()
  else ()
    unset (${OUTPUT_VARIABLE} PARENT_SCOPE)
    message (STATUS "${MESSAGE_PREFIX} - compilation failed, using default")
  endif ()

  FILE (REMOVE_RECURSE ${BINARY_DIR})

  mark_as_advanced (${OUTPUT_VARIABLE})
endfunction ()
