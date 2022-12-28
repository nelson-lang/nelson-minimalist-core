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
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/no-src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../types/src/include)
# ==============================================================================
file(GLOB LOCALIZATION_SRC "${CMAKE_CURRENT_SOURCE_DIR}/no-src/cpp/*.cpp")
list(FILTER LOCALIZATION_SRC EXCLUDE REGEX
"${CMAKE_CURRENT_SOURCE_DIR}/no-src/cpp/dllMain.cpp")
# ==============================================================================
add_library(${module_library_name} SHARED ${LOCALIZATION_SRC})
# ==============================================================================
target_link_libraries(
  ${module_library_name})
# ==============================================================================
set_target_properties(
  ${module_library_name}
  PROPERTIES
    VERSION
    ${Nelson_VERSION_MAJOR}.${Nelson_VERSION_MINOR}.${Nelson_VERSION_MAINTENANCE}
    SOVERSION ${Nelson_VERSION_MAJOR})
# ==============================================================================
install(TARGETS ${module_library_name} LIBRARY DESTINATION ${LIBRARY_OUTPUT})
# ==============================================================================
