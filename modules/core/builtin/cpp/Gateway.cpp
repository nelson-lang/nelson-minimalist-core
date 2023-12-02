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
#include "core_Gateway.hpp"
#include "quitBuiltin.hpp"
#include "bannerBuiltin.hpp"
#include "evalBuiltin.hpp"
#include "evalcBuiltin.hpp"
#include "evalinBuiltin.hpp"
#include "execstrBuiltin.hpp"
#include "namelengthmaxBuiltin.hpp"
#include "narginBuiltin.hpp"
#include "nargoutBuiltin.hpp"
#include "narginchkBuiltin.hpp"
#include "nargoutchkBuiltin.hpp"
#include "nfilenameBuiltin.hpp"
#include "pauseBuiltin.hpp"
#include "runBuiltin.hpp"
#include "inputnameBuiltin.hpp"
#include "versionBuiltin.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
const std::wstring gatewayName = L"core";
//=============================================================================
static const nlsGateway gateway[] = {
    { "exit", (ptrBuiltin)Nelson::CoreGateway::quitBuiltin, 0, 2, CPP_BUILTIN_WITH_EVALUATOR },
    { "quit", (ptrBuiltin)Nelson::CoreGateway::quitBuiltin, 0, 2, CPP_BUILTIN_WITH_EVALUATOR },
    { "run", (ptrBuiltin)Nelson::CoreGateway::runBuiltin, 1, 3, CPP_BUILTIN_WITH_EVALUATOR },
    { "nfilename", (ptrBuiltin)Nelson::CoreGateway::nfilenameBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "mfilename", (ptrBuiltin)Nelson::CoreGateway::nfilenameBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "execstr", (ptrBuiltin)Nelson::CoreGateway::execstrBuiltin, 1, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "eval", (ptrBuiltin)Nelson::CoreGateway::evalBuiltin, -1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "evalc", (ptrBuiltin)Nelson::CoreGateway::evalcBuiltin, -1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "evalin", (ptrBuiltin)Nelson::CoreGateway::evalinBuiltin, -1, 2, CPP_BUILTIN_WITH_EVALUATOR },
    { "nargin", (ptrBuiltin)Nelson::CoreGateway::narginBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "narginchk", (ptrBuiltin)Nelson::CoreGateway::narginchkBuiltin, 0, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "nargout", (ptrBuiltin)Nelson::CoreGateway::nargoutBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "nargoutchk", (ptrBuiltin)Nelson::CoreGateway::nargoutchkBuiltin, 1, 3,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "pause", (ptrBuiltin)Nelson::CoreGateway::pauseBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "namelengthmax", (ptrBuiltin)Nelson::CoreGateway::namelengthmaxBuiltin, 1, 1 },
    { "inputname", (ptrBuiltin)Nelson::CoreGateway::inputnameBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "version", (ptrBuiltin)Nelson::CoreGateway::versionBuiltin, 2, 1 },

};
//=============================================================================
int
CoreGateway(void* eval, const wchar_t* moduleFilename)
{
    return NelsonAddGatewayWithEvaluator(eval, moduleFilename, (void*)gateway,
        sizeof(gateway) / sizeof(nlsGateway), gatewayName.c_str(), (void*)nullptr);
}
//=============================================================================
