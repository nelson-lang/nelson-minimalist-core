%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
% <--ADV-CLI MODE-->
% <--WITH DISPLAY-->
%=============================================================================
if semver(qt_version(), '>=6.0')
  qml_file_ok = [modulepath('qml_engine'), '/tests/test_qml_loadfile_window_qt6.qml'];
else
  qml_file_ok = [modulepath('qml_engine'), '/tests/test_qml_loadfile_window_qt5.qml'];
end
qobj = qml_loadfile(qml_file_ok);
%=============================================================================
R = evalc('disp(qobj)');
%=============================================================================
R = evalc('display(qobj)');
%=============================================================================
delete(qobj);
%=============================================================================