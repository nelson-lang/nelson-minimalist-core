//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "AsciiToDouble.hpp"
#include <string>
#include <algorithm>
#include <cstdlib>
//=============================================================================
namespace Nelson {
//=============================================================================
double
asciiToDouble(const std::string& str)
{
    std::string s(str);
    std::replace(s.begin(), s.end(), 'D', 'E');
    std::replace(s.begin(), s.end(), 'd', 'e');
    return atof(s.c_str());
}
//=============================================================================
}; // namespace Nelson
//=============================================================================
