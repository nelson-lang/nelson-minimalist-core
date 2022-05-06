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
#include "nlsRandom_exports.h"
//=============================================================================
namespace Nelson {
//=============================================================================
NLSRANDOM_IMPEXP std::wstring
RngGetType();
//=============================================================================
NLSRANDOM_IMPEXP void
RngSetSeed(double seed);
//=============================================================================
NLSRANDOM_IMPEXP ArrayOf
RngGetSeed();
//=============================================================================
NLSRANDOM_IMPEXP ArrayOf
RngGetState();
//=============================================================================
NLSRANDOM_IMPEXP void
RngSetDefault();
//=============================================================================
NLSRANDOM_IMPEXP void
RngShuffle();
//=============================================================================
NLSRANDOM_IMPEXP bool
RngSetEngine(double seed, const std::wstring& engineName);
//=============================================================================
NLSRANDOM_IMPEXP void
RngDelete();
//=============================================================================
NLSRANDOM_IMPEXP bool
RngSetState(const ArrayOf& st);
//=============================================================================
} // namespace Nelson
//=============================================================================
