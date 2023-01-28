%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
assert_isequal(nargin('newline'), -0);
assert_isequal(nargout('newline'), 1);
%=============================================================================
R = newline();
REF = char(10);
assert_isequal(R, REF);
%=============================================================================