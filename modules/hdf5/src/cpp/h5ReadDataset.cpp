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
#define H5_BUILT_AS_DYNAMIC_LIB
#include <hdf5.h>
#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>
#include "Exception.hpp"
#include "characters_encoding.hpp"
#include "h5ReadDataset.hpp"
#include "h5ReadFloatDataset.hpp"
#include "h5ReadInteger.hpp"
#include "h5ReadOpaqueDataset.hpp"
#include "h5ReadBitfieldDataset.hpp"
#include "h5ReadString.hpp"
#include "h5ReadEnumDataset.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
ArrayOf
h5ReadDataset(const std::wstring& filename, const std::wstring& dataSetName)
{
    ArrayOf res;
    if (filename.empty()) {
        Error(_W("Valid filename expected."));
    }
    if (dataSetName.empty()) {
        Error(_W("Valid data set name expected."));
    }
    hid_t fid = H5I_INVALID_HID;
    boost::filesystem::path hdf5_filename(filename);
    bool fileExistPreviously = false;
    try {
        fileExistPreviously = boost::filesystem::exists(hdf5_filename)
            && !boost::filesystem::is_directory(hdf5_filename);
    } catch (const boost::filesystem::filesystem_error& e) {
        if (e.code() == boost::system::errc::permission_denied) {
            Error(_W("Permission denied."));
        }
        fileExistPreviously = false;
    }
    if (!fileExistPreviously) {
        Error(_W("file does not exist."));
    }
    if (!H5Fis_hdf5(wstring_to_utf8(hdf5_filename.wstring()).c_str()))
        Error(_W("HDF5 format file expected."));
    else {
        fid = H5Fopen(
            wstring_to_utf8(hdf5_filename.wstring()).c_str(), H5F_ACC_RDONLY, H5P_DEFAULT);
    }
    if (fid == H5I_INVALID_HID) {
        Error(_W("Impossible to open hdf5 file."));
    }

    hid_t dset_id = H5Dopen(fid, wstring_to_utf8(dataSetName).c_str(), H5P_DEFAULT);
    if (dset_id < 0) {
        H5Fclose(fid);
        Error("Impossible to read data set");
    }

    hid_t dspace_id = H5Dget_space(dset_id);
    if (dspace_id < 0) {
        H5Dclose(dset_id);
        H5Fclose(fid);
        Error("Impossible to read data set");
    }

    hid_t type_id = H5Dget_type(dset_id);
    std::wstring errorMessage;
    switch (H5Tget_class(type_id)) {
    case H5T_STRING: {
        res = h5ReadString(dset_id, type_id, dspace_id, false, errorMessage);
    } break;
    case H5T_INTEGER: {
        res = h5ReadInteger(dset_id, type_id, dspace_id, false, errorMessage);
    } break;
    case H5T_FLOAT: {
        res = h5ReadFloatDataset(dset_id, type_id, dspace_id, errorMessage);
    } break;
    case H5T_BITFIELD: {
        res = h5ReadBitfieldDataset(dset_id, type_id, dspace_id, errorMessage);
    } break;
    case H5T_OPAQUE: {
        res = h5ReadOpaqueDataset(dset_id, type_id, dspace_id, errorMessage);
    } break;
    case H5T_COMPOUND: {

    } break;
    case H5T_REFERENCE: {

    } break;
    case H5T_ENUM: {
        res = h5ReadEnumDataset(dset_id, type_id, dspace_id, errorMessage);
    } break;
    case H5T_VLEN: {

    } break;
    case H5T_ARRAY: {

    } break;
    case H5T_TIME: {
        /* The time datatype, H5T_TIME,
        has not been fully implemented and is not supported.If H5T_TIME is used,
        the resulting data will be readable
        and modifiable only on the originating computing platform;
        it will not be portable to other platforms. */
        errorMessage = _W("Type not managed.");
    } break;
    case H5T_NCLASSES:
    default: {
        errorMessage = _W("Type not managed.");
    } break;
    }
    if (!errorMessage.empty()) {
        Error(errorMessage);
    }
    H5Dclose(dset_id);
    H5Dclose(dspace_id);
    H5Fclose(fid);
    return res;
}
//=============================================================================
} // namespace Nelson
//=============================================================================