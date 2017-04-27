function ZTemp = mysympower(vartable,Z);
% MYSYMPOWER --- Fast symbolic power.
%
% ZSYM = mysympower(VARTABLE,ZNUM)
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

ZTemp = '[';
for j = 1:size(Z,1)
    idx = find(Z(j,:));
    charexpr = [];
    for i = idx
        if Z(j,i)>1
            charexpr = [charexpr,char(vartable(i)),'^',int2str(Z(j,i)),'*'];
        else
            charexpr = [charexpr,char(vartable(i)),'*'];    
        end;
    end;
    if isempty(idx)
        charexpr = '1*';
    end;
    charexpr = [charexpr(1:end-1),';'];
    ZTemp = [ZTemp,charexpr];
end;    
ZTemp = [ZTemp(1:end-1),']'];
ZTemp = sym(ZTemp);