function [Q,Z,Den] = findsos(p,flag)
% FINDSOS --- Find a sum of squares decomposition of a given polynomial.
%
% [Q,Z] = findsos(P)
%
% P is a scalar polynomial.
% A positive semidefinite Q and a symbolic monomial vector Z will be 
% computed such that
% 
%    Z' * Q * Z = P
%
% If P is not a sum of squares, the function will return empty Q and Z.
%
% If P is a polynomial with integer coefficients and is represented as a 
% symbolic object, then [Q,Z] = findsos(P,'rational') will compute a rational 
% matrix Q such that Z'*Q*Z = P.
% 
% If P is a polynomial object, then [Q,Z,D] = findsos(P,'rational') will
% compute an integer matrix Q and an integer D such that Z'*(Q/D)*Z = P.
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

if isa(p,'sym')

   p = expand(p);
   vars = findsym(p);
   vars = sym(['[',vars,']']);

   nvars = size(vars,2) ; 

   % Can change, to call maple only once.
   for var = 1:nvars;
       if rem(double(maple('degree',p,vars(var))),2) ;
       disp(['Degree in ' char(vars(var)) ' is not even. The polynomial cannot be a sum of squares']);
       Q = [];
       Z = [];
       return;
       end;
   end;

else

   varname = p.var;
   vars = [];
   for i = 1:size(varname,1)
       pvar(varname{i});
       vars = [vars eval(varname{i})];
   end;

   deg = mod(max(p.degmat,[],1),2);
   if sum(deg)~=0
       i = find(deg~=0);
       disp(['Degree in ' varname{i(1)} ' is not even. The polynomial cannot be a sum of squares']);
       Q = [];
       Z = [];
       return;
   end;

end;

prog = sosprogram(vars);
prog = sosineq(prog,p,'sparse');
[prog,info] = sossolve(prog);

if (info.dinf==1)|(info.pinf==1)
    disp('No sum of squares decomposition is found.');
    Q = [];
    Z = [];
    return;
else
    Q = reshape(prog.solinfo.RRx,sqrt(length(prog.solinfo.RRx)),sqrt(length(prog.solinfo.RRx)));
    if isa(p,'sym');
       Z = mysympower(vars,prog.extravar.Z{1});
    else
       pvar Z
       coefftemp = speye(size(prog.extravar.Z{1},1));
       Z = polynomial(coefftemp,prog.extravar.Z{1},prog.vartable,[size(prog.extravar.Z{1},1),1]);
    end;
end;

if nargin > 1 & strcmp(flag,'rational')

    A = (full(prog.expr.At{1})') ;
    B = (full(prog.expr.b{1})) ;
    % Round x0
    N = 1 ; % This is the tolerance in the rounding
    xx = prog.solinfo.x;
    
    kmax = 10 ;
    pd = 0 ;
    while kmax ~= 0 ;
        kmax = kmax - 1 ; 
        x0 = round(N*xx); 
        [Qflat,NN] = proj3(x0,A,B,N);
        n = sqrt(length(Qflat));
        Qr = reshape(Qflat,n,n);
        % Qr should be PSD (should really check symbolically)
        if min(eig(Qr/NN))>-1e-14 ; kmax=0 ; pd = 1 ; end
        % Increase N, and try again
        N = 2*N ; 
    end
    
    % Experimental, no good error checking yet, so we check that
    % expand(NN*p - Z.'*Qr*Z) is zero!
    
    if (expand(NN*p-Z.'*Qr*Z) ~= 0) | (pd == 0);
        Qr=[];Z=[];NN=[];
        disp('Could not compute a rational SOS!');
    end

    if nargout == 3
        Q = Qr;
        Den = NN;
    else
        if isa(p,'sym')
            Q = sym(Qr/NN);
        else
            Q = Qr/NN;
            disp('To obtain an exact rational solution, run the function with three output arguments.');
        end;
    end;
    
end;

