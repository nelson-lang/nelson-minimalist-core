%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
format('longE')
%=============================================================================
rng('default')
A = complex(rand(2, 2), 1);
A(2, 2) = NaN;
R = evalc('A = single(A)');
REF = '
A =

  2×2 single matrix

  8.1472367e-01 + 1.0000000e+00i  1.2698682e-01 + 1.0000000e+00i
  9.0579194e-01 + 1.0000000e+00i            NaN + 0.0000000e+00i

';
assert_isequal(R, REF)
%=============================================================================