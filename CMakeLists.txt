# Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
#
# Distributed under The MIT License (MIT)
# See accompanying file LICENSE.txt
#---------------------------------------------------------------------------//

cmake_minimum_required(VERSION 3.15)

project(Chronos
        VERSION 1.0.0
        DESCRIPTION "Walltime measurement library.")

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN YES)

# Project settings
include(cmake/StandardProjectSettings.cmake)
add_library(chronos_project_options INTERFACE)
target_compile_features(chronos_project_options INTERFACE cxx_std_17)

# Standard compiler warnings
add_library(chronos_project_warnings INTERFACE)
include(cmake/CompilerWarnings.cmake)
set_project_warnings(chronos_project_warnings)

add_subdirectory(source)
include(GenerateExportHeader)
generate_export_header(Chronos)

option(CHRONOS_ENABLE_EXAMPLES "Enable examples" OFF)
option(CHRONOS_ENABLE_TESTS "Enable tests" OFF)

if (CHRONOS_ENABLE_EXAMPLES)
    add_subdirectory(examples)
endif ()

if (CHRONOS_ENABLE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif ()