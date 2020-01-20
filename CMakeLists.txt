# Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
#
# Distributed under The MIT License (MIT)
# See accompanying file LICENSE.txt
#---------------------------------------------------------------------------//

cmake_minimum_required(VERSION 3.15)

project(Chronos
        VERSION 1.0.0
        DESCRIPTION "Walltime measurement library.")

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN YES)

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

include(GNUInstallDirs)
add_library(Chronos SHARED)
target_sources(Chronos PRIVATE
        source/Timer.cpp
        source/Timers.cpp)
target_include_directories(Chronos PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_BINARY_DIR})

set_target_properties(Chronos PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set_target_properties(Chronos PROPERTIES
        SOVERSION 1
        VERSION 1.0.0)

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_compile_definitions(Chronos PRIVATE Chronos_EXPORT)
endif ()

include(GenerateExportHeader)
generate_export_header(Chronos)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
        SomeProjConfigVersion.cmake
        VERSION 1.0.0
        COMPATIBILITY SameMajorVersion
)

add_subdirectory(examples)
enable_testing()
add_subdirectory(tests)

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/examples/Chronos.dll
            COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:Chronos>" "$<TARGET_FILE_DIR:example_1>"
            VERBATIM)
    add_custom_target(copyddlexamples ALL
            DEPENDS ${CMAKE_BINARY_DIR}/examples/Chronos.dll Chronos
            VERBATIM)

    add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/tests/Chronos.dll
            COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:Chronos>" "$<TARGET_FILE_DIR:test_timer>"
            VERBATIM)
    add_custom_target(copyddltests ALL
            DEPENDS ${CMAKE_BINARY_DIR}/tests/Chronos.dll Chronos
            VERBATIM)
endif ()

install(TARGETS Chronos EXPORT ChronosTargets
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT Chronos_RunTime
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT Chronos_RunTime NAMELINK_COMPONENT Chronos_Development
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT Chronos_Development
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/
        TYPE INCLUDE
        FILES_MATCHING
        PATTERN *.hpp
        PERMISSIONS OWNER_READ OWNER_WRITE
        GROUP_READ
        WORLD_READ)

install(FILES ${CMAKE_BINARY_DIR}/chronos_export.h
        TYPE INCLUDE
        PERMISSIONS OWNER_READ OWNER_WRITE
        GROUP_READ
        WORLD_READ)

install(EXPORT ChronosTargets
        NAMESPACE Chronos::
        FILE ChronosConfig.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Chronos)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        ChronosConfigVersion.cmake
        VERSION 1.0.0
        COMPATIBILITY SameMajorVersion)

install(FILES ${PROJECT_BINARY_DIR}/source/ChronosConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Chronos)