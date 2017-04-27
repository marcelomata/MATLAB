function V = findlyap(f,vars,order)
% FINDLYAP --- Find a Lyapunov function V(x) for a simple polynomial 
%        dynamical system.
%
% V = findlyap(F,VARS,ORDER)
%
% F is the (polynomial) vector field  of the dynamical system. VARS is the
% variables of the system. F and VARS must be ordered such that
%
%    dVARS/dt = F
%
% ORDER is the desired order of the Lyapunov function (has to be  an even
% integer).
% 
% A polynomial Lyapunov function V will be computed such that
% 
%    V is positive definite, radially unbounded. dV/dt is negative
%    semidefinite along the system trajectory.
% 
% If no such Lyapunov function exists, the function will return  empty V.
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


% 12/27/01 - SP
% 03/27/02 - SP

if order<2
    error('Order has to be at least 2.');
end;
if rem(order,2)
    error('Order is not even.');
end;
if length(vars)~=length(f)
    error('F and VARS have different length.');
end;

if size(vars,1)>1
    vars = vars.';
end;

prog = sosprogram(vars);
[prog,V] = sospolyvar(prog,monomials(vars,[2:order]));

% Positive definiteness condition
expr1 = V;
for i = 1:length(vars)
    expr2 = -0.1;
    for j = 2:2:order
        [prog,epsmat(i,j/2)] = sossosvar(prog,1);
        expr2 = expr2 + epsmat(i,j/2);
    end;
    prog = sosineq(prog,expr2);
    if isfield(prog,'symvartable')
       expr1 = expr1 - epsmat(i,:) * mysympower(vars(i),[2:2:order]');
    else
       expr1 = expr1 - epsmat(i,:) * (vars(i).^[2:2:order]');
    end;
end;
prog = sosineq(prog,expr1);

% Condition on derivative
expr1 = 0;
for i = 1:length(vars)
    expr1 = expr1 - diff(V,vars(i))*f(i);
end;
prog = sosineq(prog,expr1);

[prog,info] = sossolve(prog);
if (info.dinf==1)|(info.pinf==1)
    disp('No Lyapunov function has been found for this system.');
    V = [];
else
    V = sosgetsol(prog,V);
end;





