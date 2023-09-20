//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#ifdef _MSC_VER
#pragma warning(disable : 4190)
#endif
//=============================================================================
#include "NelsonGateway.hpp"
#include "assert_functions_Gateway.hpp"
#include "assert_checkerrorBuiltin.hpp"
#include "assert_isapproxBuiltin.hpp"
#include "assert_isequalBuiltin.hpp"
#include "assert_isfalseBuiltin.hpp"
#include "assert_istrueBuiltin.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
const std::wstring gatewayName = L"assert_functions";
//=============================================================================
static const nlsGateway gateway[] = {
    { "assert_istrue", (ptrBuiltin)Nelson::AssertFunctionsGateway::assert_istrueBuiltin, 2, 1 },
    { "assert_isfalse", (ptrBuiltin)Nelson::AssertFunctionsGateway::assert_isfalseBuiltin, 2, 1 },
    { "assert", (ptrBuiltin)Nelson::AssertFunctionsGateway::assert_istrueBuiltin, 2, 1 },
    { "assert_checkerror", (ptrBuiltin)Nelson::AssertFunctionsGateway::assert_checkerrorBuiltin, 2,
        -2, CPP_BUILTIN_WITH_EVALUATOR },
    { "assert_isequal", (ptrBuiltin)Nelson::AssertFunctionsGateway::assert_isequalBuiltin, 2, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "assert_isapprox", (ptrBuiltin)Nelson::AssertFunctionsGateway::assert_isapproxBuiltin, 2, -2,
        CPP_BUILTIN_WITH_EVALUATOR },
};
//=============================================================================
int
AssertFunctionsGateway(void* eval, const wchar_t* moduleFilename)
{
    return NelsonAddGatewayWithEvaluator(eval, moduleFilename, (void*)gateway,
        sizeof(gateway) / sizeof(nlsGateway), gatewayName.c_str(), (void*)nullptr);
}
//=============================================================================
