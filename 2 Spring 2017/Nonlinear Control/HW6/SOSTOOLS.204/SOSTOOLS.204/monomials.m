function Z = monomials(vartable,d)
% MONOMIALS --- Construct a vector of monomials with 
%       prespecified degrees.
%
% Z = monomials(VARTABLE,DEGREE)
%
% Given a vector of independent variables VARTABLE (can be either
% symbolic or polynomial objects) and a vector of non-negative 
% integers DEGREE, this function constructs a column vector 
% containing all possible monomials of degree described in DEGREE.
%
% For example, monomials([x1,x2],[1:3]) with x1 and x2 
% being symbolic variables will return monomials in x1 and 
% x2 of degree 1, 2, and 3.
%

% Alternative calling convention:
%
%  Z = monomials(n,d)
%
% Given two integers n and d, this function constructs 
% a vector containing all possible monomials of degree d 
% in n variables.
%
% n is the number of variables
% d is the degree of monomials
% Z is the monomial vector
%

% This file is part of SOSTOOLS - Sum of Squares Toolbox ver 2.00.
%
% Copyright (C)2002, 2004  S. Prajna (1), A. Papachristodoulou (1), P. Seiler (2),
%                          P. A. Parrilo (3)
% (1) Control and Dynamical Systems - California Institute of Technology,
%     Pasadena, CA 91125, USA.
% (2) Mechanical and Industrial Engineering Department - University of Illinois 
%     Urbana, IL 61801, USA
% (3) Institut fur Automatik - ETH Zurich, CH-8092 Zurich, Switzerland.
%
% Send bug reports and feedback to: sostools@cds.caltech.edu
%
% This program is free software; you can redistribute it and/or modify
% it under the terms of the GNU General Public License as published by
% the Free Software Foundation; either version 2 of the License, or
% (at your option) any later version.
%
% This program is distributed in the hope that it will be useful,
% but WITHOUT ANY WARRANTY; without even the implied warranty of
% MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
% GNU General Public License for more details.
%
% You should have received a copy of the GNU General Public License
% along with this program; if not, write to the Free Software
% Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
%


% 12/08/01 - SP
% 03/01/02 - SP -- Symbolic monomial


i = find(d<0);
if ~isempty(i)
    error('Negative degree.');
end;

Z = [];
for i = d
    Z = [Z; oldconstructZ(vartable,i)];
end;

% ==================================================================
function Z = oldconstructZ(vartable,d)
% Old constructZ

if isnumeric(vartable)
    n = vartable;
else
    n = length(vartable);
end;

ZZ = sparse(1,n);
for i = 1:n
    ss = size(ZZ,1);
    ZZ = sprepmat(ZZ,d+1,1);
    for j = 0:d
        ZZ(ss*j+1:ss*j+ss,i) = j;
    end;
    idx = find(sum(ZZ,2) <= d);   % Throw away invalid monomials
    ZZ = ZZ(idx,:);
end;
idx = find(sum(ZZ,2) == d);
Z = ZZ(idx,:);

if isa(vartable,'sym')
    Z = mysympower(vartable,Z);
elseif isa(vartable,'polynomial')
  coefftemp = speye(size(Z,1));
  Z = polynomial(coefftemp,Z,vartable.varname,[size(Z,1),1]);
end;


        
