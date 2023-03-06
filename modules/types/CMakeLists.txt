# ==============================================================================
# Copyright (c) 2016-present Allan CORNET (Nelson)
# ==============================================================================
# This file is part of the Nelson.
# =============================================================================
# LICENCE_BLOCK_BEGIN
# SPDX-License-Identifier: LGPL-3.0-or-later
# LICENCE_BLOCK_END
# ==============================================================================
set(module_name types)
set(module_library_name nlsTypes)
set(module_library_builtin_name ${module_library_name}_builtin)
# ==============================================================================
file(GLOB TYPES_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/cpp/*.cpp")
list(FILTER TYPES_SRC EXCLUDE REGEX "${CMAKE_CURRENT_SOURCE_DIR}/src/cpp/dllMain.cpp") 
# ==============================================================================
add_library(${module_library_name} ${TYPES_SRC})
if(WIN32)
    target_compile_definitions(${module_library_name} PUBLIC "NLSTYPES_EXPORTS")
endif()
target_include_directories(
    ${module_library_name}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/include>
    $<INSTALL_INTERFACE:include/${PROJECT_NAME}/${module_name}>
)
target_include_directories(
  ${module_library_name}
  PRIVATE
  ${EIGEN3_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/../stream_manager/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../sparse/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../linear_algebra/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../dynamic_link/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../interpreter/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../nelson_manager/src/include)
target_link_libraries(
  ${module_library_name}
  nlsCharacters_encoding
  nlsCommons
  nlsElementary_mathematics
  nlsError_manager
  nlsI18n
  nlsCommons)
# ==============================================================================
file(GLOB TYPES_BUILTIN
     "${CMAKE_CURRENT_SOURCE_DIR}/builtin/cpp/*.cpp")
list(FILTER TYPES_BUILTIN EXCLUDE REGEX
     "${CMAKE_CURRENT_SOURCE_DIR}/builtin/cpp/dllMain.cpp")
# ==============================================================================
add_library(${module_library_builtin_name} ${TYPES_BUILTIN})
if(WIN32)
    target_compile_definitions(${module_library_builtin_name} PUBLIC "NLSTYPES_BUILTIN_EXPORTS")
endif()
target_include_directories(
    ${module_library_builtin_name}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/builtin/include>
    $<INSTALL_INTERFACE:include/${PROJECT_NAME}/${module_name}>
)
target_include_directories(
    ${module_library_builtin_name}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../string/src/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../error_manager/src/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../stream_manager/src/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../overload/src/include
    ${EIGEN3_INCLUDE_DIR}
)
# ==============================================================================
target_link_libraries(
  ${module_library_builtin_name}
  nlsTypes
  nlsInterpreter
  nlsError_manager
  nlsOverload)
# ==============================================================================
file(GLOB TYPES_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/src/include/*.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/include/*.h")
set_target_properties(
  ${module_library_name}
  PROPERTIES
    VERSION
    ${Nelson_VERSION_MAJOR}.${Nelson_VERSION_MINOR}.${Nelson_VERSION_MAINTENANCE}
    SOVERSION ${Nelson_VERSION_MAJOR}
    PUBLIC_HEADER "${TYPES_HEADER}"
)
# ==============================================================================
file(GLOB TYPES_BUILTIN_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/builtin/include/*.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/builtin/include/*.h")
set_target_properties(
  ${module_library_builtin_name}
  PROPERTIES
    VERSION
    ${Nelson_VERSION_MAJOR}.${Nelson_VERSION_MINOR}.${Nelson_VERSION_MAINTENANCE}
    SOVERSION ${Nelson_VERSION_MAJOR}
    PUBLIC_HEADER "${TYPES_BUILTIN_HEADER}"
)
# ==============================================================================
include(GNUInstallDirs)
install(
    TARGETS ${module_library_builtin_name} ${module_library_name}
    EXPORT ${PROJECT_NAME}-targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION
    ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}/${module_name}
)
# ==============================================================================
