%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
assert_isequal(nargin('fullfile'), -1);
assert_isequal(nargout('fullfile'), 1);
%=============================================================================
R = fullfile([]);
REF = '';
assert_isequal(R, REF);
%=============================================================================
R = fullfile('');
REF = '';
assert_isequal(R, REF);
%=============================================================================
R = fullfile('.');
REF = '.';
assert_isequal(R, REF);
%=============================================================================
R = fullfile("rr");
REF = "rr";
assert_isequal(R, REF);
%=============================================================================
R = fullfile(["rr", string(NaN)]);
REF = ["rr", ""];
assert_isequal(R, REF);
%=============================================================================
R = fullfile(string(NaN));
REF = "";
assert_isequal(R, REF);
%=============================================================================
% error
CMD = 'fullfile( {''data''; ''data2''}, {''f1.csv'', ''data2''})';
MSG = _('All string and cell array inputs must be the same size or scalars.');
assert_checkerror(CMD, MSG);
%=============================================================================
CMD = 'fullfile( {''data''; ''data2''}, ''data2'', {''f1.csv'', ''data2''})';
MSG = _('All string and cell array inputs must be the same size or scalars.');
assert_checkerror(CMD, MSG);
%=============================================================================
CMD = 'fullfile(''/home/username'', {''data''; ''data2''}, ''data2'', {''f1.csv'', ''data2''})';
MSG = _('All string and cell array inputs must be the same size or scalars.');
assert_checkerror(CMD, MSG);
%=============================================================================
CMD = 'fullfile(''/home/username'', {''d'', ''f''; ''d'', ''f''}, {''f'', ''d''})';
MSG = _('All string and cell array inputs must be the same size or scalars.');
assert_checkerror(CMD, MSG);
%=============================================================================
