# ==============================================================================
# Copyright (c) 2016-present Allan CORNET (Nelson)
# ==============================================================================
# This file is part of the Nelson.
# =============================================================================
# LICENCE_BLOCK_BEGIN
# SPDX-License-Identifier: LGPL-3.0-or-later
# LICENCE_BLOCK_END
# ==============================================================================
set(module_name files_folders_functions)
set(module_library_name nlsFiles_folders_functions)
# ==============================================================================
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../characters_encoding/no-src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../types/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../error_manager/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../stream_manager/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../commons/src/fmt/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../commons/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../interpreter/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../string/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../i18n/no-src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../time/src/include)
# ==============================================================================
file(GLOB FILES_FOLDERS_FUNCTIONS_SRC
     "${CMAKE_CURRENT_SOURCE_DIR}/src/cpp/*.cpp")
# ==============================================================================
add_library(${module_library_name} SHARED ${FILES_FOLDERS_FUNCTIONS_SRC})
# ==============================================================================
target_link_libraries(
  ${module_library_name}
  nlsStream_manager
  nlsCharacters_encoding
  nlsError_manager
  nlsTypes
  nlsI18n
  nlsInterpreter
  nlsCommons)
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
