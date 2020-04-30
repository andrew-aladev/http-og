function (generate_registry FILE_PATH XPATH MODE)
  include (GetVerboseFlags)
  cmake_get_verbose_flags ()

  include (CheckC11)
  cmake_check_c11 ()

  set (BINARY_DIR "${PROJECT_BINARY_DIR}/CMakeTmp/generate_registry")
  set (SOURCE_DIR "${PROJECT_SOURCE_DIR}/cmake/generators/registry")
  set (NAME "cmake_generate_registry")

  set (OUTPUT_ALPHABET "CMAKE_ALPHABET")
  set (OUTPUT_CONSTANTS "CMAKE_CONSTANTS")

  get_filename_component (REGISTRY_NAME ${FILE_PATH} NAME)
  set (MESSAGE_PREFIX "Registry ${REGISTRY_NAME}, xpath ${XPATH}, mode ${MODE}")

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
      COMMAND "${BINARY_DIR}/main ${FILE_PATH} ${XPATH} ${MODE}"
      RESULT_VARIABLE RUN_RESULT
      OUTPUT_VARIABLE RUN_OUTPUT
    )

    if (RUN_RESULT EQUAL 0)
      if (MODE STREQUAL "alphabet")
        set (${OUTPUT_ALPHABET} ${RUN_OUTPUT} PARENT_SCOPE)
      else ()
        set (${OUTPUT_CONSTANTS} ${RUN_OUTPUT} PARENT_SCOPE)
      endif ()

      message (STATUS "${MESSAGE_PREFIX} - generated")

    else ()
      unset (${OUTPUT_ALPHABET} PARENT_SCOPE)
      unset (${OUTPUT_CONSTANTS} PARENT_SCOPE)
      message (STATUS "${MESSAGE_PREFIX} - failed to generate, using default")
    endif ()

  else ()
    unset (${OUTPUT_ALPHABET} PARENT_SCOPE)
    unset (${OUTPUT_CONSTANTS} PARENT_SCOPE)
    message (STATUS "${MESSAGE_PREFIX} - compilation failed, using default")
  endif ()

  FILE (REMOVE_RECURSE ${BINARY_DIR})

  mark_as_advanced (
    ${OUTPUT_ALPHABET}
    ${OUTPUT_CONSTANTS}
  )
endfunction ()
