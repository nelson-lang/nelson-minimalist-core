//=============================================================================
// Copyright (c) 2016-2018 Allan CORNET (Nelson)
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
#include "h5writeBuiltin.hpp"
#include "Error.hpp"
#include "HDF5_helpers.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
// h5write(filename, datasetname, data)
// h5write(filename, datasetname, data, start, count)
// h5write(filename, datasetname, data, start, count, stride) 
//=============================================================================
ArrayOfVector
Nelson::Hdf5Gateway::h5writeBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    if (nLhs != 0) {
        Error(ERROR_WRONG_NUMBERS_OUTPUT_ARGS);
    }
    indexType nbArgIn = argIn.size();
    if (nbArgIn < 3 || nbArgIn > 6) {
        Error(ERROR_WRONG_NUMBERS_INPUT_ARGS);
    }
	boost::container::vector<double> start;
    if (nbArgIn > 3) {
    }
    boost::container::vector<double> count;
	if (nbArgIn > 4) {
    }
    boost::container::vector<double> stride;
	if (nbArgIn > 5) {
    }
    ArrayOf param1 = argIn[0];
    std::wstring filename = param1.getContentAsWideString();
    ArrayOf param2 = argIn[1];
    std::wstring dataSetName = param2.getContentAsWideString();
    ArrayOf data = argIn[2];
    hdf5Write(filename, dataSetName, data, start, count, stride);
	return retval;
}
//=============================================================================
