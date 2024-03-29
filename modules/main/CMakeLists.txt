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
set(module_name main)
# ==============================================================================
file(GLOB MAINCLI_SRC "${CMAKE_CURRENT_SOURCE_DIR}/nelson_cli/*.cpp")
# ==============================================================================
add_executable(nelson-cli-exec ${MAINCLI_SRC})
# ==============================================================================
# force some dependencies here, to force build order
# ==============================================================================
target_link_libraries(
  nelson-cli-exec
  nlsEngine
  ${HELP_TOOLS_LIBRARIES})
# ==============================================================================
list (
  APPEND
  executableList
  nelson-cli-exec)
add_custom_target(
  Name ALL
  COMMAND ${BUILD_ALL_LOCALIZATION_ACTION}
  DEPENDS ${executableList})
# ==============================================================================
include(GNUInstallDirs)
set(NELSON_SCRIPT_DIR "")
if(UNIX)
  if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(NELSON_SCRIPT_DIR linux)
  else()
    set(NELSON_SCRIPT_DIR macOS)
  endif()
  
  install(
      FILES ${CMAKE_SOURCE_DIR}/script/${NELSON_SCRIPT_DIR}/nelson
    DESTINATION ${CMAKE_INSTALL_BINDIR}
    PERMISSIONS 
      WORLD_EXECUTE WORLD_READ 
      GROUP_EXECUTE GROUP_READ 
      OWNER_EXECUTE OWNER_READ OWNER_WRITE
  )

  install(
      FILES ${CMAKE_SOURCE_DIR}/script/${NELSON_SCRIPT_DIR}/nelson-cli
    DESTINATION ${CMAKE_INSTALL_BINDIR}
    PERMISSIONS
      WORLD_EXECUTE WORLD_READ 
      GROUP_EXECUTE GROUP_READ 
      OWNER_EXECUTE OWNER_READ OWNER_WRITE
  )
else()
  if(CMAKE_SIZE_OF_VOID_P EQUAL 4) 
    set(NELSON_SCRIPT_DIR win32)
  else()
    set(NELSON_SCRIPT_DIR x64)
  endif()
  install(
      FILES ${CMAKE_SOURCE_DIR}/script/${NELSON_SCRIPT_DIR}/nelson.bat
    DESTINATION ${CMAKE_INSTALL_BINDIR}
    PERMISSIONS 
      WORLD_EXECUTE WORLD_READ 
      GROUP_EXECUTE GROUP_READ 
      OWNER_EXECUTE OWNER_READ OWNER_WRITE
  )
endif()

# ==============================================================================
install(
  TARGETS nelson-cli-exec
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
# ==============================================================================
install(
  DIRECTORY ${CMAKE_SOURCE_DIR}/modules/${module_name}/help
  DESTINATION ${NELSON_DOC_INSTALL_DIR}/modules/${module_name}
  FILES_MATCHING
  PATTERN "*.qch"
  PATTERN "xml" EXCLUDE
  PATTERN "md" EXCLUDE)
# ==============================================================================
