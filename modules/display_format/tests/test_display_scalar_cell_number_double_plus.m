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
format('+')
%=============================================================================
R = evalc('A = {-1}');
REF =   '
A =

  1×1 cell array

    {[-]}

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = {0}');
REF =   '
A =

  1×1 cell array

    {[]}

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = {1}');
REF =   '
A =

  1×1 cell array

    {[+]}

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = {NaN}');
REF =   '
A =

  1×1 cell array

    {[+]}

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = {-Inf}');
REF =   '
A =

  1×1 cell array

    {[-]}

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = {Inf}');
REF =   '
A =

  1×1 cell array

    {[+]}

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = {complex(pi, -pi)}');
REF =   '
A =

  1×1 cell array

    {[+]}

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = {complex(-pi, pi)}');
REF =   '
A =

  1×1 cell array

    {[-]}

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = {complex(1.8e99, -eps)}');
REF =   '
A =

  1×1 cell array

    {[+]}

';
assert_isequal(R, REF)
%=============================================================================
