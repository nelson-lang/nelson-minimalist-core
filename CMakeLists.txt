# ==============================================================================
# Copyright (c) 2016-present Allan CORNET (Nelson)
# ==============================================================================
# This file is part of the Nelson.
# =============================================================================
# LICENCE_BLOCK_BEGIN SPDX-License-Identifier: LGPL-3.0-or-later
# LICENCE_BLOCK_END
# ==============================================================================
message(
  STATUS
    "CMake version ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION}"
)
# ==============================================================================
cmake_minimum_required(VERSION 3.9)
# ==============================================================================
project(Nelson)
# ==============================================================================
set(Nelson_VERSION_MAJOR_DEFAULT 0)
set(Nelson_VERSION_MINOR_DEFAULT 6)
set(Nelson_VERSION_MAINTENANCE_DEFAULT 12)
set(Nelson_VERSION_BUILD_DEFAULT 0)
# ==============================================================================
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  option(CMAKE_INSTALL_PREFIX "Install directory used by instal." "$ENV{HOME}")
endif()
message(STATUS "CMAKE_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}")
# ==============================================================================
option(LGPL_ONLY "Build Nelson under LGPL v3.x only" OFF)
# ==============================================================================
option(MINIMAL_BUILD "Build mininal Nelson " OFF)
# ==============================================================================
option(WITHOUT_OPENMP "Disable OpenMP" OFF)
# ==============================================================================
option(ENABLE_CLANG_TIDY "Analyze code with clang-tidy." OFF)
option(ENABLE_CLANG_TIDY_FIX "Analyze code with clang-tidy and fix errors." OFF)
# ==============================================================================
option(ENABLE_PACKAGING "Build Nelson for packaging" OFF)
# ==============================================================================
option(BUILD_SHARED_LIBS "Build modules as shared libraries" ON)
# ==============================================================================
message(STATUS "Build Nelson for packaging: ${ENABLE_PACKAGING}")
# ==============================================================================
if(WITHOUT_OPENMP)
  message(STATUS "OpenMP disabled.")
endif()
# ==============================================================================
if(MINIMAL_BUILD)
  message(STATUS "Minimal build.")
endif()
# ==============================================================================
foreach(mod ${optional_modules})
  if(WITHOUT_${mod}_MODULE)
    message(STATUS "${mod} module disabled.")
  endif()
endforeach(mod)
# ==============================================================================
if(LGPL_ONLY OR (WITHOUT_FFTW_MODULE AND WITHOUT_SLICOT_MODULE))
  message(STATUS "LGPL v3.x: enabled.")
endif()
# ==============================================================================
if(POLICY CMP0068)
  cmake_policy(SET CMP0068 NEW)
endif()
# ==============================================================================
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif ()
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake/")
# ==============================================================================
include(VersionConfig)
# ==============================================================================
include(C17Config)
# ==============================================================================
include(clang-tidy)
# ==============================================================================
set(CMAKE_SKIP_BUILD_RPATH TRUE)
set(CMAKE_INSTALL_RPATH ".")
if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  set(CMAKE_MACOSX_RPATH 1)
endif()
# ==============================================================================
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  set(BITNESS 32)
  if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(BITNESS 64)
    add_definitions(-D_LARGEFILE_SOURCE)
    add_definitions(-D_FILE_OFFSET_BITS=64)
  endif()
endif()
# ==============================================================================
configure_file("${CMAKE_SOURCE_DIR}/modules/commons/src/include/nlsBuildConfig.h.in"
                 "${CMAKE_SOURCE_DIR}/modules/commons/src/include/nlsBuildConfig.h")
set(Nelson_VERSION
    ${Nelson_VERSION_MAJOR}.${Nelson_VERSION_MINOR}.${Nelson_VERSION_MAINTENANCE})
# ==============================================================================
find_package(Eigen3 3.3 REQUIRED NO_MODULE)
find_package(PkgConfig REQUIRED)
# ==============================================================================
if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  include(MacOsConfig)
endif()
# ==============================================================================
include(PackageConfig)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
set(NELSON_CMAKECONFIG_INSTALL_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}" CACHE STRING "install path for nelsonConfig.cmake")
set(NELSON_DOC_INSTALL_DIR "${CMAKE_DATA_ROOTDIR}/${PROJECT_NAME}/doc" CACHE STRING "install path for Nelson doc files")
# ==============================================================================
add_subdirectory(modules)
# ==============================================================================

configure_package_config_file(
    ${PROJECT_NAME}Config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/${PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION ${NELSON_CMAKECONFIG_INSTALL_DIR}
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    VERSION ${Nelson_VERSION}
    COMPATIBILITY AnyNewerVersion
)

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/${PROJECT_NAME}Config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    DESTINATION ${NELSON_CMAKECONFIG_INSTALL_DIR}
)
install(
    EXPORT ${PROJECT_NAME}-targets
    FILE ${PROJECT_NAME}Targets.cmake
    DESTINATION ${NELSON_CMAKECONFIG_INSTALL_DIR}
)
