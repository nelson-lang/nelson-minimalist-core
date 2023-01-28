%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
assert_isequal(nargin('isa'), 2);
assert_isequal(nargout('isa'), 1);
%=============================================================================
A = 3;
res = isa(A, 'double');
assert_istrue(res);
%=============================================================================
B = {'NelSon', 3, true};
res = isa(B, 'cell');
assert_istrue(res);
%=============================================================================
B = {'NelSon', 3, true};
res = isa(B, 'cell');
assert_istrue(res);
%=============================================================================
B = {'NelSon', 3, true};
res = isa(B, 'float');
assert_isfalse(res);
%=============================================================================
B = {'NelSon', 3, true};
res = isa(B, 'numeric');
assert_isfalse(res);
%=============================================================================
B = {'NelSon', 3, true};
res = isa(B, 'integer');
assert_isfalse(res);
%=============================================================================