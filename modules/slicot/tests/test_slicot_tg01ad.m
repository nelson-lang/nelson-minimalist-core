%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
% http://slicot.org/objects/software/shared/doc/TG01AD.html
% [A_OUT, E_OUT, B_OUT, C_OUT, LSCALE, RSCALE, INFO] = slicot_tg01ad(JOB, THRESH, A_IN, E_IN, B_IN, C_IN)
assert_isequal(nargin('slicot_tg01ad'), 6);
assert_isequal(nargout('slicot_tg01ad'), 7);
%=============================================================================
L = 4;
N = 4;
M = 2;
P = 2;
JOB = 'A';
THRESH = 0;

A_IN = [ -1         0         0    0.003;
0         0    0.1000    0.02;
100        10         0    0.4;
0         0         0    0.0];

E_IN = [1       0.2         0    0.0;
0         1         0    0.01;
300        90         6    0.3;
0         0        20    0.0];

B_IN = [10         0;
0         0;
0      1000;
10000     10000];

C_IN = [-0.1      0.0    0.001    0.0;
0.0      0.01  -0.001    0.0001];

[A_OUT, E_OUT, B_OUT, C_OUT, LSCALE, RSCALE, INFO] = slicot_tg01ad(JOB, THRESH, A_IN, E_IN, B_IN, C_IN);
%=============================================================================
A_OUT_REF = [-1.0000      0.0000      0.0000      0.3000;
0.0000      0.0000      1.0000      2.0000;
1.0000      0.1000      0.0000      0.4000;
0.0000      0.0000      0.0000      0.0000];
assert_isapprox(A_OUT, A_OUT_REF, 1e-4);
%=============================================================================
E_OUT_REF = [1.0000      0.2000      0.0000      0.0000;
0.0000      1.0000      0.0000      1.0000;
3.0000      0.9000      0.6000      0.3000;
0.0000      0.0000      0.2000      0.0000];
assert_isapprox(E_OUT, E_OUT_REF, 1e-4);
%=============================================================================
B_OUT_REF = [100.0000      0.0000;
0.0000      0.0000;
0.0000    100.0000;
100.0000    100.0000];
assert_isapprox(B_OUT, B_OUT_REF, 1e-4);
%=============================================================================
C_OUT_REF = [-0.0100      0.0000      0.0010      0.0000;
0.0000      0.0010     -0.0010      0.0010];
assert_isapprox(C_OUT, C_OUT_REF, 1e-4);
%=============================================================================
LSCALE_REF = [10.0000     10.0000      0.1000      0.0100];
assert_isapprox(LSCALE, LSCALE_REF, 1e-4);
%=============================================================================
RSCALE_REF = [0.1000      0.1000      1.0000     10.0000];
assert_isapprox(RSCALE, RSCALE_REF, 1e-4);
%=============================================================================
INFO_REF = int32(0);
assert_isequal(INFO, INFO_REF);
%=============================================================================