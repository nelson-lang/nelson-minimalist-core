%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
arch = computer('arch');
%=============================================================================
R = roty(90);
REF =    [   0     0     1;     0     1     0;    -1     0     0];
if strcmp(arch, 'win32')
  assert_isapprox(R, REF, 1e-15);
else
  assert_isequal(R, REF);
end
%=============================================================================
R = roty(180);
REF = [-1     0     0;     0     1     0;     0     0    -1];
if strcmp(arch, 'win32')
  assert_isapprox(R, REF, 1e-15);
else
  assert_isequal(R, REF);
end
%=============================================================================
