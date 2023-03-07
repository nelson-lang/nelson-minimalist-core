%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
assert_isequal(nargin('issingle'), 1);
assert_isequal(nargout('issingle'), 1);
%=============================================================================
A = 3.6;
res = issingle(A);
assert_isfalse(res);
%=============================================================================
B = single([1 ; 3]);
res = issingle(B);
assert_istrue(res);
%=============================================================================
