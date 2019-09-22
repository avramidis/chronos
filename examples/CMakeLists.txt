# Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
#
# Distributed under The MIT License (MIT)
# See accompanying file LICENSE.txt
#---------------------------------------------------------------------------//

cmake_minimum_required(VERSION 3.13.4)

add_executable(example_1)
target_sources(example_1 PRIVATE example_1.cpp)
target_include_directories(example_1 PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(example_1 PRIVATE Chrono)