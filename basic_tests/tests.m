T = (1 + 1 == 2) == (1 == 1);
if ~T 
    disp('KO 1');
    quit
end
T = (1 + 1 == 3) == (0 == 1);
if ~T 
    disp('KO 2');
    quit
end

try
  1 + 1 == A
catch ex
  T = (ex.message == 'Undefined variable: A');
  if ~T 
    disp('KO 3');
    quit
   end
end

A = 3;
T = (A - 1) == 2;
if ~T
  disp('KO 4');
  quit
end
    
A = 1:10;

disp('basic tests OK');
quit