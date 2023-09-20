//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
//=============================================================================
#include "FileSystemWrapper.hpp"
#include "MexFunctionDef.hpp"
#include "Profiler.hpp"
#include "ProfilerHelpers.hpp"
#include "characters_encoding.hpp"
#include "CallMexBuiltin.hpp"
#include "OverloadHelpers.hpp"
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
using PROC_MexFileRequiredApiVersion = void (*)(int*, int*);
using PROC_MexClearAtExit = void (*)();
using PROC_MexIsLocked = bool (*)();
//=============================================================================
MexFunctionDef::MexFunctionDef(
    const std::wstring& filename, const std::wstring& name, bool isOverload)
    : FunctionDef(isOverload)
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
    if (eval->withOverload && inputs.size() > 0 && !this->isOverload()
        && this->overloadAutoMode == NLS_OVERLOAD_AUTO_ON) {
        bool wasFound = false;
        ArrayOfVector res = callOverloadedFunction(eval,
            NelsonConfiguration::getInstance()->getOverloadLevelCompatibility(), nargout, inputs,
            getName(), ClassName(inputs[0]), inputs[0].getDataClass(), wasFound);
        if (wasFound) {
            return res;
        }
    }

    ArrayOfVector outputs;
    eval->callstack.pushDebug(this->getName(), std::string("built-in ") + this->getName());
    size_t stackDepth = eval->callstack.size();
    uint64 tic = 0;
    try {
        tic = Profiler::getInstance()->tic();
        CallMexBuiltin(mexFunctionPtr, inputs, nargout, outputs, interleavedComplex);
        if (tic != 0) {
            internalProfileFunction stack
                = computeProfileStack(eval, this->getName(), this->getFilename());
            Profiler::getInstance()->toc(tic, stack);
        }
        while (eval->callstack.size() > stackDepth) {
            eval->callstack.pop_back();
        }
        eval->callstack.popDebug();
        return outputs;
    } catch (const Exception&) {
        if (tic != 0) {
            internalProfileFunction stack
                = computeProfileStack(eval, this->getName(), this->getFilename());
            Profiler::getInstance()->toc(tic, stack);
        }
        while (eval->callstack.size() > stackDepth) {
            eval->callstack.pop_back();
        }
        eval->callstack.popDebug();
        throw;
    }
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
