//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include <cstdio>
#include "SparseDynamicFunctions.hpp"
#include "Error.hpp"
#include "i18n.hpp"
//=============================================================================
void*
EyeSparseMatrixConstructorDynamicFunction(NelsonType dclass, indexType rows, indexType cols)
{
    Error(_W("Sparse type not available."));
    return nullptr;
}
//=============================================================================
void*
LogicalSparseMatrixConstructorDynamicFunction(indexType rows, indexType cols, bool bMotif)
{
    Error(_W("Sparse type not available."));
    return nullptr;
}
//=============================================================================
void
DeleteSparseMatrixDynamicFunction(NelsonType dclass, indexType rows, indexType cols, void* cp)
{
    Error(_W("Sparse type not available."));
}
//=============================================================================
void*
MakeDenseArrayOfDynamicFunction(NelsonType dclass, indexType rows, indexType cols, const void* cp)
{
    Error(_W("Sparse type not available."));
    return nullptr;
}
//=============================================================================
void*
MakeSparseArrayOfDynamicFunction(NelsonType dclass, indexType rows, indexType cols, const void* cp)
{
    Error(_W("Sparse type not available."));
    return nullptr;
}
//=============================================================================
void*
TypeConvertSparseDynamicFunction(
    NelsonType dclass, indexType rows, indexType cols, const void* cp, NelsonType oclass)
{
    Error(_W("Sparse type not available."));
    return nullptr;
}
//=============================================================================
void*
CopySparseMatrixDynamicFunction(NelsonType dclass, indexType rows, indexType cols, const void* cp)
{
    Error(_W("Sparse type not available."));
    return nullptr;
}
//=============================================================================
indexType
CountNonzerosMaxDynamicFunction(NelsonType dclass, indexType rows, indexType cols, const void* cp)
{
    Error(_W("Sparse type not available."));
    return 0;
}
//=============================================================================
indexType
CountNonzerosDynamicFunction(NelsonType dclass, indexType rows, indexType cols, const void* cp)
{
    Error(_W("Sparse type not available."));
    return 0;
}
//=============================================================================
void*
SparseMatrixConstructorDynamicFunction(
    NelsonType dclass, indexType rows, indexType cols, ArrayOfMatrix m)
{
    Error(_W("Sparse type not available."));
    return nullptr;
}
//=============================================================================
void*
GetSparseVectorSubsetsDynamicFunction(NelsonType dclass, indexType rows, indexType cols,
    const void* src, const indexType* indx, indexType irows, indexType icols)
{
    Error(_W("Sparse type not available."));
    return nullptr;
}
//=============================================================================
void*
GetSparseNDimSubsetsDynamicFunction(NelsonType dclass, indexType rows, indexType cols,
    const void* src, const indexType* rindx, indexType irows, const indexType* cindx,
    indexType icols)
{
    Error(_W("Sparse type not available."));
    return nullptr;
}
//=============================================================================
void*
SetSparseVectorSubsetsDynamicFunction(NelsonType dclass, indexType& rows, indexType& cols,
    const void* src, const indexType* indx, indexType irows, indexType icols, const void* data,
    int advance)
{
    Error(_W("Sparse type not available."));
    return nullptr;
}
//=============================================================================
void*
SetSparseNDimSubsetsDynamicFunction(NelsonType dclass, indexType& rows, indexType& cols,
    const void* src, const indexType* rindx, indexType irows, const indexType* cindx,
    indexType icols, const void* data, int advance)
{
    Error(_W("Sparse type not available."));
    return nullptr;
}
//=============================================================================
void*
GetSparseScalarElementDynamicFunction(NelsonType dclass, indexType rows, indexType cols,
    const void* src, indexType rindx, indexType cindx)
{
    Error(_W("Sparse type not available."));
    return nullptr;
}
//=============================================================================
void*
DeleteSparseMatrixColsDynamicFunction(
    NelsonType dclass, indexType rows, indexType cols, const void* cp, bool* dmap)
{
    Error(_W("Sparse type not available."));
    return nullptr;
}
//=============================================================================
void*
DeleteSparseMatrixRowsDynamicFunction(
    NelsonType dclass, indexType rows, indexType cols, const void* cp, bool* dmap)
{
    Error(_W("Sparse type not available."));
    return nullptr;
}
//=============================================================================
void*
DeleteSparseMatrixVectorSubsetDynamicFunction(NelsonType dclass, indexType& rows, indexType& cols,
    const void* cp, const indexType* todel, indexType delete_len)
{
    Error(_W("Sparse type not available."));
    return nullptr;
}
//=============================================================================
void*
ReshapeSparseMatrixDynamicFunction(NelsonType dclass, indexType rows, indexType cols,
    indexType newrows, indexType newcols, const void* cp)
{
    Error(_W("Sparse type not available."));
    return nullptr;
}
//=============================================================================
void*
SparseToIJVDynamicFunction(NelsonType dclass, indexType rows, indexType cols, const void* cp,
    indexType*& I, indexType*& J, int& nnz)
{
    Error(_W("Sparse type not available."));
    return nullptr;
}
//=============================================================================
