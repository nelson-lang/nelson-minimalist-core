%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
assert_isequal(nargin('mat2str'), -2);
assert_isequal(nargout('mat2str'), 1);
%=============================================================================
R = mat2str(int16([3, 4]), 4, 'class');
REF = 'int16([3 4])';
assert_isequal(R, REF);
%=============================================================================
R = mat2str(int16(eye(3, 4)), 4, 'class');
REF = 'int16([1 0 0 0;0 1 0 0;0 0 1 0])';
assert_isequal(R, REF);
%=============================================================================
R = mat2str(int16(eye(3, 4)));
REF = '[1 0 0 0;0 1 0 0;0 0 1 0]';
assert_isequal(R, REF);
%=============================================================================
R = mat2str(int16(eye(0, 0)));
REF = '[]';
assert_isequal(R, REF);
%=============================================================================
R = mat2str(int16(eye(0, 4)));
REF = 'zeros(0,4)';
assert_isequal(R, REF);
%=============================================================================
R = mat2str(int16(eye(0, 4)), 'class');
REF = 'int16(zeros(0,4))';
assert_isequal(R, REF);
%=============================================================================
R = mat2str(eye(3, 4) * pi, 'class');
REF = 'double([3.14159265358979 0 0 0;0 3.14159265358979 0 0;0 0 3.14159265358979 0])';
assert_isequal(R, REF);
%=============================================================================
R = mat2str(eps);
REF = '2.22044604925031e-16';
assert_isequal(R, REF);
%=============================================================================
R = mat2str([NaN Inf; 0 -Inf]);
REF = '[NaN Inf;0 -Inf]';
assert_isequal(R, REF);
%=============================================================================
R = mat2str(eps, 4);
REF = '2.22e-16';
assert_isequal(R, REF);
%=============================================================================
R = mat2str(complex(NaN, NaN));
REF = 'NaN+1i*NaN';
assert_isequal(R, REF);
%=============================================================================
R = mat2str(complex(NaN, Inf));
REF = 'NaN+1i*Inf';
assert_isequal(R, REF);
%=============================================================================
R = mat2str(complex(NaN, -Inf));
REF = 'NaN-1i*Inf';
assert_isequal(R, REF);
%=============================================================================
R = mat2str(complex(-Inf, -Inf));
REF = '-Inf-1i*Inf';
assert_isequal(R, REF);
%=============================================================================
R = mat2str(3i);
REF = '0+3i';
assert_isequal(R, REF);
%=============================================================================
R = mat2str([3.85 2.91; 7.74 8.99]);
REF = '[3.85 2.91;7.74 8.99]';
assert_isequal(R, REF);
%=============================================================================
R = mat2str(eye(3, 3) + i);
REF = '[1+1i 0+1i 0+1i;0+1i 1+1i 0+1i;0+1i 0+1i 1+1i]';
assert_isequal(R, REF);
%=============================================================================
assert_checkerror('mat2str()', _('Wrong number of input arguments.'));
assert_checkerror('mat2str(''nelson'')', _('type not supported.'));
assert_checkerror('mat2str(ones(8,9), [1 1])', _('A scalar expected.'));
assert_checkerror('mat2str(ones(2, 2, 3))', _('A 2D matrix expected.'));
assert_checkerror('R = mat2str([3.85 2.91; 7.74 8.99], 12,''class'', 3)', _('Wrong number of input arguments.'));
%=============================================================================

