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
function h = errordlg(errorstring, dlgname, mode)
  if nargin < 1
    errorstring = _('This is the default error string.');
  else
      if nargin > 1
        if ~ischar(dlgname) && ~iscellstr(dlgname)
          error(_('Wrong type for argument #1: string expected.'));
        end
      end
  end

  if nargin < 2
    dlgname = _('Error Dialog');
  else
    if ~ischar(dlgname)
      error(_('Wrong type for argument #2: string expected.'));
    end
  end

  if nargin < 3
    mode = 'nonmodal';
  else
    if ~ischar(mode)
      error(_('Wrong type for argument #3: string expected.'));
    end
    if strcmp(mode, 'modal') == false && strcmp(mode, 'nonmodal') == false && strcmp(mode, 'on') == false
      error(_('Wrong value for argument #3: ''modal'', ''nonmodal'', ''on'' expected.'));
    end
  end

  if nargin > 3
    error(_('Wrong number of input arguments.'));
  end
  h = msgbox(errorstring, dlgname, 'error', mode);
end