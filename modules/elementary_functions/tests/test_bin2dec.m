%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
assert_isequal(nargin('bin2dec'), 1)
assert_isequal(nargout('bin2dec'), 1)
%=============================================================================
R = bin2dec('11');
REF = 3;
assert_isequal(R, REF);
%=============================================================================