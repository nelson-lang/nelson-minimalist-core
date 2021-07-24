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
assert_checkerror('cos', _('Wrong number of input arguments.'));
[r, msg] = assert_checkerror('cos', _('Wrong number of input arguments.'));
if (r ~= true)
  error(_('assert_checkerror fails.'));
end
if strcmp(msg, '') == false
  error(_('assert_checkerror fails.'));
end
%=============================================================================
[r, msg] = assert_checkerror('cos', 'Wrong number of input arguments2.');
if (r ~= false)
  error(_('assert_checkerror fails.'));
end
%=============================================================================
expectedmsg = [_('Assertion failed : expected error message ='), ' "', 'Wrong number of input arguments2.', '" ', _('computed error message ='), ' "', _('Wrong number of input arguments.'), '"'];
%=============================================================================
if strcmp(msg, expectedmsg) == false
  error(_('assert_checkerror fails.'));
end
%=============================================================================
assert_checkerror('mustBeFinite(NaN)', _('Value must be finite.'), 'Nelson:validators:mustBeFinite')