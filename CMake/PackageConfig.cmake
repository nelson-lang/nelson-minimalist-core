# ==============================================================================
# Copyright (c) 2016-present Allan CORNET (Nelson)
# ==============================================================================
# This file is part of the Nelson.
# =============================================================================
# LICENCE_BLOCK_BEGIN SPDX-License-Identifier: LGPL-3.0-or-later
# LICENCE_BLOCK_END
# ==============================================================================
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_VENDOR "Allan CORNET")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY
    "Nelson is an- matrix/array programming language providing a powerful open computing environment for engineering and scientific applications using modern C/C++ libraries (Eigen, C++17, …) and others state of art numerical libraries."
)
set(CPACK_PACKAGE_VERSION_MAJOR ${Nelson_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${Nelson_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${Nelson_VERSION_MAINTENANCE})
set(CPACK_PACKAGE_VERSION
    "${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}.${Nelson_VERSION_BUILD}"
)
set(CPACK_PACKAGE_INSTALL_DIRECTORY "Nelson-${CPACK_PACKAGE_VERSION}")
set(CPACK_PACKAGE_CONTACT "nelson.numerical.computation@gmail.com")

if(UNIX)
  set(CPACK_GENERATOR "TGZ")
else(UNIX)
  set(CPACK_GENERATOR "ZIP")
endif(UNIX)
# ==============================================================================
include(CPack)
# ==============================================================================
