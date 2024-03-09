//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "JsonInterface.hpp"
#include "characters_encoding.hpp"
#include <nlohmann/json.hpp>
//=============================================================================
JsonInterface::JsonInterface() { }
//=============================================================================
JsonInterface::~JsonInterface() { }
//=============================================================================
std::wstring
JsonInterface::getLine(const std::wstring& prompt)
{
    return L"";
}
//=============================================================================
std::string
JsonInterface::getLine(const std::string& prompt)
{
    return "";
}
//=============================================================================
std::wstring
JsonInterface::getInput(const std::wstring& prompt)
{
    return L"";
}
//=============================================================================
size_t
JsonInterface::getTerminalWidth()
{
    return DEFAULT_CONSOLE_WIDTH;
}
//=============================================================================
size_t
JsonInterface::getTerminalHeight()
{
    return DEFAULT_CONSOLE_HEIGHT;
}
//=============================================================================
void
JsonInterface::outputMessage(const std::wstring& msg)
{
    outputMessage(wstring_to_utf8(msg));
}
//=============================================================================
void
JsonInterface::outputMessage(const std::string& msg)
{
    buffer += msg;
}
//=============================================================================
void
JsonInterface::errorMessage(const std::wstring& msg)
{
    errorMessage(wstring_to_utf8(msg));
}
//=============================================================================
void
JsonInterface::errorMessage(const std::string& msg)
{
    buffer += msg;
}
//=============================================================================
void
JsonInterface::warningMessage(const std::wstring& msg)
{
    warningMessage(wstring_to_utf8(msg));
}
//=============================================================================
void
JsonInterface::warningMessage(const std::string& msg)
{
    buffer += msg;
}
//=============================================================================
void
JsonInterface::clearTerminal()
{
}
//=============================================================================
bool
JsonInterface::isAtPrompt()
{
    return false;
}
//=============================================================================
void
JsonInterface::interruptGetLineByEvent()
{
}
//=============================================================================
std::string
JsonInterface::stringify()
{
    nlohmann::json data;
    data["plain/text"] = buffer;
    buffer.clear();
    return data.dump() + "\n";
}
//=============================================================================
