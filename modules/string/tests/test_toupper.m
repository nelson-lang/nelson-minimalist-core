%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
assert_isequal(nargin('toupper'), 1);
assert_isequal(nargout('toupper'), 1);
%=============================================================================
A = 'Nelson';
R = toupper(A);
REF = 'NELSON';
assert_isequal(R, REF);
%=============================================================================
A = {'r', 'b', 'C'};
R = toupper(A);
REF = {'R', 'B', 'C'};
%assert_isequal(R, REF);
%=============================================================================
A = ["r", "b", "C"];
R = toupper(A);
REF = ["R", "B", "C"];
assert_isequal(R, REF);
%=============================================================================
