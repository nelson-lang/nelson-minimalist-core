%=============================================================================
% Copyright (c) 2020-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
assert_isequal(nargin('logspace'), -1);
assert_isequal(nargout('logspace'), 1);
%=============================================================================
R = logspace(1, 5);
REF = 1.0e+05 * [0.0001, 0.0001, 0.0001, 0.0002, 0.0002, 0.0003, 0.0003, 0.0004, 0.0004, 0.0005, ...
0.0007, 0.0008, 0.0010, 0.0012, 0.0014, 0.0017, 0.0020, 0.0024, 0.0029, 0.0036, ...
0.0043, 0.0052, 0.0063, 0.0075, 0.0091, 0.0110, 0.0133, 0.0160, 0.0193, 0.0233, ...
0.0281, 0.0339, 0.0409, 0.0494, 0.0596, 0.0720, 0.0869, 0.1048, 0.1265, 0.1526, ...
0.1842, 0.2223, 0.2683, 0.3237, 0.3907, 0.4715, 0.5690, 0.6866, 0.8286, 1.0000];
assert_isapprox(R, REF, 1);
%=============================================================================
R = logspace(1, 5, 7);
REF = 1e5 * [0.0001, 0.0005, 0.0022, 0.0100, 0.0464, 0.2154, 1.0000];
assert_isapprox(R, REF, 1e-4);
%=============================================================================
R = logspace(1+2i, 5+5i, 4);
REF = 1e4 * [-0.0001 - 0.0010i, 0.0175 + 0.0126i, -0.4535 + 0.0988i, 4.9458 - 8.6913i];
assert_isapprox(R, REF, 1e-4);
%=============================================================================