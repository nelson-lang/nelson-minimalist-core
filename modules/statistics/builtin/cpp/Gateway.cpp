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
#include "corrcoefBuiltin.hpp"
#include "varBuiltin.hpp"
#include "meanBuiltin.hpp"
#include "statistics_Gateway.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
const std::wstring gatewayName = L"statistics";
//=============================================================================
static const nlsGateway gateway[] = {
    {
        "corrcoef",
        (ptrBuiltin)Nelson::StatisticsGateway::corrcoefBuiltin,
        1,
        1,
    },
    { "var", (ptrBuiltin)Nelson::StatisticsGateway::varBuiltin, 1, 3 },
    { "mean", (ptrBuiltin)Nelson::StatisticsGateway::meanBuiltin, 1, 4 },
};
//=============================================================================
int
StatisticsGateway(void* eval, const wchar_t* moduleFilename)
{
    return NelsonAddGatewayWithEvaluator(eval, moduleFilename, (void*)gateway,
        sizeof(gateway) / sizeof(nlsGateway), gatewayName.c_str(), (void*)nullptr);
}
//=============================================================================
