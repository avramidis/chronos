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

set(CMAKE_CXX_STANDARD 14)

add_library(Chrono SHARED)
target_sources(Chrono PRIVATE
        source/Timer.cpp)
target_include_directories(Chrono PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(examples)