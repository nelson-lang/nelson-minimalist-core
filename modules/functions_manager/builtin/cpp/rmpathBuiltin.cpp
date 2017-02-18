//=============================================================================
// Copyright (c) 2016-2017 Allan CORNET (Nelson)
//=============================================================================
// LICENCE_BLOCK_BEGIN
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// LICENCE_BLOCK_END
//=============================================================================
#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>
#include "rmpathBuiltin.hpp"
#include "Error.hpp"
#include "PathFuncManager.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
ArrayOfVector Nelson::FunctionsGateway::rmpathBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    if (nLhs > 1)
    {
        Error(eval, ERROR_WRONG_NUMBERS_OUTPUT_ARGS);
    }
    if (argIn.size() != 1)
    {
        Error(eval, ERROR_WRONG_NUMBERS_INPUT_ARGS);
    }
    std::wstring previousPaths = PathFuncManager::getInstance()->getPathNameAsString();
    ArrayOf param1 = argIn[0];
    if (param1.isSingleString())
    {
        std::wstring pathToRemove = param1.getContentsAsWideString();
        boost::filesystem::path data_dir(pathToRemove);
        bool bRes = false;
        try
        {
            bRes = boost::filesystem::is_directory(data_dir);
        }
        catch (const boost::filesystem::filesystem_error& e)
        {
            if (e.code() == boost::system::errc::permission_denied)
            {
            }
            bRes = false;
        }
        if (bRes)
        {
            if (!PathFuncManager::getInstance()->removePath(pathToRemove))
            {
                Interface *io = eval->getInterface();
                if (io)
                {
                    io->warningMessage(_W("Warning: Not in path:") + L" " + pathToRemove + L"\n");
                }
            }
			else
			{
				stringVector exceptedFunctionsName = eval->getCallers(true);
				PathFuncManager::getInstance()->clearCache(exceptedFunctionsName);
			}
        }
        else
        {
            Interface *io = eval->getInterface();
            if (io)
            {
                io->warningMessage(_W("Warning: Not a directory:") + L" " + pathToRemove + L"\n");
            }
        }
    }
    else
    {
        Error(eval, ERROR_WRONG_ARGUMENT_1_TYPE_STRING_EXPECTED);
    }
    if (nLhs == 1)
    {
        retval.push_back(ArrayOf::stringConstructor(previousPaths));
    }
    return retval;
}
//=============================================================================
