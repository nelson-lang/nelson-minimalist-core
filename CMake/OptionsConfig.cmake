# ==============================================================================
# Copyright (c) 2016-present Allan CORNET (Nelson)
# ==============================================================================
# This file is part of the Nelson.
# =============================================================================
# LICENCE_BLOCK_BEGIN
# SPDX-License-Identifier: LGPL-3.0-or-later
# LICENCE_BLOCK_END
# ==============================================================================
include(GNUInstallDirs)
configure_file("${CMAKE_SOURCE_DIR}/modules/commons/src/include/nlsBuildConfig.h.in"
                 "${CMAKE_SOURCE_DIR}/modules/commons/src/include/nlsBuildConfig.h")
# ==============================================================================
