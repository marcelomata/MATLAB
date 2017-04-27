function p=s2p(s)
% function p=s2p(s)
%
% DESCRIPTION 
%   Converts a polynomial from a symbolic toolbox object to
%   a multipoly toolbox object.
%   (currently works for scalar polynomials only)
%   
% INPUTS 
%   s: A polynomial created using the symbolic toolbox
%
% OUTPUTS  
%   p: The polynomial created using the multipoly toolbox  
%  
% SYNTAX 
%   p = s2p(s)
  
% 1/30/2003: PJS  Initial Coding  

if ~isa(s,'sym')
  error('Input must be a symbolic toolbox object');
end

% Convert to variable precision arithmetic
s = vpa(s);

% Get list of variables
vars = [' ' findsym(s)];
idx = [0 findstr(vars,',') length(vars)+1];
nv = length(idx)-1;
varname = cell(nv,1);
for i1 =1:nv
  varname{i1} = vars( idx(i1)+2 : idx(i1+1)-1 );
end

% Expand the polynomial and convert to a structure to
% gain access to the string representation.
s = expand(s);
s = struct(s);
[nr,nc] = size(s);

if any([nr nc]~=[1 1])
  error('The input must be a scalar polynomial');
end

% Get string representation
term = s.s;
idx = sort([findstr(term,'+') findstr(term,'-')]);
if(idx(1)~=1), idx=[1 idx]; end
idx = [idx length(term)+1];
temp = findstr(term,'e')+1;
idx = setdiff(idx,temp);

% Go monomial by monomial
nt = length(idx)-1;
coefficient = spalloc(nt,1,nt);
degmat = sparse(nt,nv);
for i1 = 1:nt
  monom=term( idx(i1) : idx(i1+1)-1 );
  coefficient(i1) = str2double(maple('lcoeff',monom));
  for i2 = 1:nv
    degmat(i1,i2) = str2double(maple('degree',monom,varname{i2}));
  end
end  

% Create multipoly object
p = polynomial(coefficient,degmat,varname,[1 1]);