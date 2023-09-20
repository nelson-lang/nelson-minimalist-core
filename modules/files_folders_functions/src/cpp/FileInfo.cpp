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
#include <chrono>
#include <ctime>
#include <cmath>
#include "FileSystemWrapper.hpp"
#include "FileInfo.hpp"
#include "characters_encoding.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
static bool
IsLeapYear(int year)
{
    if (year < 0) {
        return false;
    }
    /* Check if the year is divisible by 4 or is divisible by 400 */
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
//=============================================================================
static double
DateNumber(double year, double month, double day, double hour, double minutes, double secondes)
{
    if (month < 1) {
        month = 1;
    }
    if (month > 12) {
        year += (month - 1) / 12;
        month = (static_cast<int>(month - 1) % 12) + 1;
    }
    double decimal_part = (secondes * (1.0 / (24.0 * 3600.0))) + (minutes * (1.0 / (24.0 * 60.0)))
        + (hour * (1.0 / 24.0));
    // convert of month and day
    int integer_part = static_cast<int>(day + floor((month * 3057 - 3007) / 100));
    // we remove 1 if mont is more than february
    integer_part = integer_part + (static_cast<int>(month < 3) - 1);
    // we remove again 1 if month is more februar and it is not a leap year
    integer_part = (integer_part
        + ((static_cast<int>(month < 3) | static_cast<int>(IsLeapYear(static_cast<int>(year))))
            - 1));
    if (IsLeapYear(static_cast<int>(year))) {
        double leap_year_case = year * 365 + (year / 4) - floor(year / 100) + floor(year / 400);
        integer_part = static_cast<int>(integer_part + leap_year_case);
    } else {
        double not_leap_year_case
            = year * 365 + floor(year / 4) + 1 - floor(year / 100) + floor(year / 400);
        integer_part = static_cast<int>(integer_part + not_leap_year_case);
    }
    return (integer_part + decimal_part);
}
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
    std::time_t last_write_time = FileSystemWrapper::Path::last_write_time(_path, errorMessage);
    if (errorMessage.empty()) {
        std::tm* timeinfo = std::gmtime(&last_write_time);
        int year = timeinfo->tm_year + 1900;
        int month = timeinfo->tm_mon + 1;
        int day = timeinfo->tm_mday;
        int hours = timeinfo->tm_hour;
        int minutes = timeinfo->tm_min;
        int seconds = timeinfo->tm_sec;
        this->date = std::to_wstring(year) + L"-" + std::to_wstring(month) + L"-"
            + std::to_wstring(day) + L" " + std::to_wstring(hours) + L":" + std::to_wstring(minutes)
            + L":" + std::to_wstring(seconds);
        this->datenum = DateNumber(year, month, day, hours, minutes, seconds);
    } else {
        this->date = std::wstring();
        this->datenum = -1;
    }
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
