%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% This program is free software; you can redistribute it and/or
% modify it under the terms of the GNU Lesser General Public
% License as published by the Free Software Foundation; either
% version 2.1 of the License, or (at your option) any later version.
%
% Alternatively, you can redistribute it and/or
% modify it under the terms of the GNU General Public License as
% published by the Free Software Foundation; either version 2 of
% the License, or (at your option) any later version.
%
% This program is distributed in the hope that it will be useful,
% but WITHOUT ANY WARRANTY; without even the implied warranty of
% MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
% GNU Lesser General Public License for more details.
%
% You should have received a copy of the GNU Lesser General Public
% License along with this program. If not, see <http://www.gnu.org/licenses/>.
% LICENCE_BLOCK_END
%=============================================================================
addpath([fileparts(nfilename('fullpathext'), 'path'), '/loadsavebin']);
F = [nelsonroot(), '/modules/stream_manager/tests/test_loadbin.bin'];
REF_A = ones(5, 6);
REF_B = 'A string saved.';
REF_C = single(REF_A);
REF_D = int8(REF_A);
clear('A', 'B', 'C', 'D');
loadbin(F, 'A', 'B', 'C', 'D');
assert_isequal(A, REF_A);
assert_isequal(B, REF_B);
assert_isequal(C, REF_C);
assert_isequal(D, REF_D);
%=============================================================================