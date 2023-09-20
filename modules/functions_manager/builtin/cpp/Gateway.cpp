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
#include "functions_manager_Gateway.hpp"
#include "addpathBuiltin.hpp"
#include "builtinBuiltin.hpp"
#include "clearfunBuiltin.hpp"
#include "fevalBuiltin.hpp"
#include "isbuiltinBuiltin.hpp"
#include "ismacroBuiltin.hpp"
#include "macroargsBuiltin.hpp"
#include "pathBuiltin.hpp"
#include "rehashBuiltin.hpp"
#include "rmpathBuiltin.hpp"
#include "userpathBuiltin.hpp"
#include "whatBuiltin.hpp"
#include "inmemBuiltin.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
const std::wstring gatewayName = L"functions_manager";
//=============================================================================
static const nlsGateway gateway[] = {
    { "macroargs", (ptrBuiltin)Nelson::FunctionsGateway::macroargsBuiltin, 2, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "builtin", (ptrBuiltin)Nelson::FunctionsGateway::builtinBuiltin, -1, -1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "feval", (ptrBuiltin)Nelson::FunctionsGateway::fevalBuiltin, -1, -1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "what", (ptrBuiltin)Nelson::FunctionsGateway::whatBuiltin, -1, 0,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "addpath", (ptrBuiltin)Nelson::FunctionsGateway::addpathBuiltin, 1, -1 },
    { "clearfun", (ptrBuiltin)Nelson::FunctionsGateway::clearfunBuiltin, 1, 1 },
    { "rmpath", (ptrBuiltin)Nelson::FunctionsGateway::rmpathBuiltin, 1, -1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "path", (ptrBuiltin)Nelson::FunctionsGateway::pathBuiltin, 1, 2 },
    { "ismacro", (ptrBuiltin)Nelson::FunctionsGateway::ismacroBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "isbuiltin", (ptrBuiltin)Nelson::FunctionsGateway::isbuiltinBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "rehash", (ptrBuiltin)Nelson::FunctionsGateway::rehashBuiltin, 0, 0 },
    { "userpath", (ptrBuiltin)Nelson::FunctionsGateway::userpathBuiltin, 1, 1 },
    { "inmem", (ptrBuiltin)Nelson::FunctionsGateway::inmemBuiltin, 2, 0 },

};
//=============================================================================
int
FunctionsManagerGateway(void* eval, const wchar_t* moduleFilename)
{
    return NelsonAddGatewayWithEvaluator(eval, moduleFilename, (void*)gateway,
        sizeof(gateway) / sizeof(nlsGateway), gatewayName.c_str(), (void*)nullptr);
}
//=============================================================================
