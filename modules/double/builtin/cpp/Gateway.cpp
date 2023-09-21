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
#include "double_Gateway.hpp"
#include "doubleBuiltin.hpp"
#include "flintmaxBuiltin.hpp"
#include "realmaxBuiltin.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
const std::wstring gatewayName = L"double";
//=============================================================================
static const nlsGateway gateway[] = {
    { "double", (ptrBuiltin)Nelson::DoubleGateway::doubleBuiltin, 1, 1 },
    { "flintmax", (ptrBuiltin)Nelson::DoubleGateway::flintmaxBuiltin, 1, 1 },
    { "realmax", (ptrBuiltin)Nelson::DoubleGateway::realmaxBuiltin, 1, 1 },
};
//=============================================================================
int
DoubleGateway(void* eval, const wchar_t* moduleFilename)
{
    return NelsonAddGatewayWithEvaluator(eval, moduleFilename, (void*)gateway,
        sizeof(gateway) / sizeof(nlsGateway), gatewayName.c_str(), (void*)nullptr);
}
//=============================================================================
