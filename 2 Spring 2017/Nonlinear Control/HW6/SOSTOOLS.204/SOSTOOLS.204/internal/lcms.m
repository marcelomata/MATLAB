function g = lcms(L);
% Computes the LCM of a list of numbers
% Inefficient, but doesn't matter...
%

n  = length(L);
g = 1 ;
for k = 1:n; 
    g = lcm(g,L(k));
end
