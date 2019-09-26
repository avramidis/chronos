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

add_compile_options("$<$<CONFIG:DEBUG>:${MY_DEBUG_OPTIONS}>")
add_compile_options("$<$<CONFIG:RELEASE>:${MY_RELEASE_OPTIONS}>")

add_library(Chronos SHARED)
target_sources(Chronos PRIVATE
        source/Timer.cpp
        source/Timers.cpp)
target_include_directories(Chronos PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(examples)