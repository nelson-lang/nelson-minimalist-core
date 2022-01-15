//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// Alternatively, you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2 of
// the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this program. If not, see <http://www.gnu.org/licenses/>.
// LICENCE_BLOCK_END
//=============================================================================
#pragma once
//=============================================================================
#include "ArrayOf.hpp"
#include "Evaluator.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
namespace DisplayFormatGateway {
    //=============================================================================
    ArrayOfVector
    dispBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn);
    //=============================================================================
    ArrayOfVector
    int8_dispBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn);
    //=============================================================================
    ArrayOfVector
    int16_dispBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn);
    //=============================================================================
    ArrayOfVector
    int32_dispBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn);
    //=============================================================================
    ArrayOfVector
    int64_dispBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn);
    //=============================================================================
    ArrayOfVector
    uint8_dispBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn);
    //=============================================================================
    ArrayOfVector
    uint16_dispBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn);
    //=============================================================================
    ArrayOfVector
    uint32_dispBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn);
    //=============================================================================
    ArrayOfVector
    uint64_dispBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn);
    //=============================================================================
    ArrayOfVector
    logical_dispBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn);
    //=============================================================================
    ArrayOfVector
    char_dispBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn);
    //=============================================================================
    ArrayOfVector
    double_dispBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn);
    //=============================================================================
    ArrayOfVector
    single_dispBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn);
    //=============================================================================
    ArrayOfVector
    struct_dispBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn);
    //=============================================================================
    ArrayOfVector
    cell_dispBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn);
    //=============================================================================
    ArrayOfVector
    handle_dispBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn);
    //=============================================================================
    ArrayOfVector
    string_dispBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn);
    //=============================================================================
    ArrayOfVector
    sparsedouble_dispBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn);
    //=============================================================================
    ArrayOfVector
    sparselogical_dispBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn);
    //=============================================================================

}
//=============================================================================
} // namespace Nelson
//=============================================================================
