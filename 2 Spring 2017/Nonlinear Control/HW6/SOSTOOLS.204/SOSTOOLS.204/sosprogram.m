function sos = sosprogram(vartable,decvartable)
% SOSPROGRAM --- Initialize a new sum of squares program.
%
% SOSP = sosprogram(VARTABLE,DECVARTABLE)
%
% SOSP is a new sum of squares program. 
% VARTABLE is a vector of independent variables.
% DECVARTABLE is a vector of decision variables (optional).
%
% Both VARTABLE and DECVARTABLE are either symbolic or polynomial objects.
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


% 12/24/01 - SP
% 01/07/02 - SP
% 02/21/02 - SP -- Symbolic polynomial
% 10/10/02 - SP -- Path checking 

if ~exist('sedumi') & ~exist('sqlp')
    error('Neither SeDuMi nor SDPT3 is installed.');
end;

if ~exist('getpolysym')
    dd = which('sosprogram');
    dd = strrep(dd,'/sosprogram.m','/');
    dd = strrep(dd,'\sosprogram.m','\');
    pp = genpath(dd);
    addpath(pp);
end;

if isa(vartable,'sym')

	sos.var.num = 0;
	sos.var.type = {};
	sos.var.Z = {};
	sos.var.ZZ = {};
	sos.var.T = {};
	
	sos.expr.num = 0;
	sos.expr.type = {};
	sos.expr.At = {};
	sos.expr.b = {};
	sos.expr.Z = {};
	
	sos.extravar.num = 0;
	sos.extravar.Z = {};
	sos.extravar.ZZ = {};
	sos.extravar.T = {};
	sos.extravar.idx = {};
	
	sos.objective = [];        % 01/07/02
	
	sos.solinfo.x = [];
	sos.solinfo.y = [];
	sos.solinfo.RRx = [];
	sos.solinfo.RRy = [];
	sos.solinfo.info = [];
	
	sos.vartable = sym2chartable(vartable);    % 02/21/02
	if size(vartable,2) > 1
        vartable = vartable.';
	end;
	sos.symvartable = vartable;
	
	if (nargin == 2 & ~isempty(decvartable))
        sos.objective = sparse(length(decvartable),1);
        sos.decvartable = sym2chartable(decvartable);     % 03/01/02
        if size(decvartable,2) > 1
            decvartable = decvartable.';
        end;
        sos.symdecvartable = decvartable;
        sos.var.idx{1} = length(find(sos.decvartable==','))+2;
	else
        sos.decvartable = '[]';
        sos.symdecvartable = [];
        sos.var.idx{1} = 1;
	end;

else
    
	sos.var.num = 0;
	sos.var.type = {};
	sos.var.Z = {};
	sos.var.ZZ = {};
	sos.var.T = {};
	
	sos.expr.num = 0;
	sos.expr.type = {};
	sos.expr.At = {};
	sos.expr.b = {};
	sos.expr.Z = {};
	
	sos.extravar.num = 0;
	sos.extravar.Z = {};
	sos.extravar.ZZ = {};
	sos.extravar.T = {};
	sos.extravar.idx = {};
	
	sos.objective = [];        % 01/07/02
	
	sos.solinfo.x = [];
	sos.solinfo.y = [];
	sos.solinfo.RRx = [];
	sos.solinfo.RRy = [];
	sos.solinfo.info = [];
    
    sos.vartable = sort(vartable.varname);
	
	if (nargin == 2 & ~isempty(decvartable))
        sos.objective = sparse(length(decvartable),1);
        sos.decvartable = sort(decvartable.varname);     
        sos.var.idx{1} = length(decvartable)+1;
	else
        sos.decvartable = {};
        sos.var.idx{1} = 1;
	end;
    
end;



