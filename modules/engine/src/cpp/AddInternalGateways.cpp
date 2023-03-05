//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "AddInternalGateways.hpp"
//=============================================================================
#include "display_format_Gateway.hpp"
#include "functions_manager_Gateway.hpp"
#include "trigonometric_functions_Gateway.hpp"
#include "types_Gateway.hpp"
#include "elementary_functions_Gateway.hpp"
#include "linear_algebra_Gateway.hpp"
#include "constructors_functions_Gateway.hpp"
#include "time_Gateway.hpp"
#include "string_Gateways.hpp"
#include "stream_manager_Gateway.hpp"
#include "statistics_Gateway.hpp"
#include "data_analysis_Gateway.hpp"
#include "single_Gateway.hpp"
#include "logical_Gateway.hpp"
#include "core_Gateway.hpp"
#include "error_manager_Gateway.hpp"
#include "memory_manager_Gateway.hpp"
#include "data_structures_Gateway.hpp"
#include "assert_functions_Gateway.hpp"
#include "double_Gateway.hpp"
#include "integer_Gateway.hpp"
#include "debugger_Gateway.hpp"
#include "console_Gateway.hpp"
#include "interpreter_Gateway.hpp"
#include "overload_Gateway.hpp"
#include "validators_Gateway.hpp"
#include "files_folders_functions_Gateway.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
void
addInternalGateways(Evaluator* eval)
{
    FunctionsManagerGateway(eval, L"");
    DisplayFormatGateway(eval, L"");
    TrigonometricFunctionsAddGateway(eval, L"");
    TypesGateway(eval, L"");
    ElementaryFunctionsGateway(eval, L"");
    LinearAlgebraGateway(eval, L"");
    ConstructorsFunctionsGateway(eval, L"");
    TimeGateway(eval, L"");
    StringGateway(eval, L"");
    StreamManagerGateway(eval, L"");
    StatisticsGateway(eval, L"");
    DataAnalysisGateway(eval, L"");
    SingleGateway(eval, L"");
    LogicalGateway(eval, L"");
    CoreGateway(eval, L"");
    ErrorManagerGateway(eval, L"");
    MemoryManagerGateway(eval, L"");
    DataStructuresGateway(eval, L"");
    AssertFunctionsGateway(eval, L"");
    DoubleGateway(eval, L"");
    IntegerGateway(eval, L"");
    DebuggerGateway(eval, L"");
    ConsoleGateway(eval, L"");
    InterpreterGateway(eval, L"");
    OverloadGateway(eval, L"");
    ValidatorsGateway(eval, L"");
    FilesFoldersFunctionsGateway(eval, L"");
}
//=============================================================================
}
//=============================================================================
