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
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
//=============================================================================
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <vector>
#include "runBuiltin.hpp"
#include "Error.hpp"
#include "EvaluateScriptFile.hpp"
#include "StringFormat.hpp"
#include "characters_encoding.hpp"
#include "PositionScript.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
static std::wstring
getBackTraceMessage(Exception& e)
{
    std::wstring message = e.getMessage();
    std::vector<PositionScript> traces = e.getTrace();
    size_t nbTraces = traces.size();

    std::wstring functionName;
    std::wstring lineAsString;

    int i = -1;
    if (nbTraces != 0) {
        if (traces[0].getFunctionName() != L"error") {
            if (nbTraces > 1) {
                i = 0;
            }
        } else {
            if (nbTraces > 1) {
                if (traces[1].getFunctionName() != L"run") {
                    i = 1;
                }
            }
        }
    }

    if (i != -1) {
        if (traces[i + 1].getFunctionName() != L"run") {
            functionName = traces[i].getFunctionName();
            if (traces[i].getLine() != 0) {
                lineAsString = std::to_wstring(traces[i].getLine());
            }
        }
    }

    if (functionName.empty()) {
        message = L"\n" + _W("Error: ") + L"\n" + message + L"\n";
    } else {
        if (!lineAsString.empty()) {
            message = L"\n" + _W("Error in ") + functionName + L" (" + _W("line") + L" "
                + lineAsString + L")\n" + message + L"\n";
        } else {
            message = L"\n" + _W("Error in ") + functionName + L"\n" + message + L"\n";
        }
    }
    if (nbTraces > 0) {
        message = message + L"\n";
    }

    for (size_t k = 0; k < nbTraces; k++) {
        if (traces[k].getFunctionName() == L"run") {
            if ((k >= 1) && traces[k - 1].getLine() != 0) {
                size_t pos = k - 1;
                boost::filesystem::path pf = boost::filesystem::path(traces[pos].getFilename());
                std::wstring filename;
                if (traces[pos].getFilename().size() > 50) {
                    filename = pf.filename().wstring();
                } else {
                    filename = pf.wstring();
                }
                message = message
                    + StringFormat(_W("at line %5d of \'%ls\'\n").c_str(), traces[pos].getLine(),
                          filename.c_str());
            }
        }
    }
    return message;
}
//=============================================================================
static ArrayOfVector
runBuiltinThreeRhs(Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    bool bErrorCatch = false;
    bool bChangeDir = true;
    std::wstring wpath;
    if (argIn[2].isLogical()) {
        bChangeDir = (argIn[2].getContentAsLogicalScalar() == 0) ? false : true;
    } else {
        Error(ERROR_WRONG_ARGUMENT_1_TYPE_LOGICAL_EXPECTED);
    }
    if (argIn[1].isRowVectorCharacterArray()) {
        std::wstring arg2 = argIn[1].getContentAsWideString();
        if (arg2.compare(L"errcatch") == 0) {
            bErrorCatch = true;
            if (nLhs > 1) {
                Error(ERROR_WRONG_NUMBERS_OUTPUT_ARGS);
            }
        } else if (arg2.compare(L"nocatch") == 0) {
            bErrorCatch = false;
        } else {
            Error(ERROR_WRONG_ARGUMENT_2_VALUE);
        }
    } else {
        Error(ERROR_WRONG_ARGUMENT_1_TYPE_STRING_EXPECTED);
    }
    if (argIn[0].isRowVectorCharacterArray()) {
        wpath = argIn[0].getContentAsWideString();
    } else {
        Error(ERROR_WRONG_ARGUMENT_1_TYPE_STRING_EXPECTED);
    }
    bool bSuccess = false;
    try {
        bSuccess = EvaluateScriptFile(eval, wpath.c_str(), bChangeDir);
    } catch (Exception& e) {
        eval->setLastErrorException(e);
        if (bErrorCatch) {
            bSuccess = false;
        } else {
            Interface* io = eval->getInterface();
            std::wstring message = getBackTraceMessage(e);
            io->errorMessage(message);
            Error("");
        }
    }
    if (bErrorCatch) {
        retval.push_back(ArrayOf::logicalConstructor(bSuccess));
    }
    return retval;
}
//=============================================================================
static ArrayOfVector
runBuiltinTwoRhs(Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    bool bErrorCatch = false;
    bool bChangeDir = true;
    std::wstring wpath;
    if (argIn[1].isLogical()) {
        if (nLhs != 0) {
            Error(ERROR_WRONG_NUMBERS_OUTPUT_ARGS);
        }
        bChangeDir = (argIn[1].getContentAsLogicalScalar() == 0) ? false : true;
    } else {
        if (argIn[1].isRowVectorCharacterArray()) {
            std::wstring arg2 = argIn[1].getContentAsWideString();
            if (arg2.compare(L"errcatch") == 0) {
                bErrorCatch = true;
                if (nLhs > 1) {
                    Error(ERROR_WRONG_NUMBERS_OUTPUT_ARGS);
                }
            } else if (arg2.compare(L"nocatch") == 0) {
                bErrorCatch = false;
            } else {
                Error(ERROR_WRONG_ARGUMENT_2_VALUE);
            }
        } else {
            Error(ERROR_WRONG_ARGUMENT_2_TYPE);
        }
    }
    if (argIn[0].isRowVectorCharacterArray()) {
        wpath = argIn[0].getContentAsWideString();
    } else {
        Error(ERROR_WRONG_ARGUMENT_1_TYPE_STRING_EXPECTED);
    }
    bool bSuccess = false;
    try {
        bSuccess = EvaluateScriptFile(eval, wpath.c_str(), bChangeDir);
    } catch (Exception& e) {
        eval->setLastErrorException(e);
        if (bErrorCatch) {
            bSuccess = false;
        } else {
            Interface* io = eval->getInterface();
            std::wstring message = getBackTraceMessage(e);
            io->errorMessage(message);
            Error("");
        }
    }
    if (bErrorCatch) {
        retval.push_back(ArrayOf::logicalConstructor(bSuccess));
    }
    return retval;
}
//=============================================================================
static ArrayOfVector
runBuiltinOneRhs(Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    if (nLhs != 0) {
        Error(ERROR_WRONG_NUMBERS_OUTPUT_ARGS);
    }
    if (argIn[0].isRowVectorCharacterArray()) {
        std::wstring wpath = argIn[0].getContentAsWideString();
        try {
            EvaluateScriptFile(eval, wpath.c_str(), true);
        } catch (Exception& e) {
            Interface* io = eval->getInterface();
            eval->setLastErrorException(e);
            std::wstring message = getBackTraceMessage(e);
            io->errorMessage(message);
            Error("");
        }
    } else {
        Error(ERROR_WRONG_ARGUMENT_1_TYPE_STRING_EXPECTED);
    }
    return retval;
}
//=============================================================================
ArrayOfVector
Nelson::CoreGateway::runBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    if (argIn.size() == 1) {
        return runBuiltinOneRhs(eval, nLhs, argIn);
    } else if (argIn.size() == 2) {
        return runBuiltinTwoRhs(eval, nLhs, argIn);
    } else if (argIn.size() == 3) {
        return runBuiltinThreeRhs(eval, nLhs, argIn);
    } else {
        Error(ERROR_WRONG_NUMBERS_INPUT_ARGS);
    }
    return retval;
}
//=============================================================================
