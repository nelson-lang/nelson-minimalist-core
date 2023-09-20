%=============================================================================
% Copyright (c) 2017-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
% <--ENGLISH IMPOSED-->
%=============================================================================
lasterror('reset');
S = getLastReport();
assert_isequal(S, '');
%=============================================================================
clear('a');
execstr('a','errcatch');
S = getLastReport();
REF = '
Error in execstr
Undefined variable or function: a

at line    17 of ''test_getLastReport.m''
';
assert_isequal(S, REF);
%=============================================================================