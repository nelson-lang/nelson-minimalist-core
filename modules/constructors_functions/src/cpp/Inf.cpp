//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include <algorithm>
#include "Inf.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
ArrayOf
Inf()
{
    return Inf(1, 1);
}
//=============================================================================
ArrayOf
Inf(indexType m, indexType n)
{
    Dimensions dims(m, n);
    return Inf(dims);
}
//=============================================================================
ArrayOf
Inf(Dimensions& dims)
{
    dims.simplify();
    indexType nbElements = dims.getElementCount();
    double* mat = nullptr;
    if (nbElements != 0) {
        mat = static_cast<double*>(
            ArrayOf::allocateArrayOf(NLS_DOUBLE, nbElements, stringVector(), false));
        std::fill_n(mat, nbElements, std::numeric_limits<double>::infinity());
    }
    return ArrayOf(NLS_DOUBLE, dims, mat, false);
}
//=============================================================================
} // namespace Nelson
//=============================================================================
