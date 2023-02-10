//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#pragma once
//=============================================================================
#include "ArrayOf.hpp"
#include "nlsSpecial_functions_exports.h"
//=============================================================================
namespace Nelson {
NLSSPECIAL_FUNCTIONS_IMPEXP ArrayOf
BetaIncomplete(
    const ArrayOf& X, const ArrayOf& Y, const ArrayOf& Z, bool isLower, bool& needOverload);
}
//=============================================================================