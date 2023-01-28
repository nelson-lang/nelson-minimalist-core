%=============================================================================
% Copyright (c) 2017 Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
function ME = fun_MException_1()
  ME = test1();
end
%=============================================================================
function ME = test1();
  ME = test2();
end
%=============================================================================
function ME = test2();
  ME = test3();
end
%=============================================================================
function ME = test3()
  ME = MException('sayHello:inputError','Input must be char.');
end
%=============================================================================