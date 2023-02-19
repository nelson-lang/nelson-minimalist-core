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
#include <string>
#include "ArrayOf.hpp"
#include "Evaluator.hpp"
#include "nlsAssert_functions_exports.h"
//=============================================================================
namespace Nelson {
NLSASSERT_FUNCTIONS_IMPEXP bool
Assert_IsEqual(
    Evaluator* eval, const ArrayOf& computedArray, const ArrayOf& expectedArray, std::wstring& msg);
}
//=============================================================================
