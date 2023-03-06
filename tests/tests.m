%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
tests_scritp_path = fileparts(mfilename('fullpathext'), 'path');
modules_path = fullpath([tests_scritp_path, '/../modules/']);
modules_subdirectories = dir(modules_path);
tests_directories = {};
for p = modules_subdirectories'
  tests_dir = [p.folder, '/', p.name, '/tests'];
  if isdir(tests_dir) && ~strcmp(p.name, '..')
    tests_directories = fullpath([tests_directories; tests_dir]);
  end
end
for tests_directory = tests_directories'
  files = dir([tests_directory{1}, '/test_*.m']);
  for file = files'
    tests_file = [file.folder, '/', file.name];
    try
      run(tests_file);
      fprintf('%s PASSED\n', file.name);
    catch
      fprintf('%s FAILED\n', file.name);
      exit(1);
    end
  end
end
exit(0);
