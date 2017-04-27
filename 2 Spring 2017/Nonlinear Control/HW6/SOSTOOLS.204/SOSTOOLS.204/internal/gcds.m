function g = lcms(L);
% Computes the GCD of a list of numbers
% Inefficient, but doesn't matter...
%
n  = length(L);
g = L(1) ;
for k = 1:n; 
    g = gcd(g,L(k));
end
