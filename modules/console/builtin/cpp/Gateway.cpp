//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "NelsonGateway.hpp"
#include "console_Gateway.hpp"
#include "clcBuiltin.hpp"
#include "inputBuiltin.hpp"
#include "terminal_sizeBuiltin.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
const std::wstring gatewayName = L"console";
//=============================================================================
static const nlsGateway gateway[] = {
    { "clc", (ptrBuiltin)Nelson::ConsoleGateway::clcBuiltin, 0, 0, CPP_BUILTIN_WITH_EVALUATOR },
    { "input", (ptrBuiltin)Nelson::ConsoleGateway::inputBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "terminal_size", (ptrBuiltin)Nelson::ConsoleGateway::terminal_sizeBuiltin, 1, 0,
        CPP_BUILTIN_WITH_EVALUATOR }

};
//=============================================================================
int
ConsoleGateway(void* eval, const wchar_t* moduleFilename)
{
    return NelsonAddGatewayWithEvaluator(eval, moduleFilename, (void*)gateway,
        sizeof(gateway) / sizeof(nlsGateway), gatewayName.c_str(), (void*)nullptr);
}
//=============================================================================
