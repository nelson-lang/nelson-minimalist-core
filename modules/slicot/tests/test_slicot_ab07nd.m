%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
% http://slicot.org/objects/software/shared/doc/AB07ND.html
% [A_OUT, B_OUT, C_OUT, D_OUT, RCOND, INFO] = slicot_ab07nd(A_IN, B_IN, C_IN, D_IN)
assert_isequal(nargin('slicot_ab07nd'), 4);
assert_isequal(nargout('slicot_ab07nd'), 6);
%=============================================================================
A_IN = [1.0   2.0   0.0;
4.0  -1.0   0.0;
0.0   0.0   1.0];

B_IN = [1.0   0.0;
0.0   1.0;
1.0   0.0];

C_IN = [0.0   1.0  -1.0;
0.0   0.0   1.0];

D_IN = [4.0   0.0;
0.0   1.0];

[A_OUT, B_OUT, C_OUT, D_OUT, RCOND, INFO] = slicot_ab07nd(A_IN, B_IN, C_IN, D_IN);
%=============================================================================
A_OUT_REF = [1.0000      1.7500      0.2500;
4.0000     -1.0000     -1.0000;
0.0000     -0.2500      1.2500];
assert_isapprox(A_OUT, A_OUT_REF, 1e-4);
%=============================================================================
B_OUT_REF = [-0.2500      0.0000;
0.0000     -1.0000;
-0.2500      0.0000];
assert_isapprox(B_OUT, B_OUT_REF, 1e-4);
%=============================================================================
C_OUT_REF = [0.0000      0.2500     -0.2500;
0.0000      0.0000      1.0000];
assert_isapprox(C_OUT, C_OUT_REF, 1e-4);
%=============================================================================
D_OUT_REF = [0.2500     -0.0000;
0.0000      1.0000];
assert_isapprox(D_OUT, D_OUT_REF, 1e-4);
%=============================================================================
RCOND_REF = 0.2500;
assert_isapprox(RCOND, RCOND_REF, 1e-4);
%=============================================================================
INFO_REF = int32(0);
assert_isequal(INFO, INFO_REF);
%=============================================================================