//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "LeftDivide.hpp"
#include "MatrixCheck.hpp"
#include "DotLeftDivide.hpp"
#include "LinearEquationSolver.hpp"
#include "Warning.hpp"
#include "Error.hpp"
#include "i18n.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
static bool
promoteCommonType(ArrayOf& A, ArrayOf& B)
{
    bool wasPromoted = true;
    if (A.getDataClass() != B.getDataClass()) {
        if (A.isComplex() || B.isComplex()) {
            if (A.isComplex()) {
                if (B.getDataClass() == NLS_DOUBLE) {
                    B.promoteType(NLS_DCOMPLEX);
                } else if (B.getDataClass() == NLS_SINGLE) {
                    B.promoteType(NLS_SCOMPLEX);
                } else {
                    wasPromoted = false;
                }
            } else {
                if (A.getDataClass() == NLS_DOUBLE) {
                    A.promoteType(NLS_DCOMPLEX);
                } else if (A.getDataClass() == NLS_SINGLE) {
                    A.promoteType(NLS_SCOMPLEX);
                } else {
                    wasPromoted = false;
                }
            }
        } else {
            if (A.getDataClass() == NLS_SINGLE || B.getDataClass() == NLS_SINGLE) {
                A.promoteType(NLS_SINGLE);
                B.promoteType(NLS_SINGLE);
            } else {
                wasPromoted = false;
            }
        }
    }
    return wasPromoted;
}
//=============================================================================
ArrayOf
LeftDivide(ArrayOf A, ArrayOf B, bool& needToOverload)
{
    needToOverload = false;
    if (A.isEmpty() || B.isEmpty()) {
        Dimensions dims(0, 1);
        return ArrayOf::emptyConstructor(dims);
    }

    if (A.isSparse() || B.isSparse()) {
        needToOverload = true;
        return {};
    }

    if (A.isScalar()) {
        return DotLeftDivide(A, B, needToOverload);
    }

    if (A.getDimensionLength(0) != B.getDimensionLength(0)) {
        Error(_W("Requested divide operation requires arguments to have correct dimensions."));
    }
    std::wstring warningId;
    std::string warningMessage;
    ArrayOf res;

    if (!promoteCommonType(A, B)) {
        needToOverload = true;
        return res;
    }

    Error(_W("Requires LAPACK."));

    return res;
}
//=============================================================================
} // namespace Nelson
//=============================================================================
