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
function r = complexObj_extraction(obj, varargin)
  disp('complexObj_extract:')
  disp('nargin')
  disp(nargin)
  disp('nargout')
  disp(nargout)
  disp(varargin)
  n = numel(varargin);
  switch (n)
    case 1
      s = struct(obj);
      f = varargin{1};
      if ischar(f)
        r = s.(f);
      elseif isnumeric(f)
        s.r = f;
        r = class(s, 'complexObj');
      else
        error(_('not managed.'));
      end
    case 2
      f1 = varargin{1};
      f2 = varargin{2};
      if isnumeric(f1) && isnumeric(f2)
        s = struct(obj);
        s.r = f1;
        s.i = f2;
        r = class(s, 'complexObj')
        disp('ici')
      else
        error(_('not managed.'));
      end
    otherwise
      error(_('not managed.'));
    end
end
