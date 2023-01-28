%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
% <-- NO USER MODULES -->
%=============================================================================
assert_isequal(nargin('dllib_delete'), 1);
assert_isequal(nargout('dllib_delete'), 0);
%=============================================================================
path_ref = [modulepath(nelsonroot(),'dynamic_link','bin'), '/libnlsDynamic_link', getdynlibext()];
lib = dlopen(path_ref);
assert_istrue(isvalid(lib));
delete(lib);
assert_isfalse(isvalid(lib));
assert_isequal(size(dllib_used()), [0 0]);
%=============================================================================