function (cmake_check_libxml2)
  if (DEFINED LIBXML2_FOUND)
    return ()
  endif ()

  find_package (LIBXML2 REQUIRED)

  include (GetVerboseFlags)
  cmake_get_verbose_flags ()

  include (CheckC11)
  cmake_check_c11 ()

  include (CheckRunnable)
  cmake_check_runnable ()

  set (BINARY_DIR "${PROJECT_BINARY_DIR}/CMakeTmp/check_LIBXML2")
  set (SOURCE_DIR "${PROJECT_SOURCE_DIR}/cmake/checks/LIBXML2")
  set (NAME "cmake_check_libxml2")

  set (MESSAGE_PREFIX "Status of XML2 support")

  try_compile (
    CHECK_RESULT ${BINARY_DIR} ${SOURCE_DIR} ${NAME}
    CMAKE_FLAGS
      "-DCMAKE_C_FLAGS=${CMAKE_C_FLAGS} ${CMAKE_VERBOSE_C_FLAGS} ${CMAKE_C11_C_FLAGS} ${CMAKE_WERROR_C_FLAGS}"
      "-DCMAKE_VERBOSE_MAKEFILE=${CMAKE_VERBOSE_MAKEFILE}"
      "-DCMAKE_LIBXML2_INCLUDE_DIRS=${LIBXML2_INCLUDE_DIRS}"
      "-DCMAKE_LIBXML2_LIBRARIES=${LIBXML2_LIBRARIES}"
      "-DCMAKE_TRY_RUN=${CMAKE_CAN_RUN_EXE}"
    OUTPUT_VARIABLE CHECK_OUTPUT
  )
  if (CMAKE_VERBOSE_MAKEFILE)
    message (STATUS ${CHECK_OUTPUT})
  endif ()
  FILE (REMOVE_RECURSE ${BINARY_DIR})

  if (CHECK_RESULT)
    set (CMAKE_LIBXML2_WORKS true)
    message (STATUS "${MESSAGE_PREFIX} - working")
  else ()
    set (CMAKE_LIBXML2_WORKS false)
    message (FATAL_ERROR "${MESSAGE_PREFIX} - not working")
  endif ()

  set (CMAKE_LIBXML2_WORKS ${CMAKE_LIBXML2_WORKS} CACHE STRING "Status of XML2")

  mark_as_advanced (CMAKE_LIBXML2_WORKS)
endfunction ()
