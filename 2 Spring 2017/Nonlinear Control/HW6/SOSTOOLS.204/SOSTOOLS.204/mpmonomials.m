function Z = mpmonomials(vars,deg)
% MPMONOMIALS --- Construct a vector of multipartite monomials
%       with prespecified degrees.
%
% Z = mpmonomials(VARTABLE,DEGREE)
% 
% Given cells of independent variable vectors VARTABLE and
% cells of non-negative integer vectors DEGREE, this function
% constructs a column vector containing all possible 
% multipartite monomials of degree described in DEGREE.
% 
% For example, mpmonomials({[x1,x2],[x3]},{[2],[3:4]})
% will return bipartite monomials whose degree in
% x1 and x2 are 2, and whose degree in x3 are 3 and 4.
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

% 03/12/03 -- SP

Z1 = 1;
for i = 1:length(vars)
    Z1 = Z1*monomials(vars{i},deg{i}).';
    Z1 = Z1(:);
end;
Z = Z1;
    
