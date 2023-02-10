%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
assert_isequal(nargin('atand'), -1);
assert_isequal(nargout('atand'), 1);
%=============================================================================
R = atand([-50 -20 0 20 50]);
REF = [-88.8542  -87.1376         0   87.1376   88.8542];
assert_isapprox(R, REF, 1e-3);
%=============================================================================