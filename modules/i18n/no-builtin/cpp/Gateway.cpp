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
#include "i18n_Gateway.hpp"
#include "gettextBuiltin.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
const std::wstring gatewayName = L"i18n";
//=============================================================================
static const nlsGateway gateway[] = {
    { "gettext", (ptrBuiltin)Nelson::I18nGateway::gettextBuiltin, 1, 1 },
    { "_", (ptrBuiltin)Nelson::I18nGateway::gettextBuiltin, 1, 1 },

};
//=============================================================================
int
I18nGateway(void* eval, const wchar_t* moduleFilename)
{
    return NelsonAddGatewayWithEvaluator(eval, moduleFilename, (void*)gateway,
        sizeof(gateway) / sizeof(nlsGateway), gatewayName.c_str(), (void*)nullptr);
}
//=============================================================================
