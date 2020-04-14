function (generate_constant_processor PREFIX PREFIX_LOWER_CASE TARGET_PATH GENERATOR_PATH)
  set (OUTPUT_CONSTANT_SYMBOLS "CMAKE_CONSTANT_SYMBOLS")
  set (OUTPUT_CONSTANT_LENGTH "CMAKE_CONSTANT_LENGTH")

  set (BINARY_DIR "${PROJECT_BINARY_DIR}/CMakeTmp/generate_constant_processor")
  set (SOURCE_DIR "${PROJECT_SOURCE_DIR}/cmake/generators/constant_processor")
  set (NAME "cmake_generate_constant_processor")

  set (MESSAGE_PREFIX "${PREFIX_LOWER_CASE} constant processor")

  try_compile (
    COMPILE_RESULT ${BINARY_DIR} ${SOURCE_DIR} ${NAME}
    CMAKE_FLAGS
      "-DCMAKE_VERBOSE_MAKEFILE=${CMAKE_VERBOSE_MAKEFILE}"
      "-DCMAKE_TARGET_PATH=${TARGET_PATH}"
      "-DCMAKE_GENERATOR_PATH=${GENERATOR_PATH}"
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
      list (GET RUN_OUTPUT 0 CONSTANT_SYMBOLS)
      set (${OUTPUT_CONSTANT_SYMBOLS} ${CONSTANT_SYMBOLS} PARENT_SCOPE)
      list (GET RUN_OUTPUT 1 CONSTANT_LENGTH)
      set (${OUTPUT_CONSTANT_LENGTH} ${CONSTANT_LENGTH} PARENT_SCOPE)
      message (STATUS "${MESSAGE_PREFIX} - generated")
    else ()
      unset (${OUTPUT_CONSTANT_SYMBOLS} PARENT_SCOPE)
      unset (${OUTPUT_CONSTANT_LENGTH} PARENT_SCOPE)
      message (STATUS "${MESSAGE_PREFIX} - failed to generate, using default")
    endif ()
  else ()
    unset (${OUTPUT_CONSTANT_SYMBOLS} PARENT_SCOPE)
    unset (${OUTPUT_CONSTANT_LENGTH} PARENT_SCOPE)
    message (STATUS "${MESSAGE_PREFIX} - compilation failed, using default")
  endif ()

  FILE (REMOVE_RECURSE ${BINARY_DIR})

  mark_as_advanced (
    ${OUTPUT_CONSTANT_SYMBOLS}
    ${OUTPUT_CONSTANT_LENGTH}
  )
endfunction ()
