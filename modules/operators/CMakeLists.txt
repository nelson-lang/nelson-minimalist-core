# ==============================================================================
# Copyright (c) 2016-present Allan CORNET (Nelson)
# ==============================================================================
# This file is part of the Nelson.
# =============================================================================
# LICENCE_BLOCK_BEGIN SPDX-License-Identifier: LGPL-3.0-or-later
# LICENCE_BLOCK_END
# ==============================================================================
set(module_name operators)
set(module_library_name nlsOperators)
# ==============================================================================
# ==============================================================================
file(GLOB OPERATORS_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/cpp/*.cpp")
list(FILTER OPERATORS_SRC EXCLUDE REGEX
     "${CMAKE_CURRENT_SOURCE_DIR}/src/cpp/dllMain.cpp")
# ==============================================================================
add_library(${module_library_name} SHARED ${OPERATORS_SRC})
target_include_directories(
    ${module_library_name}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/include>
    $<INSTALL_INTERFACE:include/nelson/${module_name}>
)
target_include_directories(
  ${module_library_name}
  PRIVATE
  ${EIGEN3_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/../commons/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../integer/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../stream_manager/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../sparse/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../characters_encoding/no-src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../overload/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../linear_algebra/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../interpreter/src/include
)
target_link_libraries(
  ${module_library_name}
  nlsApi_nelson
  nlsElementary_mathematics
  nlsError_manager
  nlsI18n
  nlsTypes
  ${NELSON_BLAS_LAPACKX_LIBRARIES})
# ==============================================================================
file(GLOB OPERATORS_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/src/include/*.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/include/*.h")
set_target_properties(
  ${module_library_name}
  PROPERTIES
    VERSION
    ${Nelson_VERSION_MAJOR}.${Nelson_VERSION_MINOR}.${Nelson_VERSION_MAINTENANCE}
    SOVERSION ${Nelson_VERSION_MAJOR}
    PUBLIC_HEADER "${OPERATORS_HEADER}"
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
