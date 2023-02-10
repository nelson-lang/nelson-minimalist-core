%=============================================================================
% Copyright (c) 2017 Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
function r = complexObj_plus_complexObj(a, b)
  % stupid addition algo.
  R1 = a.r + b.r;
  R2 = a.i + b.i;
  r = complexObj(R1, R2);
end
%=============================================================================