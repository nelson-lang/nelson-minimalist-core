%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
F = str2func('cos');
assert_isequal(F(.5), cos(.5));
%=============================================================================
F = str2func('@cos');
assert_isequal(F(.5), cos(.5));
%=============================================================================
clear x
A = str2func('@(x) x*sqrt(x);');
R = eval('A(4);');
assert_isequal(R, 8);
B = A(4);
assert_isequal(B, R);
%=============================================================================
A = str2func('@(x) x*sqrt(x)');
R = eval('A(4)');
assert_isequal(R, 8);
B = A(4);
assert_isequal(B, 8);
%=============================================================================
A = str2func('@(x) disp(x+1)');
A(4);
assert_checkerror('B = A(4)', _('Wrong number of output arguments.'));
%=============================================================================
str = '@(x)7*x-13';
fh = str2func(str);
R = func2str(fh);
REF = '@(x)(7*x)-13'
assert_isequal(R, REF)
assert_isequal(fh(3), 8)
%=============================================================================
str = '@(x)7*x-13+a';
fh = str2func(str);
assert_checkerror('fh(3)', [_('Undefined variable:'), ' ', 'a']);
%=============================================================================
assert_checkerror('F = str2func(''@ (y) x= y+1'');', _('A valid function handle expected.'))
%=============================================================================
