# Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
#
# Distributed under The MIT License (MIT)
# See accompanying file LICENSE.txt
#---------------------------------------------------------------------------//

cmake_minimum_required(VERSION 3.13.4)

project(Chronos
        VERSION 1.00
        DESCRIPTION "Walltime measurement library.")

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_STANDARD 17)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    message(STATUS "USING OPTIONS FOR GNU COMPILER")
    set(MY_DEBUG_OPTIONS "-O0;-g;-Wall;-Wextra;-Wpedantic")
    set(MY_RELEASE_OPTIONS "-O3;-Wall;-Wextra;-Wpedantic")
endif ()

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    message(STATUS "USING OPTIONS FOR MSVC COMPILER")
    set(MY_DEBUG_OPTIONS "/Wall /wd4710")
    set(MY_RELEASE_OPTIONS "/Wall;/wd4710;/wd4711;/wd4514")
endif ()

add_compile_options("$<$<CONFIG:DEBUG>:${MY_DEBUG_OPTIONS}>")
add_compile_options("$<$<CONFIG:RELEASE>:${MY_RELEASE_OPTIONS}>")

add_library(Chronos SHARED)
target_sources(Chronos PRIVATE
        source/Timer.cpp
        source/Timers.cpp)
target_include_directories(Chronos PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_compile_definitions(Chronos PRIVATE Chronos_EXPORT)
endif ()

add_subdirectory(examples)
enable_testing()
add_subdirectory(tests)

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/examples/Chronos.dll
            COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/Chronos.dll ${CMAKE_BINARY_DIR}/examples/
            VERBATIM)
    add_custom_target(copyddlexamples ALL
            DEPENDS ${CMAKE_BINARY_DIR}/examples/Chronos.dll Chronos
            VERBATIM)

    add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/tests/Chronos.dll
            COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/Chronos.dll ${CMAKE_BINARY_DIR}/tests/
            VERBATIM)
    add_custom_target(copyddltests ALL
            DEPENDS ${CMAKE_BINARY_DIR}/tests/Chronos.dll Chronos
            VERBATIM)
endif ()