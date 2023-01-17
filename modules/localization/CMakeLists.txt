# ==============================================================================
# Copyright (c) 2016-present Allan CORNET (Nelson)
# ==============================================================================
# This file is part of the Nelson.
# =============================================================================
# LICENCE_BLOCK_BEGIN SPDX-License-Identifier: LGPL-3.0-or-later
# LICENCE_BLOCK_END
# ==============================================================================
set(module_name localization)
set(module_library_name nlsLocalization)
# ==============================================================================
file(GLOB LOCALIZATION_SRC "${CMAKE_CURRENT_SOURCE_DIR}/no-src/cpp/*.cpp")
list(FILTER LOCALIZATION_SRC EXCLUDE REGEX
"${CMAKE_CURRENT_SOURCE_DIR}/no-src/cpp/dllMain.cpp")
# ==============================================================================
add_library(${module_library_name} ${LOCALIZATION_SRC})
target_include_directories(
    ${module_library_name}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/no-src/include>
    $<INSTALL_INTERFACE:include/nelson/${module_name}>
)
target_include_directories(
    ${module_library_name}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../types/src/include
)
# ==============================================================================
file(GLOB LOCALIZATION_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/no-src/include/*.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/no-src/include/*.h")
set_target_properties(
  ${module_library_name}
  PROPERTIES
    VERSION
    ${Nelson_VERSION_MAJOR}.${Nelson_VERSION_MINOR}.${Nelson_VERSION_MAINTENANCE}
    SOVERSION ${Nelson_VERSION_MAJOR}
    PUBLIC_HEADER "${LOCALIZATION_HEADER}"
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
