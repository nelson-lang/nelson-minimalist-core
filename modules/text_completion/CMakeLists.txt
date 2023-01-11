# ==============================================================================
# Copyright (c) 2016-present Allan CORNET (Nelson)
# ==============================================================================
# This file is part of the Nelson.
# =============================================================================
# LICENCE_BLOCK_BEGIN SPDX-License-Identifier: LGPL-3.0-or-later
# LICENCE_BLOCK_END
# ==============================================================================
set(module_name text_completion)
set(module_library_name nlsText_completion)
# ==============================================================================
# ==============================================================================
file(GLOB TEXT_COMPLETION_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/cpp/*.cpp")
list(FILTER TEXT_COMPLETION_SRC EXCLUDE REGEX
     "${CMAKE_CURRENT_SOURCE_DIR}/src/cpp/dllMain.cpp")
# ==============================================================================
add_library(${module_library_name} SHARED ${TEXT_COMPLETION_SRC})
target_include_directories(
    ${module_library_name}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/include>
    $<INSTALL_INTERFACE:include/nelson/${module_name}>
)
target_include_directories(
  ${module_library_name}
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/../commons/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../characters_encoding/no-src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../functions_manager/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../interpreter/src/include
)
target_link_libraries(
  ${module_library_name}
  nlsCharacters_encoding
  nlsCommons
  nlsFunctions_manager
  nlsInterpreter)
# ==============================================================================
file(GLOB TEXT_COMPLETION_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/src/include/*.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/include/*.h")
set_target_properties(
  ${module_library_name}
  PROPERTIES
    VERSION
    ${Nelson_VERSION_MAJOR}.${Nelson_VERSION_MINOR}.${Nelson_VERSION_MAINTENANCE}
    SOVERSION ${Nelson_VERSION_MAJOR}
    PUBLIC_HEADER "${TEXT_COMPLETION_HEADER}"
)
# ==============================================================================
include(GNUInstallDirs)
install(
    TARGETS ${module_library_name}
    EXPORT ${PROJECT_NAME}-targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION
    ${CMAKE_INSTALL_INCLUDEDIR}/nelson/${module_name}
)
# ==============================================================================
