%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
assert_isequal(nargin('strfind'), 2);
assert_isequal(nargout('strfind'), 1);
%=============================================================================
k = strfind('', '');
ref = [];
assert_isequal(k, ref);
%=============================================================================
k = strfind('', 'bb');
ref = [];
assert_isequal(k, ref);
%=============================================================================
k = strfind('aaaa', '');
ref = [];
assert_isequal(k, ref);
%=============================================================================
S = 'Find the starting indices of the pattern string';
k = strfind(S, 'in');
ref = [2    15    19    45];
assert_isequal(k, ref);
%=============================================================================
S = 'Find the starting indices of the pattern string';
k = strfind(S, 'In');
ref = [];
assert_isequal(k, ref);
%=============================================================================
S = 'Find the starting indices of the pattern string';
k = strfind(S, ' ');
ref = [5     9    18    26    29    33    41];
assert_isequal(k, ref);
%=============================================================================
idx = strfind('aaaa', 5);
ref = [];
assert_isequal(idx, ref);
%=============================================================================
idx = strfind([], []);
ref = [];
assert_isequal(idx, ref);
%=============================================================================
idx = strfind('', '1');
ref = [];
assert_isequal(idx, ref);
%=============================================================================
idx = strfind('aaaa','aa');
ref = [ 1 2 3 ];
assert_isequal(idx, ref);
%=============================================================================
idx = strfind(ones(1,3), []);
ref = [];
assert_isequal(idx, ref);
%=============================================================================
idx = strfind(5,'aa');
ref = [];
assert_isequal(idx, ref);
%=============================================================================
c1 = 'time';
c2 = {'Once','upon';
'a','time'};
assert_checkerror('r = strfind(c1, c2);', _('Second argument a single string expected.'));
assert_checkerror('idx = strfind(ones(3,0), []);', _('Input strings must have one row.'));
assert_checkerror('idx = strfind([], {});', _('Second argument a single string expected.'));
assert_checkerror('k = strfind(''aaa'', {});', _('Second argument a single string expected.'));
assert_checkerror('idx = strfind({}, {});', _('Second argument a single string expected.'));
assert_checkerror('idx = strfind('''', {''''});', _('Second argument a single string expected.'));
assert_checkerror('idx = strfind(''aaaa'',[''a'';''a'']);', _('Second argument a single string expected.'));
assert_checkerror('strfind([''aaaa'';''bbbb''],{''aba'',''aa''})', _('Wrong type for argument #1: string or cell expected.'))
assert_checkerror('strfind()', _('Wrong number of input arguments.'));
expected_msg = _("'ForceCellOutput' expected as third input argument.");
assert_checkerror('strfind(''aaaa'', ''aa'', ''overlaps'', -1)', expected_msg);
%=============================================================================
S = "Find the starting indices of the pattern string";
k = strfind(S, "in");
ref = [2    15    19    45];
assert_isequal(k, ref);
%=============================================================================
idx = strfind(5, "aa");
ref = [];
assert_isequal(idx, ref);
%=============================================================================
