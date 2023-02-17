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
#include "expmBuiltin.hpp"
#include "issymmetricBuiltin.hpp"
#include "ishermitianBuiltin.hpp"
#include "logmBuiltin.hpp"
#include "schurBuiltin.hpp"
#include "sqrtmBuiltin.hpp"
#include "traceBuiltin.hpp"
#include "detBuiltin.hpp"
#include "linear_algebra_Gateway.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
const std::wstring gatewayName = L"linear_algebra";
//=============================================================================
static const nlsGateway gateway[] = {
    { "sqrtm", (ptrBuiltin)Nelson::LinearAlgebraGateway::sqrtmBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "logm", (ptrBuiltin)Nelson::LinearAlgebraGateway::logmBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "expm", (ptrBuiltin)Nelson::LinearAlgebraGateway::expmBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "schur", (ptrBuiltin)Nelson::LinearAlgebraGateway::schurBuiltin, 2, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "trace", (ptrBuiltin)Nelson::LinearAlgebraGateway::traceBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "issymmetric", (ptrBuiltin)Nelson::LinearAlgebraGateway::issymmetricBuiltin, 1, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "ishermitian", (ptrBuiltin)Nelson::LinearAlgebraGateway::ishermitianBuiltin, 1, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "det", (ptrBuiltin)Nelson::LinearAlgebraGateway::detBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
};
//=============================================================================
int
LinearAlgebraGateway(void* eval, const wchar_t* moduleFilename)
{
    return NelsonAddGatewayWithEvaluator(eval, moduleFilename, (void*)gateway,
        sizeof(gateway) / sizeof(nlsGateway), gatewayName.c_str(), (void*)nullptr);
}
//=============================================================================
