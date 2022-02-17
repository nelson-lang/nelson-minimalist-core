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
#include "Types.hpp"
#include "nlsInterpreter_exports.h"
//=============================================================================
namespace Nelson {

NLSINTERPRETER_IMPEXP wstringVector
GetKeywords(bool bSorted = false);
NLSINTERPRETER_IMPEXP bool
isKeyword(const std::wstring& key);

const unsigned int IDENTIFIER_LENGTH_MAX = 4096;

/**
 * These keywords must be in alphabetical order.
 */
const unsigned int NLS_KEYWORD_BREAK = 0;
const unsigned int NLS_KEYWORD_CASE = 1;
const unsigned int NLS_KEYWORD_CATCH = 2;
const unsigned int NLS_KEYWORD_CONTINUE = 3;
const unsigned int NLS_KEYWORD_ELSE = 4;
const unsigned int NLS_KEYWORD_ELSEIF = 5;
const unsigned int NLS_KEYWORD_END = 6;
const unsigned int NLS_KEYWORD_FOR = 7;
const unsigned int NLS_KEYWORD_FUNCTION = 8;
const unsigned int NLS_KEYWORD_IF = 9;
const unsigned int NLS_KEYWORD_KEYBOARD = 10;
const unsigned int NLS_KEYWORD_OTHERWISE = 11;
const unsigned int NLS_KEYWORD_QUIT = 12;
const unsigned int NLS_KEYWORD_ABORT = 13;
const unsigned int NLS_KEYWORD_RETURN = 14;
const unsigned int NLS_KEYWORD_SWITCH = 15;
const unsigned int NLS_KEYWORD_TRY = 16;
const unsigned int NLS_KEYWORD_WHILE = 17;
const unsigned int NLS_KEYWORD_ENDFUNCTION = 18;

/**
 * Each reserved word structure has three attributes,
 * the text of the reserved word, the token for the word,
 * as generated by the parser, and the ordinal (from above).
 */
struct keywordStruct
{
    const char* word;
    int token;
    int ordinal;
};
//=============================================================================
#define KEYWORDCOUNT 20
extern keywordStruct keyWord[KEYWORDCOUNT];
//=============================================================================
/**
 * A comparison function for the keyWord list of
 * structures, so that the binary search algorithm used
 * on the keywordStruct list works properly.
 */
int
compareKeyword(const void* /*a*/, const void* /*b*/);
//=============================================================================
} // namespace Nelson
//=============================================================================
