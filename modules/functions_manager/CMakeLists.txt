# ==============================================================================
# Copyright (c) 2016-present Allan CORNET (Nelson)
# ==============================================================================
# This file is part of the Nelson.
# =============================================================================
# LICENCE_BLOCK_BEGIN SPDX-License-Identifier: LGPL-3.0-or-later
# LICENCE_BLOCK_END
# ==============================================================================
set(module_name functions_manager)
set(module_library_name nlsFunctions_manager)
set(module_library_builtin_name ${module_library_name}_builtin)
# ==============================================================================
file(GLOB FUNCTIONS_MANAGER
     "${CMAKE_CURRENT_SOURCE_DIR}/src/cpp/*.cpp")
list(FILTER FUNCTIONS_MANAGER EXCLUDE REGEX
     "${CMAKE_CURRENT_SOURCE_DIR}/src/cpp/dllMain.cpp")
# ==============================================================================
add_library(${module_library_name} ${FUNCTIONS_MANAGER})
target_include_directories(
    ${module_library_name}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/include>
    $<INSTALL_INTERFACE:include/nelson/${module_name}>
)
target_include_directories(
    ${module_library_name}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../mex/src/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../interpreter/src/include)
# ==============================================================================
target_link_libraries(
  ${module_library_name}
  nlsInterpreter
)
# ==============================================================================
file(GLOB FUNCTIONS_MANAGER_BUILTIN
     "${CMAKE_CURRENT_SOURCE_DIR}/builtin/cpp/*.cpp")
list(FILTER FUNCTIONS_MANAGER_BUILTIN EXCLUDE REGEX
     "${CMAKE_CURRENT_SOURCE_DIR}/builtin/cpp/dllMain.cpp")
# ==============================================================================
add_library(${module_library_builtin_name} ${FUNCTIONS_MANAGER_BUILTIN})
target_include_directories(
    ${module_library_builtin_name}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/builtin/include>
    $<INSTALL_INTERFACE:include/nelson/${module_name}>
)
target_include_directories(
    ${module_library_builtin_name}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../mex/src/include
)
# ==============================================================================
target_link_libraries(
  ${module_library_builtin_name}
  nlsCharacters_encoding
  nlsError_manager
  nlsStream_manager
  nlsInterpreter
  nlsTypes
  nlsApi_nelson
  nlsI18n
  nlsCommons
  nlsFiles_folders_functions)
# ==============================================================================
file(GLOB FUNCTIONS_MANAGER_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/builtin/include/*.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/builtin/include/*.h")
set_target_properties(
  ${module_library_builtin_name}
  PROPERTIES
    VERSION
    ${Nelson_VERSION_MAJOR}.${Nelson_VERSION_MINOR}.${Nelson_VERSION_MAINTENANCE}
    SOVERSION ${Nelson_VERSION_MAJOR}
    PUBLIC_HEADER "${FUNCTIONS_MANAGER_HEADER}"
)
# ==============================================================================
include(GNUInstallDirs)
install(
    TARGETS ${module_library_builtin_name} ${module_library_name}
    EXPORT ${PROJECT_NAME}-targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION
    ${CMAKE_INSTALL_INCLUDEDIR}/nelson/${module_name}
)
# ==============================================================================
