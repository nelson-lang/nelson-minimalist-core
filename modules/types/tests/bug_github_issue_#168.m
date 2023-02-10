%=============================================================================
% Copyright (c) 2017 Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
% <--INTERACTIVE TEST-->
% <-- Issue URL -->
% https://github.com/Nelson-numerical-software/nelson/issues/168
% <-- Short Description -->
% integer display was not interruptable.
%=============================================================================
int32(eye(1000))
% and try to do CTRL-C
%=============================================================================
int64(eye(1000))
% and try to do CTRL-C
%=============================================================================