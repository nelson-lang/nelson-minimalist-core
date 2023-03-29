//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "CallMexBuiltin.hpp"
#include "NelsonConfiguration.hpp"
#include "Error.hpp"
#include "i18n.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
void
CallMexBuiltin(void* fptr, const ArrayOfVector& inputArgs, int nargout, ArrayOfVector& outputArgs,
    bool interleavedComplex)
{
    Error(_W("Mex not supported."));
}
//=============================================================================
} // namespace Nelson
//=============================================================================
