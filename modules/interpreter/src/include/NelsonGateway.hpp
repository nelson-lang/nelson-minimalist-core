//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#pragma once
//=============================================================================
#include <string>
#include "Evaluator.hpp"
#include "GatewayHelpers.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
using ptrBuiltin = void*;
//=============================================================================
enum BUILTIN_PROTOTYPE
{
    CPP_BUILTIN = 0,
    CPP_BUILTIN_WITH_EVALUATOR = 1,
    C_MEX_BUILTIN = 2
};
//=============================================================================
using nlsGateway = struct nlsGatewayStructType
{
    std::string functionName;
    ptrBuiltin fptr;
    int nLhs;
    int nRhs;
    BUILTIN_PROTOTYPE builtinPrototype;
};
//=============================================================================
} // namespace Nelson
//=============================================================================
#ifdef _MSC_VER
#define EXPORTSYMBOL __declspec(dllexport)
#define EXTERN_AS_C extern "C"
#else
#define EXPORTSYMBOL __attribute__((visibility("default")))
#define EXTERN_AS_C extern "C"
#endif
//=============================================================================
