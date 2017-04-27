function [At,b,Z] = getequation(symexpr,vartable,decvartable)
% GETEQUATION --- Convert a symbolic expression to At, b, and Z
%         used in an SOS program.
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

% 03/01/02 - SP
% 03/10/02 - SP -- Use Maple


if strcmp(decvartable,'[]');
    decvarnum = 0;
else
    decvarnum = length(find(decvartable == ','))+1;
end;

maple(['expr:=',symexpr,':']);
maple(['vartable:=',vartable,':']);
maple(['decvartable:=',decvartable,':']);
maple(loadcomputeAcZ);
Z = ['[',maple('Z'),']'];
Z = getdegrees(Z,vartable);

% Constructing At and b matrices
At = sparse(decvarnum,size(Z,1));
for i = 1:decvarnum
    At(i,:) = -eval(maple(['[seq(diff(F[cidx],decvartable[',int2str(i),']),cidx=1..nequs)];']));
end;

%At = sparse(decvarnum,size(Z,1));
%if decvarnum > 0
%  for i = 1:size(Z,1)
%    At(:,i) = -eval(maple(['[seq(diff(F[',int2str(i),'],decvartable[cidx]),cidx=1..',int2str(decvarnum),')];']))';
%  end;
%end;
  
b = sparse(eval(maple('val;'))');




