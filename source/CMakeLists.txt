# Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
#
# Distributed under The MIT License (MIT)
# See accompanying file LICENSE.txt
#---------------------------------------------------------------------------//

include(GNUInstallDirs)
add_library(Chronos SHARED)
target_sources(Chronos PRIVATE
        Timer.cpp
        Timers.cpp)

target_include_directories(Chronos PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>/..
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

set_target_properties(Chronos PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_compile_definitions(Chronos PRIVATE Chronos_EXPORT)
endif ()

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    if (CHRONOS_ENABLE_EXAMPLES)
        add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/examples/Chronos.dll
                COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:Chronos>" "$<TARGET_FILE_DIR:example_1>"
                VERBATIM)
        add_custom_target(copyddlexamples ALL
                DEPENDS ${CMAKE_BINARY_DIR}/examples/Chronos.dll Chronos
                VERBATIM)
    endif ()

    if (CHRONOS_ENABLE_TESTS)
        add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/tests/Chronos.dll
                COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:Chronos>" "$<TARGET_FILE_DIR:test_timer>"
                VERBATIM)
        add_custom_target(copyddltests ALL
                DEPENDS ${CMAKE_BINARY_DIR}/tests/Chronos.dll Chronos
                VERBATIM)
    endif ()
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
        VERSION ${CMAKE_PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion)

install(FILES ${PROJECT_BINARY_DIR}/ChronosConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Chronos)