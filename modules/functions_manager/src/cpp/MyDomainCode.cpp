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
#include "MyDomainCode.hpp"
//=============================================================================
namespace Nelson {
std::wstring
MyDomainCode(const std::wstring& inputString)
{
    std::wstring copy(inputString);

    std::reverse(copy.begin(), copy.end());

    return copy;
}
//=============================================================================
} // namespace Nelson
//=============================================================================
