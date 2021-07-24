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
assert_isequal(nargin('isreal'), 1);
assert_isequal(nargout('isreal'), 1);
%=============================================================================
R = complex(13);
assert_isfalse(isreal(R));
%=============================================================================
R = complex([]);
assert_istrue(isreal(R));
%=============================================================================
R = complex([]);
assert_istrue(isreal(ones(3, 0)));
%=============================================================================
R1 = 3 + 14i;
R2 = 5 - 14i;
R = R1 + R2;
assert_isfalse(isreal(R1));
assert_isfalse(isreal(R2));
assert_istrue(isreal(R));
%=============================================================================
R1 = 3 - 14i;
R2 = 5 - 14i;
R = R2 - R1;
assert_isfalse(isreal(R1));
assert_isfalse(isreal(R2));
assert_istrue(isreal(R));
%=============================================================================
R = isreal(1+0i);
assert_istrue(R);
%=============================================================================
R = isreal([]);
assert_istrue(R);
%=============================================================================
R = isreal(complex([]));
assert_istrue(R);
%=============================================================================
R = isreal(complex(ones(3, 0)));
assert_isfalse(R);
%=============================================================================
R = isreal([1]);
assert_istrue(R);
%=============================================================================
R = isreal([1,2,3]);
assert_istrue(R);
%=============================================================================
R = isreal([1;2;3]);
assert_istrue(R);
%=============================================================================
R = isreal([1,2,3;4,5,6]);
assert_istrue(R);
%=============================================================================
R = isreal([i]);
assert_isfalse(R);
%=============================================================================
R = isreal([i,2i,3i]);
assert_isfalse(R);
%=============================================================================
R = isreal([i;2i;3i]);
assert_isfalse(R);
%=============================================================================
R = isreal([i,2i,3i;4i,5i,6i]);
assert_isfalse(R);
%=============================================================================
R = isreal(['s']);
assert_istrue(R);
%=============================================================================
R = isreal(['str1']);
assert_istrue(R);
%=============================================================================
R = isreal(['str1','str2','str3']);
assert_istrue(R);
%=============================================================================
R = isreal(['str1';'str2';'str3']);
assert_istrue(R);
%=============================================================================
R = isreal(['str1','str2','str3';'str4','str5','str6']);
assert_istrue(R);
%=============================================================================
R = isreal([[1]==[1]]);
assert_istrue(R);
%=============================================================================
R = isreal([[1,2,3]==[1,0,3]]);
assert_istrue(R);
%=============================================================================
R = isreal([[1;2;3]==[1;0;3]]);
assert_istrue(R);
%=============================================================================
R = isreal([[1,2,3;4,5,6]==[1,0,3;4,5,0]]);
assert_istrue(R);
%=============================================================================
R = isreal(rand(3,3,3));
assert_istrue(R);
%=============================================================================
R = isreal(sparse(4 + 3i));
assert_isfalse(R);
%=============================================================================
R = isreal(sparse(true));
assert_istrue(R);
%=============================================================================
R = isreal({});
assert_isfalse(R);
%=============================================================================
R = isreal(struct());
assert_isfalse(R);
%=============================================================================
R = single([3, i]);
assert_isfalse(isreal(R));
%=============================================================================
R = [3, i];
assert_isfalse(isreal(R));
%=============================================================================
R = [3, 0i];
assert_istrue(isreal(R));
%=============================================================================