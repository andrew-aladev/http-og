function (generate_methods REGISTRY_PATH)
  include (GetVerboseFlags)
  cmake_get_verbose_flags ()

  include (CheckC11)
  cmake_check_c11 ()

  set (BINARY_DIR "${PROJECT_BINARY_DIR}/CMakeTmp/generate_methods")
  set (SOURCE_DIR "${PROJECT_SOURCE_DIR}/cmake/generators/methods")
  set (NAME "cmake_generate_methods")

  set (OUTPUT_METHODS "CMAKE_METHODS")
  set (OUTPUT_METHODS_LENGTH "CMAKE_METHODS_LENGTH")

  set (MESSAGE_PREFIX "Methods")

  try_compile (
    COMPILE_RESULT ${BINARY_DIR} ${SOURCE_DIR} ${NAME}
    CMAKE_FLAGS
      "-DCMAKE_C_FLAGS=${CMAKE_VERBOSE_C_FLAGS} ${CMAKE_C11_C_FLAGS} ${CMAKE_WERROR_C_FLAGS}"
      "-DCMAKE_VERBOSE_MAKEFILE=${CMAKE_VERBOSE_MAKEFILE}"
    OUTPUT_VARIABLE COMPILE_OUTPUT
  )
  if (CMAKE_VERBOSE_MAKEFILE)
    message (STATUS ${COMPILE_OUTPUT})
  endif ()

  if (COMPILE_RESULT)
    execute_process (
      COMMAND "${BINARY_DIR}/main ${REGISTRY_PATH}"
      RESULT_VARIABLE RUN_RESULT
      OUTPUT_VARIABLE RUN_OUTPUT
    )

    if (RUN_RESULT EQUAL 0)
      list (GET RUN_OUTPUT 0 METHODS)
      set (${OUTPUT_METHODS} ${METHODS} PARENT_SCOPE)
      list (GET RUN_OUTPUT 1 METHODS_LENGTH)
      set (${OUTPUT_METHODS_LENGTH} ${METHODS_LENGTH} PARENT_SCOPE)
      message (STATUS "${MESSAGE_PREFIX} - generated")
    else ()
      unset (${OUTPUT_METHODS} PARENT_SCOPE)
      unset (${OUTPUT_METHODS_LENGTH} PARENT_SCOPE)
      message (STATUS "${MESSAGE_PREFIX} - failed to generate, using default")
    endif ()
  else ()
    unset (${OUTPUT_METHODS} PARENT_SCOPE)
    unset (${OUTPUT_METHODS_LENGTH} PARENT_SCOPE)
    message (STATUS "${MESSAGE_PREFIX} - compilation failed, using default")
  endif ()

  FILE (REMOVE_RECURSE ${BINARY_DIR})

  mark_as_advanced (
    ${OUTPUT_METHODS}
    ${OUTPUT_METHODS_LENGTH}
  )
endfunction ()
