//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "isvarnameBuiltin.hpp"
#include "Error.hpp"
#include "IsValidVariableName.hpp"
#include "CheckerHelpers.hpp"
#include "CheckerHelpers.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
ArrayOfVector
Nelson::TypeGateway::isvarnameBuiltin(int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    nargoutcheck(nLhs, 0, 1);
    nargincheck(argIn, 1, 1);
    bool isvarname = false;
    if (argIn[0].isRowVectorCharacterArray() || (argIn[0].isStringArray() && argIn[0].isScalar())) {
        isvarname = IsValidVariableName(argIn[0].getContentAsWideString());
    }
    retval << ArrayOf::logicalConstructor(isvarname);
    return retval;
}
//=============================================================================
