function s=p2s(p)
% function s=p2s(p)
%
% DESCRIPTION 
%   Converts a polynomial from a multipoly toolbox object to
%   a symbolic toolbox object.
%   (currently works for scalar polynomials only)
%   
% INPUTS 
%   p: A polynomial created using the multipoly toolbox
%
% OUTPUTS  
%   s: The polynomial created using the symbolic toolbox  
%  
% SYNTAX 
%   s = p2s(p)
  
% 1/30/2003: PJS  Initial Coding  

if ~isa(p,'polynomial')
  error('Input must be a multipoly toolbox object');
end

% Get polynomial info
[nr nc] = size(p);
if any([nr nc]~=[1 1])
  error('The input must be a scalar polynomial');
end
[nt,nv] = size(p.degmat);
coef = p.coefficient;
deg = p.degmat;
var = p.varname;

% Create symbolic toolbox variables
for i1 = 1:nv
  eval(['syms ' var{i1} ' real']);
end

% Construct monomial by monomial
s = 0;
for i1 = 1:nt
  term = coef(i1);
  termexp = deg(i1,:);
  idx = find(termexp);
  for i2 = 1:length(idx)
    eval(['term = term*(' var{idx(i2)} ')^termexp(idx(i2));']);
  end
  s = s+term;
end  

