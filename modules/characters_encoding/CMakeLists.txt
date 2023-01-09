# ==============================================================================
# Copyright (c) 2016-present Allan CORNET (Nelson)
# ==============================================================================
# This file is part of the Nelson.
# =============================================================================
# LICENCE_BLOCK_BEGIN SPDX-License-Identifier: LGPL-3.0-or-later
# LICENCE_BLOCK_END
# ==============================================================================
set(module_name characters_encoding)
set(module_library_name nlsCharacters_encoding)
# ==============================================================================
file(GLOB CHARACTERS_ENCODING_SRC "${CMAKE_CURRENT_SOURCE_DIR}/no-src/cpp/*.cpp")
list(FILTER CHARACTERS_ENCODING_SRC EXCLUDE REGEX
"${CMAKE_CURRENT_SOURCE_DIR}/no-src/cpp/dllMain.cpp")
# ==============================================================================
add_library(${module_library_name} SHARED ${CHARACTERS_ENCODING_SRC})
target_include_directories(
    ${module_library_name}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/no-src/include>
    $<INSTALL_INTERFACE:include/nelson/${module_name}>
)
target_link_libraries(${module_library_name} ${ICU_LIBRARIES})
# ==============================================================================
set_target_properties(
  ${module_library_name}
  PROPERTIES
    VERSION
    ${Nelson_VERSION_MAJOR}.${Nelson_VERSION_MINOR}.${Nelson_VERSION_MAINTENANCE}
    SOVERSION ${Nelson_VERSION_MAJOR})
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
