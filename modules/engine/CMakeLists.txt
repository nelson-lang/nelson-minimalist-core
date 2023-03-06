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
set(module_name engine)
set(module_library_name nlsEngine)
# ==============================================================================
file(GLOB ENGINE_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/cpp/*.cpp")
list(FILTER ENGINE_SRC EXCLUDE REGEX
     "${CMAKE_CURRENT_SOURCE_DIR}/src/cpp/dllMain.cpp")
# ==============================================================================
add_library(${module_library_name} ${ENGINE_SRC})
if(WIN32)
    target_compile_definitions(${module_library_name} PUBLIC "NLSENGINE_EXPORTS")
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
    ${CMAKE_CURRENT_SOURCE_DIR}/../types/src/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../mex/no-src/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../stream_manager/src/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../os_functions/src/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../nelson_manager/src/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../elementary_functions/builtin/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../functions_manager/builtin/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../display_format/builtin/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../trigonometric_functions/builtin/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../linear_algebra/builtin/include    
    ${CMAKE_CURRENT_SOURCE_DIR}/../constructors_functions/builtin/include    
    ${CMAKE_CURRENT_SOURCE_DIR}/../time/builtin/include    
    ${CMAKE_CURRENT_SOURCE_DIR}/../string/builtin/include    
    ${CMAKE_CURRENT_SOURCE_DIR}/../stream_manager/builtin/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../data_analysis/builtin/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../statistics/builtin/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../single/builtin/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../core/builtin/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../error_manager/builtin/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../memory_manager/builtin/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../data_structures/builtin/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../operators/builtin/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../assert_functions/builtin/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../debugger/builtin/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../validators/builtin/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../files_folders_function/builtin/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../interpreter/builtin/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../overload/builtin/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../console/builtin/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../double/builtin/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../integer/builtin/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../function_handle/builtin/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../i18n/no-builtin/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../logical/builtin/include)
# ==============================================================================
target_link_libraries(
  ${module_library_name}
  nlsInterpreter
  nlsTerminal
  nlsCharacters_encoding
  nlsCommons
  nlsCore
  nlsError_manager
  nlsMemory_manager
  nlsI18n
  nlsLocalization 
  nlsFunctions_manager_builtin
  nlsDisplay_format_builtin
  nlsTrigonometric_functions_builtin
  nlsElementary_functions_builtin
  nlsLinear_algebra_builtin
  nlsConstructors_functions_builtin
  nlsTypes_builtin
  nlsTime_builtin
  nlsString_builtin
  nlsStream_manager_builtin
  nlsData_analysis_builtin
  nlsStatistics_builtin
  nlsLogical_builtin
  nlsSingle_builtin
  nlsError_manager_builtin
  nlsMemory_manager_builtin
  nlsData_structures_builtin
  nlsOperators_builtin
  nlsAssert_functions_builtin
  nlsDouble_builtin
  nlsInteger_builtin
  nlsOverload_builtin
  nlsDebugger_builtin
  nlsInterpreter_builtin
  nlsConsole_builtin
  nlsValidators_builtin
  nlsFunction_handle_builtin
  nlsFiles_folders_functions_builtin
  nlsI18n_builtin
  nlsCore_builtin)
# ==============================================================================
file(GLOB ENGINE_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/src/include/*.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/include/*.h")
set_target_properties(
  ${module_library_name}
  PROPERTIES
    VERSION
    ${Nelson_VERSION_MAJOR}.${Nelson_VERSION_MINOR}.${Nelson_VERSION_MAINTENANCE}
    SOVERSION ${Nelson_VERSION_MAJOR}
    PUBLIC_HEADER "${ENGINE_HEADER}"
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
    ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}/${module_name}
)
# ==============================================================================
