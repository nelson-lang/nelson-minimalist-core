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
#include "Evaluator.hpp"
#include "NelsonGateway.hpp"
#include "time_Gateway.hpp"
#include "datevecBuiltin.hpp"
#include "sleepBuiltin.hpp"
#include "ticBuiltin.hpp"
#include "tocBuiltin.hpp"
#include "timeitBuiltin.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
const std::wstring gatewayName = L"time";
//=============================================================================
static const nlsGateway gateway[] = {
    { "tic", (ptrBuiltin)Nelson::TimeGateway::ticBuiltin, 0, 0, CPP_BUILTIN_WITH_EVALUATOR },
    { "toc", (ptrBuiltin)Nelson::TimeGateway::tocBuiltin, 1, 0, CPP_BUILTIN_WITH_EVALUATOR },
    { "sleep", (ptrBuiltin)Nelson::TimeGateway::sleepBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "datevec", (ptrBuiltin)Nelson::TimeGateway::datevecBuiltin, 6, 1 },
    { "timeit", (ptrBuiltin)Nelson::TimeGateway::timeitBuiltin, 1, -2, CPP_BUILTIN_WITH_EVALUATOR },
};
//=============================================================================
int
TimeGateway(void* eval, const wchar_t* moduleFilename)
{
    return NelsonAddGatewayWithEvaluator(eval, moduleFilename, (void*)gateway,
        sizeof(gateway) / sizeof(nlsGateway), gatewayName.c_str(), (void*)nullptr);
}
//=============================================================================
