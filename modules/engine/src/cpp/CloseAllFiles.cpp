//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include <cstdio>
#ifndef _MSC_VER
#include <unistd.h>
#endif
#include "CloseAllFiles.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
void
CloseAllFiles()
{
#ifdef _MSC_VER
    _fcloseall();
#else
    FILE* stream = nullptr;
    int maxfd = getdtablesize();
    for (int fd = 0; fd < maxfd; fd++) {
        stream = fdopen(fd, "r");
        if (stream != nullptr) {
            fclose(stream);
            stream = nullptr;
        }
    }

#endif
}
//=============================================================================
} // namespace Nelson
//=============================================================================
