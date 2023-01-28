%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
rng('default')
format('longE')
%=============================================================================
A = complex(rand(3,3,2), rand(3,3,2));
A(1) = 0;
R = evalc('single(A)');
REF =     '
  3×3×2 single array

ans(:,:,1) =

  Columns 1 through 2

  0.0000000e+00 + 0.0000000e+00i  9.1337585e-01 + 3.5711680e-02i
  9.0579194e-01 + 9.5949244e-01i  6.3235927e-01 + 8.4912932e-01i
  1.2698682e-01 + 6.5574068e-01i  9.7540401e-02 + 9.3399322e-01i

  Column 3

  2.7849823e-01 + 6.7873514e-01i
  5.4688150e-01 + 7.5774014e-01i
  9.5750684e-01 + 7.4313247e-01i


ans(:,:,2) =

  Columns 1 through 2

  9.6488851e-01 + 3.9222702e-01i  9.5716697e-01 + 7.0604610e-01i
  1.5761308e-01 + 6.5547788e-01i  4.8537564e-01 + 3.1832844e-02i
  9.7059280e-01 + 1.7118669e-01i  8.0028045e-01 + 2.7692297e-01i

  Column 3

  1.4188634e-01 + 4.6171390e-02i
  4.2176127e-01 + 9.7131774e-02i
  9.1573554e-01 + 8.2345784e-01i

';
assert_isequal(R, REF)
%=============================================================================