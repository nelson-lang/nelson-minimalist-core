%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
% clear cache before to exit
%=============================================================================
base2dec('', 2);
dec2base([], 2);
%=============================================================================
rmpath(modulepath(nelsonroot(), 'elementary_functions', 'functions'));
removegateway(modulepath(nelsonroot(), 'elementary_functions', 'builtin'))
%=============================================================================