//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "FileSystemWrapper.hpp"
#include "MexFunctionDef.hpp"
#include "Profiler.hpp"
#include "ProfilerHelpers.hpp"
#include "characters_encoding.hpp"
#include "CallMexBuiltin.hpp"
#include "Error.hpp"
#include "i18n.hpp"
//=============================================================================
#define BUFFER_LENGTH_NAME 4096
#define MEXFILEREQUIREDAPIVERSION_ENTRY "mexfilerequiredapiversion"
#define MEXFUNCTION_ENTRY "mexFunction"
#define FUNCTIONNAME_ENTRY "functionName"
#define MEXCLEARATEXIT_ENTRY "mexClearAtExit"
#define MEXISLOCKED_ENTRY "mexIsLocked"
//=============================================================================
namespace Nelson {
//=============================================================================
MexFunctionDef::MexFunctionDef(const std::wstring& filename, const std::wstring& name)
{
    Error(_W("Not supported."));
}
//=============================================================================
bool
MexFunctionDef::clear()
{
    return false;
}
//=============================================================================
MexFunctionDef::~MexFunctionDef() { }
//=============================================================================
ArrayOfVector
MexFunctionDef::evaluateFunction(Evaluator* eval, const ArrayOfVector& inputs, int nargout)
{
    ArrayOfVector retval;
    Error(_W("Not supported."));
    return retval;
}
//=============================================================================
bool
MexFunctionDef::isLocked()
{
    return false;
}
//=============================================================================
bool
MexFunctionDef::updateCode()
{
    return false;
}
//=============================================================================
} // namespace Nelson
//=============================================================================
