cmake_minimum_required(VERSION 3.10)
project(osc-dependencies)

# -------------- gather user-facing build cache vars ---------------- #

set(OSCDEPS_GET_QTBASE ON CACHE BOOL "enable getting qtbase")
set(OSCDEPS_BUILD_ALWAYS OFF CACHE BOOL "set BUILD_ALWAYS on all dependency targets, useful when editing dependencies")

include(ExternalProject)  # ExternalProject_Add
include(GNUInstallDirs)  # CMAKE_INSTALL_LIBDIR

# setup `OSCDEPS_DEPENDENCY_CMAKE_ARGS`
#
# these are cache args that should be forwarded to external dependency projects
if(TRUE)
    set(OSCDEPS_FORWARDED_VARS

        CMAKE_CXX_COMPILER
        CMAKE_C_COMPILER
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_MINSIZEREL
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_RELWITHDEBINFO
        CMAKE_C_FLAGS
        CMAKE_C_FLAGS_DEBUG
        CMAKE_C_FLAGS_MINSIZEREL
        CMAKE_C_FLAGS_RELEASE
        CMAKE_C_FLAGS_RELWITHDEBINFO
        CMAKE_BUILD_TYPE
        CMAKE_INSTALL_PREFIX
    )
    foreach(OSCDEPS_FORWARDED_VAR IN LISTS OSCDEPS_FORWARDED_VARS)
        list(APPEND OSCDEPS_DEPENDENCY_CMAKE_ARGS -D${OSCDEPS_FORWARDED_VAR}:STRING=${${OSCDEPS_FORWARDED_VAR}})
    endforeach()
    unset(OSCDEPS_FORWARDED_VARS)
endif()

if(${OSCDEPS_GET_QTBASE})
    ExternalProject_Add(qtbase
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/qtbase
        BUILD_ALWAYS ${OSCDEPS_BUILD_ALWAYS}
        CMAKE_CACHE_ARGS
            ${OSCDEPS_DEPENDENCY_CMAKE_ARGS}
            -DFEATURE_androiddeployqt:BOOL=OFF
	    -DFEATURE_brotli:BOOL=OFF
            -DFEATURE_dbus:BOOL=OFF
            -DFEATURE_doubleconversion:BOOL=ON
            -DFEATURE_freetype:BOOL=OFF
            -DFEATURE_glib:BOOL=OFF
            -DFEATURE_harfbuzz:BOOL=ON
            -DFEATURE_icu:BOOL=OFF
            -DFEATURE_jpeg:BOOL=ON
            -DFEATURE_macdeployqt:BOOL=OFF
            -DFEATURE_pcre2:BOOL=ON
            -DFEATURE_pdf:BOOL=OFF
            -DFEATURE_png:BOOL=ON
            -DFEATURE_printsupport:BOOL=OFF
            -DFEATURE_qmake:BOOL=OFF
	    -DFEATURE_schannel:BOOL=OFF
            -DFEATURE_sql:BOOL=OFF
            -DFEATURE_system_doubleconversion:BOOL=OFF
            -DFEATURE_system_jpeg:BOOL=OFF
            -DFEATURE_system_pcre2:BOOL=OFF
            -DFEATURE_system_png:BOOL=OFF
            -DFEATURE_system_zlib:BOOL=OFF
            -DFEATURE_testlib:BOOL=OFF
            -DFEATURE_windeployqt:BOOL=OFF
            -DINPUT_openssl:STRING=no
            -DQT_BUILD_BENCHMARKS:BOOL=OFF
            -DQT_BUILD_EXAMPLES:BOOL=OFF
            -DQT_BUILD_EXAMPLES_BY_DEFAULT:BOOL=OFF
            -DQT_BUILD_MANUAL_TESTS:BOOL=OFF
            -DQT_BUILD_TESTS:BOOL=OFF
            -DQT_BUILD_TESTS_BY_DEFAULT:BOOL=OFF
            -DQT_BUILD_TOOLS_BY_DEFAULT:BOOL=OFF
            -DQT_USE_VCPKG:BOOL=OFF
    )
endif()

