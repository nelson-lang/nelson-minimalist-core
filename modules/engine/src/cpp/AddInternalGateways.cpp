//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "AddInternalGateways.hpp"
//=============================================================================
#include "display_format_Gateway.hpp"
#include "functions_manager_Gateway.hpp"
#include "trigonometric_functions_Gateway.hpp"
#include "types_Gateway.hpp"
#include "elementary_functions_Gateway.hpp"
#include "linear_algebra_Gateway.hpp"
#include "constructors_functions_Gateway.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
void
addInternalGateways(Evaluator* eval)
{
    FunctionsManagerGateway(eval, L"");
    DisplayFormatGateway(eval, L"");
    TrigonometricFunctionsAddGateway(eval, L"");
    TypesGateway(eval, L"");
    ElementaryFunctionsGateway(eval, L"");
    LinearAlgebraGateway(eval, L"");
    ConstructorsFunctionsGateway(eval, L"");
}
//=============================================================================

}
//=============================================================================
