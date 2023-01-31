%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
if strcmp(getnelsonmode(), 'BASIC_TERMINAL') == true
  addgateway(modulepath(nelsonroot(), 'mpi', 'builtin'), 'mpi');
end
addpath(modulepath(nelsonroot(), 'mpi', 'functions'), '-frozen');
%=============================================================================
