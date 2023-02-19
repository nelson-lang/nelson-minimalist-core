# ==============================================================================
# Copyright (c) 2016-present Allan CORNET (Nelson)
# ==============================================================================
# This file is part of the Nelson.
# =============================================================================
# LICENCE_BLOCK_BEGIN SPDX-License-Identifier: LGPL-3.0-or-later
# LICENCE_BLOCK_END
# ==============================================================================
set(module_name mex)
set(module_library_name nlsMex)
set(module_library_builtin_name ${module_library_name}_builtin)
# ==============================================================================
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/no-src/include)
# ==============================================================================
  file(GLOB MEX_SRC "${CMAKE_CURRENT_SOURCE_DIR}/no-src/cpp/*.cpp")
  list(FILTER MEX_SRC EXCLUDE REGEX
       "${CMAKE_CURRENT_SOURCE_DIR}/no-src/cpp/dllMain.cpp")
# ==============================================================================
add_library(${module_library_name} SHARED ${MEX_SRC})
# ==============================================================================
  target_link_libraries(${module_library_name})
# ==============================================================================
set_target_properties(
  ${module_library_name}
  PROPERTIES
    VERSION
    ${Nelson_VERSION_MAJOR}.${Nelson_VERSION_MINOR}.${Nelson_VERSION_MAINTENANCE}
    SOVERSION ${Nelson_VERSION_MAJOR})
# ==============================================================================
