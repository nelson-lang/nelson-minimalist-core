//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#define _CRT_SECURE_NO_WARNINGS
#include "FileSystemWrapper.hpp"
#include "FileInfo.hpp"
#include "characters_encoding.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
FileInfo::FileInfo(const std::wstring& filename)
{
    FileSystemWrapper::Path _path(filename);
    // uniformize path separator
    _path = _path.generic_wstring();
    this->folder = _path.parent_path().wstring();
    this->name = _path.filename().wstring();
    this->isdir = FileSystemWrapper::Path::is_directory(_path);
    if (this->isdir) {
        this->bytes = 0;
    } else {
        std::string errorMessage;
        double value = (double)FileSystemWrapper::Path::file_size(_path, errorMessage);
        if (errorMessage.empty()) {
            this->bytes = value;
        } else {
            this->bytes = -1;
        }
    }
    std::string errorMessage;
    std::time_t t = FileSystemWrapper::Path::last_write_time(_path, errorMessage);
/*
    if (errorMessage.empty()) {
        int day = pt.date().day();
        int month = pt.date().month();
        int year = pt.date().year();
        auto hms = pt.time_of_day();
        int h = (int)hms.hours();
        int m = (int)hms.minutes();
        int s = (int)hms.seconds();
        this->date = boost::posix_time::to_simple_wstring(pt);
        this->datenum = DateNumber(year, month, day, h, m, s);
    } else {
        this->date = std::wstring();
        this->datenum = -1;
    }
    */
           this->date = std::wstring();
        this->datenum = -1;

}
//=============================================================================
FileInfo::~FileInfo()
{
    this->folder = std::wstring();
    this->name = std::wstring();
    this->date = std::wstring();
    this->isdir = false;
    this->bytes = -1;
    this->datenum = -1;
}
//=============================================================================
std::wstring
FileInfo::getFolder()
{
    return this->folder;
}
//=============================================================================
std::wstring
FileInfo::getName()
{
    return this->name;
}
//=============================================================================
std::wstring
FileInfo::getDate()
{
    return this->date;
}
//=============================================================================
bool
FileInfo::isDir()
{
    return this->isdir;
}
//=============================================================================
double
FileInfo::getBytes()
{
    return this->bytes;
}
//=============================================================================
double
FileInfo::getDatenum()
{
    return this->datenum;
}
//=============================================================================
} // namespace Nelson
//=============================================================================
