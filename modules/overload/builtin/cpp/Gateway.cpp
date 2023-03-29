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
#include "overload_Gateway.hpp"
#include "overloadbasictypesBuiltin.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
const std::wstring gatewayName = L"overload";
//=============================================================================
static const nlsGateway gateway[] = {
    { "overloadbasictypes", (ptrBuiltin)Nelson::OverloadGateway::overloadbasictypesBuiltin, 1, -1,
        CPP_BUILTIN_WITH_EVALUATOR },
};
//=============================================================================
int
OverloadGateway(void* eval, const wchar_t* moduleFilename)
{
    return NelsonAddGatewayWithEvaluator(eval, moduleFilename, (void*)gateway,
        sizeof(gateway) / sizeof(nlsGateway), gatewayName.c_str(), (void*)nullptr);
}
//=============================================================================
