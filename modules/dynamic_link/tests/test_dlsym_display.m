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
% <-- NO USER MODULES -->
%=============================================================================
lib = dlopen([modulepath(nelsonroot(),'dynamic_link','bin'), '/libnlsDynamic_link', getdynlibext()]);
f = dlsym(lib, 'dynlibTestMultiplyDoubleArrayWithReturn', 'int32', {'doublePtr', 'int32'});
%=============================================================================
R = evalc('display(f)');
REF = '
f =

  1×1 handle [dlsym] 

  Prototype: string 1x79
  Input:     {doublePtr, int32}
  Output:    {int32, doublePtr}

';
assert_isequal(R, REF);
%=============================================================================
R = evalc('disp(f)');
REF = '  1×1 handle [dlsym] 

  Prototype: string 1x79
  Input:     {doublePtr, int32}
  Output:    {int32, doublePtr}
';
assert_isequal(R, REF);
%=============================================================================
