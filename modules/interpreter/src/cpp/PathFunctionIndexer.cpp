//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#define FMT_HEADER_ONLY
#include <fmt/printf.h>
#include <fmt/format.h>
#include <fmt/xchar.h>
#include "nlsBuildConfig.h"
#include "StringHelpers.hpp"
#include "PathFunctionIndexer.hpp"
#include "characters_encoding.hpp"
#include "MxGetExtension.hpp"
#include "Error.hpp"
#include "i18n.hpp"
#include "FileSystemWrapper.hpp"
#include "OverloadName.hpp"
#include "NelsonConfiguration.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
PathFunctionIndexer::PathFunctionIndexer(const std::wstring& path, bool withWatcher)
{
    this->withWatcher = withWatcher;
    fileWatcher = nullptr;
    watcherID = 0;
    updateFileWatcherListener = nullptr;
    if (FileSystemWrapper::Path::is_directory(path)) {
        _path = path;
    } else {
        _path.clear();
    }
    rehash();
}
//=============================================================================
bool
PathFunctionIndexer::isWithWatcher()
{
    return NelsonConfiguration::getInstance()->isFileWatcherEnabled() && this->withWatcher;
}
//=============================================================================
void
PathFunctionIndexer::startFileWatcher()
{
}
//=============================================================================
std::unordered_map<std::string, FileFunction*>
PathFunctionIndexer::getAllFileFunctions()
{
    return mapAllFiles;
}
//=============================================================================
bool
PathFunctionIndexer::wasModified()
{
    return false;
}
//=============================================================================
bool
PathFunctionIndexer::comparePathname(const std::wstring& path1, const std::wstring& path2)
{
    FileSystemWrapper::Path p1(path1);
    FileSystemWrapper::Path p2(path2);
    return FileSystemWrapper::Path::equivalent(p1, p2);
}
//=============================================================================
PathFunctionIndexer::~PathFunctionIndexer()
{
    for (auto& mapAllFile : mapAllFiles) {
        if (mapAllFile.second) {
            delete mapAllFile.second;
            mapAllFile.second = nullptr;
        }
    }
    mapRecentFiles.clear();
    mapAllFiles.clear();
    _path.clear();
}
//=============================================================================
wstringVector
PathFunctionIndexer::getFunctionsName(const std::wstring& prefix)
{
    wstringVector functionsName;
    for (auto& mapAllFile : mapAllFiles) {
        if (mapAllFile.second) {
            if (prefix.empty()) {
                functionsName.push_back(mapAllFile.second->getName());
            } else {
                std::wstring name = mapAllFile.second->getName();
                if (StringHelpers::starts_with(name, prefix)) {
                    functionsName.push_back(name);
                }
            }
        }
    }
    return functionsName;
}
//=============================================================================
wstringVector
PathFunctionIndexer::getFunctionsFilename()
{
    wstringVector functionsFilename;
    for (auto& mapAllFile : mapAllFiles) {
        if (mapAllFile.second) {
            functionsFilename.push_back(mapAllFile.second->getFilename());
        }
    }
    return functionsFilename;
}
//=============================================================================
std::wstring
PathFunctionIndexer::getPath()
{
    return _path;
}
//=============================================================================
bool
PathFunctionIndexer::isSupportedFuncFilename(const std::wstring& name)
{
    for (int c : name) {
        bool bSupportedChar
            = (c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c == '_') || (c >= 48 && c <= 57);
        if (!bSupportedChar) {
            return false;
        }
    }
    return true;
}
//=============================================================================
inline std::wstring
getFunctionName(const std::wstring& objectName, const std::wstring& name)
{
    if (objectName.empty() || objectName == name) {
        return name;
    }
    return L"@" + objectName + L"/" + name;
}
//=============================================================================
void
PathFunctionIndexer::rehash(
    const std::wstring& pathToScan, const std::wstring& prefix, bool isPrivate)
{
    try {
        nfs::directory_iterator end_iter;
        FileSystemWrapper::Path path(pathToScan);
        for (nfs::directory_iterator dir_iter(path.native()); dir_iter != end_iter; ++dir_iter) {
            FileSystemWrapper::Path current(dir_iter->path().native());
            if (current.is_directory()) {
                std::wstring stemDirectory = current.stem().wstring();
                if (stemDirectory[0] == OVERLOAD_SYMBOL_CHAR) {
                    rehash(current.generic_wstring(), stemDirectory, false);
                }
                if (stemDirectory == L"private") {
                    rehash(current.generic_wstring(), L"", true);
                }
            }
            std::wstring ext = current.extension().generic_wstring();
            bool isMacro = ext == L".m";
            bool isMex = ext == L"." + getMexExtension();
            std::wstring objectName;
            if (prefix.length() > 1) {
                objectName = prefix;
                objectName.erase(0, 1);
            }
            if (isMacro || isMex) {
                std::wstring name = getFunctionName(objectName, current.stem().generic_wstring());
                if (isSupportedFuncFilename(current.stem().generic_wstring())) {
                    FileFunction* ff = nullptr;
                    std::wstring pathName = prefix == L""
                        ? pathToScan
                        : nfs::path(pathToScan).parent_path().generic_wstring();

                    try {
                        ff = new FileFunction(pathName, objectName, name, isMex, withWatcher,
                            prefix != L"" && !isPrivate, isPrivate);
                    } catch (const std::bad_alloc&) {
                        ff = nullptr;
                    }
                    if (ff) {
                        if (isPrivate) {
                            name = pathName + L"/" + name;
                            mapAllFiles.emplace(wstring_to_utf8(name), ff);

                        } else {
                            mapAllFiles.emplace(wstring_to_utf8(name), ff);
                        }
                    }
                }
            }
        }
    } catch (const nfs::filesystem_error&) {
    }
}
//=============================================================================
void
PathFunctionIndexer::rehash()
{
    if (!_path.empty()) {
        mapRecentFiles.clear();
        rehash(_path, L"", false);
    }
}
//=============================================================================
bool
PathFunctionIndexer::findFuncName(const std::string& functionName, std::wstring& filename)
{
    std::unordered_map<std::string, FileFunction*>::iterator found = mapAllFiles.find(functionName);
    if (found != mapAllFiles.end()) {
        filename = found->second->getFilename();
        if (FileSystemWrapper::Path::is_regular_file(filename)) {
            return true;
        }
    }
    if (withWatcher) {
        const std::wstring mexFullFilename
            = _path + L"/" + utf8_to_wstring(functionName) + L"." + getMexExtension();
        if (FileSystemWrapper::Path::is_regular_file(mexFullFilename)) {
            filename = mexFullFilename;
            return true;
        }
        const std::wstring macroFullFilename = _path + L"/" + utf8_to_wstring(functionName) + L".m";
        if (FileSystemWrapper::Path::is_regular_file(macroFullFilename)) {
            filename = macroFullFilename;
            return true;
        }
    }
    return false;
}
//=============================================================================
} // namespace Nelson
//=============================================================================
