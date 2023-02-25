//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "handle_vertcat_handleBuiltin.hpp"
#include "InputOutputArgumentsCheckers.hpp"
#include "VertCatHandle.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
ArrayOfVector
Nelson::HandleGateway::handle_vertcat_handleBuiltin(int nLhs, const ArrayOfVector& argIn)
{
    nargincheck(argIn, 2, 2);
    nargoutcheck(nLhs, 0, 1);
    ArrayOfVector retval(1);
    ArrayOf A = argIn[0];
    ArrayOf B = argIn[1];
    retval << VertCatHandle(A, B);
    return retval;
}
//=============================================================================
