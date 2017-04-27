function sos = sosconstr(sos,Type,symexpr)
% SOSCONSTR --- Add a new constraint (equality/inequality) 
%    to an SOS program 
%
% SOSP = sosconstr(SOSP,TYPE,EXPR)
%
% SOSP is the sum of squares program.
% The new constraint is described by TYPE as follows:
%   TYPE = 'eq'   : constraint is an equality, viz., f(x) = 0
%   TYPE = 'ineq' : constraint is an inequality, viz., f(x) >= 0 (an SOS)
% EXPR is the expression in the left hand side of the constraint, i.e., f(x).
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


% 12/24/01 - SP
% 03/01/02 - SP -- New syntax
% 04/06/03 - PJS -- Handle poly objects w/out for-loops

sos.expr.num = sos.expr.num+1;
expr = sos.expr.num;
sos.expr.type{expr} = Type;


if isfield(sos,'symvartable')

  [sos.expr.At{expr},sos.expr.b{expr},sos.expr.Z{expr}] = ...
      getequation(char(symexpr),sos.vartable,sos.decvartable);
    
else

  % Pull out information from the polynomial
  coef = symexpr.coefficient;
  deg = symexpr.degmat;
  var = symexpr.varname;
    
  % Sort variables: decision stacked on non-decision
  [dummy,idxdvar1,idxdvar2] = intersect(var,sos.decvartable);
  ldv = length(idxdvar1);
  [dummy,idxvar1,idxvar2] = intersect(var,sos.vartable);
  var = var([idxdvar1; idxvar1]);
  deg = deg(:,[idxdvar1; idxvar1]);
  
  % Sort terms: Stack terms without decision variables above 
  % terms with decision variables.
  [deg,sortidx] = sortrows(deg);
  coef = coef(sortidx);
  if ldv~=0
    [idx,dummy1]=find( deg(:,1:ldv) );
    nvterm = min(idx)-1;
  else
    nvterm = size(deg,1);
  end
  D12 = deg(1:nvterm,ldv+1:end);
  D22 = deg(nvterm+1:end,ldv+1:end);    
  D21 = deg(nvterm+1:end,1:ldv);
  
  % Get the equality constraints    
  if any( sum(D21,2) > 1 )
    error(['The expression is not linear in the decision' ...
	   ' variables']);
  else
    % Extract monomials
    [Ztemp,idx1,idx2] = unique([D12; D22],'rows');
    lZ = size(Ztemp,1);
    sos.expr.Z{expr} = sparse(lZ,length(sos.vartable));
    sos.expr.Z{expr}(:,idxvar2) = Ztemp;
    
    % Form the equality constraints
    Ac = sparse(length(sos.decvartable),lZ);
    b = sparse(lZ,1);
    
    % If symexpr has not been combined down, need to check that
    % idx2(1:nvterm) are all unique....
    b(idx2(1:nvterm)) = coef(1:nvterm);
    if ldv~=0
      [dv,dummy]=find(D21');      
      tempidx = sub2ind(size(Ac), idxdvar2(dv) , idx2(nvterm+1:end) );
      Ac(tempidx) = coef(nvterm+1:end);
    end
    
    sos.expr.At{expr} = -Ac; 
    sos.expr.b{expr} = b;
  end

% $$$   % Extract degmat and sort the terms according to degmat     
% $$$   [dummy,idxvar1,idxvar2] = intersect(symexpr.varname,sos.vartable);
% $$$   [Ztemp,idx1,idx2] = unique(sparse(symexpr.degmat(:,idxvar1)),'rows');
% $$$   sos.expr.Z{expr} = sparse(size(Ztemp,1),length(sos.vartable));
% $$$   sos.expr.Z{expr}(:,idxvar2) = Ztemp;
% $$$   
% $$$   % Now get the coefficients
% $$$   Ac = sparse(length(sos.decvartable),size(sos.expr.Z{expr},1));
% $$$   b = sparse(size(sos.expr.Z{expr},1),1);
% $$$   
% $$$   [dummy,idxdecvar1,idxdecvar2] = ... 
% $$$       intersect(symexpr.varname,sos.decvartable);
% $$$   for i = 1:size(Ztemp,1)
% $$$     
% $$$     for j = find(idx2==i)'         % These are the terms corresponding to the i-th row of Ztemp
% $$$       k = find(symexpr.degmat(j,idxdecvar1)==1);
% $$$       if isempty(k)
% $$$ 	b(i) = symexpr.coefficient(j);
% $$$       elseif length(k)>1
% $$$ 	error('The expression is not linear in the decision variables');
% $$$       else
% $$$ 	Ac(idxdecvar2(k),i) = symexpr.coefficient(j);
% $$$       end;
% $$$     end;
% $$$   end;
% $$$   
% $$$   sos.expr.At{expr} = -Ac; 
% $$$   sos.expr.b{expr} = b;
% $$$ end  

end



