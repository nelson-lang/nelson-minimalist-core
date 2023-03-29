%=============================================================================
% Copyright (c) 2017 Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
this_file = mfilename('fullpathext');
this_path = fileparts(this_file, 'path');
addpath(this_path);
ME = fun_MException_3(true);
assert_isequal(ME.message, 'Input must be char.');
assert_isequal(ME.identifier, 'sayHello:inputError');
assert_isequal(class(ME.stack), 'struct')
n = numel(ME.stack);
if n == 3 || n == 6
  assert_isequal(ME.stack(1).name, 'fun_MException_3')
  assert_isequal(ME.stack(1).line, 12)
end
%=============================================================================
