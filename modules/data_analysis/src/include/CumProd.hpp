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
#include "nlsData_analysis_exports.h"
//=============================================================================
namespace Nelson {
NLSDATA_ANALYSIS_IMPEXP ArrayOf
CumProd(const ArrayOf& A, indexType n, bool withNaN, bool reverse, bool& needOverload);
//=============================================================================
} // namespace Nelson
//=============================================================================
