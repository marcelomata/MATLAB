function [x,NN] = proj2(x0,A,b,N); 
%
% Orthogonal projection of the point x0 onto the subspace Ax=b 
%
% Here, all rational data
% A is assumed fat, and full row rank
% A*A' is diagonal
%
% All integer computations
% The solution is x/NN, the input is x0/N
%
% Should revise it at some point.

%aa = (A*A');
aa = sum(A.*A,2);
N2 = lcms(unique(aa));
x = N2*x0 - A'*( (N2 ./aa) .* (A*x0-b*N)) ;

NN = N2*N;

% Make sure it's minimal
[dum1,dum2,nz]=find(unique(abs(x)));
cfact = gcds([nz ; NN]);
x = x/cfact ;
NN = NN/cfact ;
