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
#include "addpathBuiltin.hpp"
#include "functions_manager_Gateway.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
const std::wstring gatewayName = L"functions_manager";
//=============================================================================
static const nlsGateway gateway[] = {
    { "addpath", (ptrBuiltin)Nelson::FunctionsGateway::addpathBuiltin, 1, -1,
        CPP_BUILTIN_WITH_EVALUATOR },
};
//=============================================================================
int
FunctionsManagerGateway(void* eval, const wchar_t* moduleFilename)
{
    return NelsonAddGatewayWithEvaluator(eval, moduleFilename, (void*)gateway,
        sizeof(gateway) / sizeof(nlsGateway), gatewayName.c_str(), (void*)nullptr);
}
//=============================================================================
