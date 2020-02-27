cmake_minimum_required (VERSION 3.9)
project ("oghttp" "C")

if (PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message (FATAL_ERROR "In-source builds are not allowed")
endif ()

set (OGHTTP_VERSION "0.1.0")

if (NOT DEFINED CMAKE_INSTALL_LIBDIR)
  set (CMAKE_INSTALL_LIBDIR "lib" CACHE PATH "output directory for libraries")
endif ()
if (NOT DEFINED CMAKE_INSTALL_INCLUDEDIR)
  set (CMAKE_INSTALL_INCLUDEDIR "include" CACHE PATH "output directory for include files")
endif ()
if (NOT DEFINED CMAKE_INSTALL_BINDIR)
  set (CMAKE_INSTALL_BINDIR "bin" CACHE PATH "output directory for binaries")
endif ()

if (NOT DEFINED OGHTTP_TARGET)
  set (OGHTTP_TARGET ${PROJECT_NAME})
endif ()

option (OGHTTP_SHARED   "build shared libs" ON)
option (OGHTTP_STATIC   "build static libs" OFF)
option (OGHTTP_TESTS    "build tests"       ON)
option (OGHTTP_COVERAGE "enable coverage"   OFF)
option (OGHTTP_EXAMPLES "build examples"    OFF)

if (NOT OGHTTP_SHARED AND NOT OGHTTP_STATIC)
  message (FATAL_ERROR "Please enable building of shared or static libraries.")
endif ()

set (
  CMAKE_MODULE_PATH
  "${PROJECT_SOURCE_DIR}/cmake/checks"
  "${PROJECT_SOURCE_DIR}/cmake/functions"
  "${PROJECT_SOURCE_DIR}/cmake/generators"
)

include (GetVerboseFlags)
cmake_get_verbose_flags ()

include (GetPipeFlags)
cmake_get_pipe_flags ()

if (OGHTTP_COVERAGE)
  include (GetCoverageFlags)
  cmake_get_coverage_flags ()
endif ()

include (CheckC11)
cmake_check_c11 ()

include (CheckIPO)
cmake_check_ipo ()

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_VERBOSE_C_FLAGS} ${CMAKE_PIPE_C_FLAGS} ${CMAKE_C11_C_FLAGS}")

if (OGHTTP_COVERAGE)
  set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_COVERAGE_C_FLAGS}")
endif ()

if (NOT DEFINED CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "")
  set (CMAKE_BUILD_TYPE "DEBUG")
endif ()

set (CMAKE_C_FLAGS_DEBUG         "-O0 -g" CACHE STRING "debug cflags" FORCE)
set (CMAKE_C_FLAGS_RELEASE       "-O2"    CACHE STRING "release cflags" FORCE)
set (CMAKE_C_FLAGS_RELEASE_EMBED "-Os"    CACHE STRING "release embed cflags" FORCE)

if (CMAKE_HAVE_IPO)
  set (CMAKE_INTERPROCEDURAL_OPTIMIZATION true CACHE BOOL "status of IPO")
else ()
  set (CMAKE_INTERPROCEDURAL_OPTIMIZATION false CACHE BOOL "status of IPO")
endif ()

if (OGHTTP_TESTS)
  enable_testing ()
endif ()

add_subdirectory ("src")

include (CPackConfig.cmake)
include (CPack)
