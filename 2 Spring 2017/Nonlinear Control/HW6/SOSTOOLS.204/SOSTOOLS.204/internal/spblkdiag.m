function A = spblkdiag(A1,A2)
%SPBLKDIAG  Sparse block diagonal concatenation.
%
%   A = spblkdiag(A1,A2)  
%
% Given two sparse matrices A1 and A2, this function
% constructs their block diagonal concatenation
%
%        | A1 0  |
%  A =   |       |
%        | 0  A2 |
%
% where A is a sparse matrix.
%

% This file is part of SOSTOOLS - Sum of Squares Toolbox ver 1.00.
%
% Copyright (C) 2002  S. Prajna (1), A. Papachristodoulou (1), P. A. Parrilo (2)
% (1) Control and Dynamical Systems - California Institute of Technology,
%     Pasadena, CA 91125, USA.
% (2) Institut fur Automatik - ETH Zurich, CH-8092 Zurich, Switzerland.
%
% Send feedback to: sostools@cds.caltech.edu
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


% 12/12/01 -- SP

A = [A1 sparse(size(A1,1),size(A2,2));
    sparse(size(A2,1),size(A1,2)) A2];

if ~issparse(A)
    error('A is not sparse. Check the inputs.');
end;

