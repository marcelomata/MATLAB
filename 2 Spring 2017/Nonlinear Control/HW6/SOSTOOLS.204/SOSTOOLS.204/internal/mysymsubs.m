function newexpr = mysymsubs(expr,old,new,digit)
% MYSYMSUBS --- Fast symbolic substitution.
%
% NEWEXPR = mysymsubs(EXPR,OLD,NEW,DIGIT)
%
% EXPR is symbolic/string.
% OLD is symbolic.
% NEW is numeric (column vector).
% DIGIT is the number of digits.
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

% 03/15/02 - SP

cc = ',';
expr = char(expr);
old = char(old);
old = strrep(old,'],[',',');
verstring = char(version);
if verstring(1) =='7'
    old = strrep(old,'matrix([','');
else
    old = strrep(old,'array([','');
end;
old = strrep(old,'])','');
if old(1)~='['
    old = ['[',old,']'];
end;

new = [cc(ones(length(new),1)),num2str(new,digit)];
new = reshape(new',1,prod(size(new)));
new = new(find(new~=' '));
new = ['[',new(2:end),']'];

maple(['expr :=',expr,':']);
maple(['old :=',old,':']);
maple(['new :=',new,':']);
maple('cidx2 := nops(new):');
newexpr = sym(maple('eval(expr,[seq(old[cidx1]=new[cidx1],cidx1=1..cidx2)]);'));