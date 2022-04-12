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
if ispc()
  MSGFMT = ['"', nelsonroot(), '/tools/gettext/bin/msgfmt.exe', '"'];
else
  if ismac()
    MSGFMT = '/usr/local/bin/msgfmt';
    if ~isfile(MSGFMT)
      MSGFMT = 'msgfmt';
    end
  else
    MSGFMT = 'msgfmt';
  end
end

DOMAIN = 'nelson';

pot_en_US = [nelsonroot(), '/locale/nelson.pot'];
po_en_US = [nelsonroot(), '/locale/en_US/LC_MESSAGES/nelson.po'];
if ~isfile(po_en_US)
  status = mkdir([nelsonroot(), '/locale/en_US/LC_MESSAGES']);
  copyfile(pot_en_US, po_en_US);
end

langs = getavailablelanguages();

for l = langs(:)'
  posrc = [nelsonroot(), '/locale/', l{1}, '/LC_MESSAGES/', DOMAIN, '.po'];
  modst = [nelsonroot(), '/locale/', l{1}, '/LC_MESSAGES/', DOMAIN, '.mo'];
  dir_posrc = dir(posrc);
  dir_modst = dir(modst);
  needToUpdate = true;
  if ~isempty(dir_posrc)
    if ~isempty(dir_modst)
      if dir_modst.datenum > dir_posrc.datenum
        needToUpdate = false;
      end
    end
    if needToUpdate
      disp([_('Update translations:'), ' ', l{1}]);
      MSGFMT_CMD = [MSGFMT, ' --output-file="', modst, '" "', posrc, '"'];
      [r, errmsg] = unix(MSGFMT_CMD);
      if r != 0
        warning(errmsg);
      end
    else
      disp([_('Translations up-to-date:'), ' ', l{1}]);
    end
  end
end

exit
%=============================================================================
