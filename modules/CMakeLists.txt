# ==============================================================================
# Copyright (c) 2016-present Allan CORNET (Nelson)
# ==============================================================================
# This file is part of the Nelson.
# =============================================================================
# LICENCE_BLOCK_BEGIN
#
# SPDX-License-Identifier: LGPL-3.0-or-later
#
# LICENCE_BLOCK_END
# ==============================================================================
include_directories(${EIGEN_INCLUDE_DIR})
# ==============================================================================
list(
  APPEND
  moduleslist
  characters_encoding
  commons
  nelson_manager
  debugger
  i18n
  localization
  elementary_mathematics
  error_manager
  types
  stream_manager
  display_format
  operators
  os_functions
  interpreter
  profiler
  functions_manager
  files_folders_functions
  core
  memory_manager
  overload
  text_completion
  trigonometric_functions
  terminal
  elementary_functions
  linear_algebra
  constructors_functions
  time
  string
  statistics
  data_analysis
  single
  logical
  data_structures
  assert_functions
  double
  integer
  engine)
# ==============================================================================
list(APPEND moduleslist main)
# ==============================================================================
foreach(mod ${moduleslist})
  add_subdirectory(${mod})
endforeach(mod)
# ==============================================================================
