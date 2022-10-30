# ==============================================================================
# Copyright (c) 2016-present Allan CORNET (Nelson)
# ==============================================================================
# This file is part of the Nelson.
# =============================================================================
# LICENCE_BLOCK_BEGIN
# SPDX-License-Identifier: LGPL-3.0-or-later
# LICENCE_BLOCK_END
# ==============================================================================
set(module_name engine)
set(module_library_name nlsEngine)
set(module_library_builtin_name ${module_library_name}_builtin)
# ==============================================================================
include_directories(
  ${EIGEN3_INCLUDE_DIR}
  ${Boost_INCLUDE_DIRS}
  ${CMAKE_CURRENT_SOURCE_DIR}/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../types/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../dynamic_link/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../characters_encoding/no-src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../interpreter/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../error_manager/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../stream_manager/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../memory_manager/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../core/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../os_functions/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../modules_manager/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../nelson_manager/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../file_archiver/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../terminal/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../gui/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../localization/no-src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../i18n/no-src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../mex/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../sparse/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../time/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../ipc/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../sio_client/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../sio_client/src/socket_io/src)
# ==============================================================================
file(GLOB ENGINE_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/cpp/*.cpp")
# ==============================================================================
add_library(${module_library_name} SHARED ${ENGINE_SRC})
# ==============================================================================
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  find_library(LIBRT rt)
endif()
# ==============================================================================
target_link_libraries(
  ${module_library_name}
  nlsCore
  nlsInterpreter
  nlsTerminal
  nlsCharacters_encoding
  nlsMemory_manager
  nlsNelson_manager
  nlsLocalization
  nlsI18n
  ${BOOST_LIBRARIES}
  ${LIBRT})
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
