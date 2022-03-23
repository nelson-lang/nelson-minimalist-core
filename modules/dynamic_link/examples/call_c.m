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
getpid_symbol = 'getpid';
if ispc()
  lib_c_name = ['msvcrt', getdynlibext()];
  libc = dlopen(lib_c_name)
else
  if isunix()
    % arch vs debian vs others
    lib_c_names = [string(['libc', getdynlibext()]), ...
                string(['/usr/lib64/libc', getdynlibext(), '.6']), ...
                string(['libc', getdynlibext(), '.6']), ...
                string(['/usr/lib/x86_64-linux-gnu/libc', getdynlibext()]), ...
                string(['/lib/x86_64-linux-gnu/libc', getdynlibext(), '.6'])];
    for l = lib_c_names
      lib_c_name = char(l);
      try
        libc = dlopen(lib_c_name);
        break
      catch
        libc = [];
      end
    end
    if isempty(libc)
      libc = dlopen(['libc', getdynlibext()]);
    end
  else
    % macos
    lib_c_name = ['libc', getdynlibext()];
    libc = dlopen(lib_c_name)
  end
end
% getpid C function from standard libc library
f = dlsym(libc, getpid_symbol, 'int32', {})
% call getpid
pid = dlcall(f)
% release handles
delete(f);
delete(libc);
% clear variables
clear f
clear libc
