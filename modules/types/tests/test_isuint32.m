%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
assert_isequal(nargin('isuint32'), 1);
assert_isequal(nargout('isuint32'), 1);
%=============================================================================
A = 3;
res = isuint32(A);
assert_isfalse(res);
%=============================================================================
A = uint32(3);
res = isuint32(A);
assert_istrue(res);
%=============================================================================
