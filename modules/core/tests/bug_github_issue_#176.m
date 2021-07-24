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
% <-- Issue URL -->
% https://github.com/Nelson-numerical-software/nelson/issues/176
% <-- Short Description -->
% nfilename did not return canonical path name in some cases.
%=============================================================================
cd([nelsonroot(), '/modules/core/tests']);
run('nfilename_#176.m');
%=============================================================================
REF1 = 'nfilename_#176';
assert_isequal(R1, REF1);
%=============================================================================
REF2 = [pwd(), '/', 'nfilename_#176'];
assert_isequal(R2, REF2);
%=============================================================================
REF3 = [pwd(), '/', 'nfilename_#176.m'];
assert_isequal(R3, REF3);
%=============================================================================