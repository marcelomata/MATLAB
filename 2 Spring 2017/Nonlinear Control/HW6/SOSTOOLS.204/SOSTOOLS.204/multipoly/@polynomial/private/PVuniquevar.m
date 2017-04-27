function [newdegmat,uniquevar] = PVuniquevar(degmat,varname)
% function [NewDegmat,UniqueVarname] = PVuniquevar(Degmat,Varname)
%
% DESCRIPTION 
%   (INTERNAL FUNCTION)  
%   Find the unique set of variables in varname and form
%   degmat in terms of this unique set.
%   
% INPUTS 
%   Degmat: degree matrix for a polynomial
%   Varname: variable list for a polynomial
%
% OUTPUTS  
%   NewDegmat: degree matrix in terms of unique variable list
%   UniqueVarname: list of unique variables
%  
% SYNTAX 
%   [NewDegmat,UniqueVarname] = PVuniquevar(Degmat,Varname)  

% 11/25/2002: PJS  Initial Coding
%  1/30/2002: PJS  Combine columns using sparse multiply

% Find repeated variables: 
%   sortidx: index such that varsort = varname(sortidx)
%   repeatidx: nonzero indices indicate repeats
%  rvec: map entries of varsort to numbers 1,..,nuv
[varsort,sortidx] = sortrows(char(varname));
repeatidx = all(varsort(2:end,:) == varsort(1:end-1,:),2);    
rvec = cumsum([1; ~repeatidx]);

% Create unique set of variables
uniqueidx = sortidx;
uniqueidx( repeatidx ) = [];
uniquevar = varname(uniqueidx);

% Form degree matrix in terms of new variable set    
%  (Use sparse multiply, degmat*summat, to sum the rows)
nv = size(degmat,2);
nuv = length(uniquevar);
summat = spalloc(nv,nuv,nv);
idx = sub2ind([nv nuv],sortidx,rvec);
summat(idx) = 1;
newdegmat = degmat*summat;
      




