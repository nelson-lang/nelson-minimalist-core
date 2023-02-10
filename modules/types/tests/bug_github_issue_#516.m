%=============================================================================
% Copyright (c) 2017 Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
% <-- Issue URL -->
% https://github.com/Nelson-numerical-software/nelson/issues/516
% <-- Short Description -->
% 'ind = 2; ind(false)' logical extraction on scalar should return empty matrix
%=============================================================================
ind = 2;
R = ind(true);
REF = 2;
assert_isequal(R, REF);
%=============================================================================
R = ind(false);
REF = [];
assert_isequal(R, REF);
%=============================================================================
R = ind(logical([0 0 0 ]'));
REF = zeros(0, 1);
assert_isequal(R, REF);
%=============================================================================
R =ind(logical([0 0 0 ]));
REF = zeros(1, 0);
assert_isequal(R, REF);
%=============================================================================
A = eye(3, 3);
R = A(logical(ones(3,3)));
REF = [  1;     0;     0;     0;     1;     0;     0;     0;     1];
assert_isequal(R, REF);
%=============================================================================