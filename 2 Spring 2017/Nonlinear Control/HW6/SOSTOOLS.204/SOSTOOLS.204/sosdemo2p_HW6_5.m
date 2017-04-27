% SOSDEMO2 --- Lyapunov Function Search 
% Section 3.2 of SOSTOOLS User's Manual
% 

clc
clear; echo on;

lambda = 0;
pvar x1 x2;
vars = [x1; x2];

% Constructing the vector field dx/dt = f
f = [-x2;x1 + (x1^4 - 2)*x2];

% =============================================
% First, initialize the sum of squares program
prog = sosprogram(vars);

% =============================================
% V function:
P = [1 0;0 1];
V = [x1 x2]*P*[x1;x2]

% =============================================
% S function: 
[prog,s] = sospolyvar(prog,monomials([x1,x2],[1,2,3,4]),'wscoeff');
% =============================================
% Next, define SOSP constraints

% Constraint 1 : V(x) - (x1^2 + x2^2 + x3^2) >= 0
prog = sosineq(prog,s-(x1^2+x2^2));

% Constraint 2: -dV/dx*(x3^2+1)*f >= 0
expr = -(diff(V,x1)*f(1)+diff(V,x2)*f(2));
l = 1e-6*(x1^2 + x2^2);
prog = sosineq(prog,-(l+expr) + s*(V-lambda));

% =============================================
% And call solver
prog = sossolve(prog);

% =============================================
% Finally, get solution
V = sosgetsol(prog,s)

echo off;
