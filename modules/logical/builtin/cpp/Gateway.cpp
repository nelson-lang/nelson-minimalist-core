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
#include "logical_Gateway.hpp"
#include "falseBuiltin.hpp"
#include "logicalBuiltin.hpp"
#include "trueBuiltin.hpp"
#include "xorBuiltin.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
const std::wstring gatewayName = L"logical";
//=============================================================================
static const nlsGateway gateway[] = {
    { "logical", (ptrBuiltin)Nelson::LogicalGateway::logicalBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "true", (ptrBuiltin)Nelson::LogicalGateway::trueBuiltin, 1, 1 },
    { "false", (ptrBuiltin)Nelson::LogicalGateway::falseBuiltin, 1, 1 },
    { "xor", (ptrBuiltin)Nelson::LogicalGateway::xorBuiltin, 1, 2 },
};
//=============================================================================
int
LogicalGateway(void* eval, const wchar_t* moduleFilename)
{
    return NelsonAddGatewayWithEvaluator(eval, moduleFilename, (void*)gateway,
        sizeof(gateway) / sizeof(nlsGateway), gatewayName.c_str(), (void*)nullptr);
}
//=============================================================================
