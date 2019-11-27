# Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
#
# Distributed under The MIT License (MIT)
# See accompanying file LICENSE.txt
#---------------------------------------------------------------------------//

cmake_minimum_required(VERSION 3.15)

project(tests)

add_executable(test_timer test_timer.cpp)
target_include_directories(test_timer PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/external/include)
target_link_libraries(test_timer PRIVATE Chronos)
add_test(NAME test_timer COMMAND test_timer)