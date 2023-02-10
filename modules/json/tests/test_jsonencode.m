%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
r = jsonencode(char(13));
ref = '"\r"';
assert_isequal(r, ref);
%=============================================================================
r = jsonencode(char(10));
ref = '"\n"';
assert_isequal(r, ref);
%=============================================================================
r = jsonencode('"');
ref = '"\""';
assert_isequal(r, ref);
%=============================================================================
r = jsonencode('\r');
ref = '"\\r"';
assert_isequal(r, ref);
%=============================================================================
r = jsonencode('\n');
ref = '"\\n"';
assert_isequal(r, ref);
%=============================================================================
r = jsonencode('\\');
ref = '"\\\\"';
assert_isequal(r, ref);
%=============================================================================
r = jsonencode(ones(3,0));
ref = '[]';
assert_isequal(r, ref);
%=============================================================================
r = jsonencode({});
ref = '[]';
assert_isequal(r, ref);
%=============================================================================
r = jsonencode([]);
ref = '[]';
assert_isequal(r, ref);
%=============================================================================
field1 = 'f1';  value1 = zeros(1,10);
field2 = 'f2';  value2 = {'a', 'b'};
field3 = 'f3';  value3 = {pi, pi*pi};
field4 = 'f4';  value4 = {'fourth'};
s = struct(field1,value1,field2,value2,field3,value3,field4,value4);
r = jsonencode(s);
ref = '[{"f1":[0,0,0,0,0,0,0,0,0,0],"f2":"a","f3":3.141592653589793,"f4":"fourth"},{"f1":[0,0,0,0,0,0,0,0,0,0],"f2":"b","f3":9.869604401089358,"f4":"fourth"}]';
assert_isequal(r, ref);
%=============================================================================
r = jsonencode(['Nel'; 'Son']);
ref = '["Nel","Son"]';
assert_isequal(r, ref);
%=============================================================================
r = jsonencode([1,2,3;4,5,6;7,8,9]);
ref = '[[1,2,3],[4,5,6],[7,8,9]]';
assert_isequal(r, ref);
%=============================================================================
r = jsonencode(char(20));
ref =  '"\u0014"';
assert_isequal(r, ref);
%=============================================================================
r = jsonencode(reshape(char([22,20,32;42,52,62;72,82,92]),1,3,3));
ref = '["\u0016*H","\u00144R"," >\\"]';
assert_isequal(r, ref);
%=============================================================================
r = jsonencode(reshape([1,2,3;4,5,6;7,8,9],1,3,3));
ref = '[[1,2,3],[4,5,6],[7,8,9]]';
assert_isequal(r, ref);
%=============================================================================
r = jsonencode(char([22,20,32;42,52,62;72,82,92]));
ref = '["\u0016\u0014 ","*4>","HR\\"]';
assert_isequal(r, ref);
%=============================================================================
r = jsonencode(true);
ref = 'true';
assert_isequal(r, ref);
%=============================================================================
r = jsonencode([true,false,false]);
ref = '[true,false,false]';
assert_isequal(r, ref);
%=============================================================================
r = jsonencode(logical([1, 0, 0, 1, 1, 0]));
ref = '[true,false,false,true,true,false]';
assert_isequal(r, ref);
%=============================================================================
r = jsonencode('漢字');
ref = '"漢字"';
assert_isequal(r, ref);
%=============================================================================
r = jsonencode('');
ref = '""';
assert_isequal(r, ref);
%=============================================================================
r = jsonencode(2.6);
ref = '2.6';
assert_isequal(r, ref);
%=============================================================================
r = jsonencode(1:3);
ref =  '[1,2,3]';
assert_isequal(r, ref);
%=============================================================================
r = jsonencode(eye(4));
ref = '[[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]]';
assert_isequal(r, ref);
%=============================================================================
r = jsonencode({'B',true,[22;32]});
ref = '["B",true,[22,32]]';
assert_isequal(r, ref);
%=============================================================================
r = jsonencode(struct('a','value'));
ref = '{"a":"value"}';
assert_isequal(r, ref);
%=============================================================================
r = jsonencode(struct('aa',{true,true,false,false}));
ref = '[{"aa":true},{"aa":true},{"aa":false},{"aa":false}]';
assert_isequal(r, ref);
%=============================================================================
r = jsonencode([1,2,NaN,3,Inf, -Inf]);
ref = '[1,2,null,3,null,null]';
assert_isequal(r, ref);
%=============================================================================
r = jsonencode([1,2,NaN,3,Inf, -Inf],'ConvertInfAndNaN',true);
ref = '[1,2,NaN,3,Inf,-Inf]';
assert_isequal(r, ref);
%=============================================================================
r = jsonencode([1,2,NaN,3,Inf, -Inf],'ConvertInfAndNaN',false);
ref = '[1,2,null,3,null,null]';
assert_isequal(r, ref);
%=============================================================================