//=============================================================================
// Copyright (c) 2016-2019 Allan CORNET (Nelson)
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
#include "SaveMatioHandle.hpp"
#include "SaveMatioStruct.hpp"
#include "Warning.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
matvar_t*
SaveMatioHandle(std::string variableName, ArrayOf variableValue)
{
    /* handle have no equivalent in others softwares */
    Warning(_W("handle not saved."));
    return SaveMatioStruct(variableName, ArrayOf::emptyStructWithoutFields());
}
//=============================================================================
}
//=============================================================================