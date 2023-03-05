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
set(module_name profiler)
set(module_library_name nlsProfiler)
# ==============================================================================
file(GLOB PROFILER_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/cpp/*.cpp")
list(FILTER PROFILER_SRC EXCLUDE REGEX
     "${CMAKE_CURRENT_SOURCE_DIR}/src/cpp/dllMain.cpp")
# ==============================================================================
add_library(${module_library_name} ${PROFILER_SRC})
if(WIN32)
    target_compile_definitions(${module_library_name} PUBLIC "NLSPROFILER_EXPORTS")
endif()
target_include_directories(
    ${module_library_name}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/include>
    $<INSTALL_INTERFACE:include/nelson/${module_name}>
)
target_include_directories(
    ${module_library_name}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../linear_algebra/src/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../interpreter/src/include
)
target_link_libraries(
  ${module_library_name}
  nlsError_manager
  nlsCommons
  nlsStream_manager
  nlsCharacters_encoding
  nlsI18n
  nlsTypes)
# ==============================================================================
file(GLOB PROFILER_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/src/include/*.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/include/*.h")
set_target_properties(
  ${module_library_name}
  PROPERTIES
    VERSION
    ${Nelson_VERSION_MAJOR}.${Nelson_VERSION_MINOR}.${Nelson_VERSION_MAINTENANCE}
    SOVERSION ${Nelson_VERSION_MAJOR}
    PUBLIC_HEADER "${PROFILER_HEADER}"
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
