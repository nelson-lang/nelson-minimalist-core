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
% <--INDEX 64 BIT REQUIRED-->
%=============================================================================
path_dest = [tempdir(), 'imwrite_bench'];
RES_8K = [7680, 4320];
IMG_8K = rand(RES_8K(1), RES_8K(2));
IMG_8K(:,:,2) = rand(RES_8K(1), RES_8K(2));
IMG_8K(:,:,3) = rand(RES_8K(1), RES_8K(2));
tic();imwrite(IMG_8K,[path_dest, '8K.png']);toc()
%=============================================================================