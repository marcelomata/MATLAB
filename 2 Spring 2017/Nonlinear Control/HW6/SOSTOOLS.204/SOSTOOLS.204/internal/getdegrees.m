function Znum = getdegrees(Z,vartable)
% GETDEGREES --- Get degrees of monomials.
%
% ZDEG = getdegrees(Z,VARTABLE)
%
% Z is a row vector of monomials (a string).
% VARTABLE is the row vector of independent variables (a string).
% ZDEG is the degree of Z (in SOSTOOLS notation).
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

% 03/21/02 - SP

numvars = length(find(vartable==','))+1;
nummonos = length(find(Z==','))+1;
maple(['vartable :=',vartable,':']);
maple(['Z :=',Z,':']);

Zchar = maple(['[seq(degree(Z[modp(cidx,',int2str(nummonos),')+1],',...
        'vartable[floor(cidx/',int2str(nummonos),')]),',...
        'cidx=',int2str(nummonos),'..',int2str(nummonos*(numvars+1)-1),')];']);

Zchar = strrep(Zchar,'[',', ');
idx1 = findstr([Zchar '   '],',');
idx2 = findstr([Zchar '   '],', 0');
[dummy,idx1] = setdiff(idx1,idx2);
Zchar = strrep(Zchar,', 0','');
Zchar = ['[',Zchar];
Zchar = strrep(Zchar,'[, ','[');

Znum = sparse(idx1,ones(1,length(idx1)),eval(Zchar),numvars*nummonos,1);
Znum = reshape(Znum,nummonos,numvars);

