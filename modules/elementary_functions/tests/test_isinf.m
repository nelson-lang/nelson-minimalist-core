%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
assert_isequal(nargin('isinf'), 1)
assert_isequal(nargout('isinf'), 1)
%=============================================================================
assert_isequal(isinf(NaN), false);
assert_isequal(isinf(single(Inf)), true);
assert_isequal(isinf(Inf), true);
%=============================================================================
X = [1 2 Inf 3 -Inf 4];
R = isinf(X);
REF = [ false  false  true   false  true   false];
assert_isequal(R, REF);
%=============================================================================
R = isinf([13, Inf, -Inf, NaN]);
REF = logical([0, 1, 1, 0]);
assert_isequal(R, REF);
%=============================================================================
