function pvar(varargin)
% function pvar(varargin)
%
% DESCRIPTION 
%   Create variables (i.e. monomials of degree 1).
%   
% INPUTS 
%   X1,X2,...: variable names
%
% OUTPUTS  
%   None
%  
% SYNTAX 
%   pvar('x1','x2','x3',...)  
%   pvar x1 x2 x3  
%     Both of these function calls create monomials of degree 1 with
%     the given names.
  
% 6/8/2002: PJS  Initial Coding  

for i1 = 1:nargin
  if isstr(varargin{i1})
    assignin('caller',varargin{i1}, polynomial(1,1,varargin(i1),[1 1]));
  else
    error('Inputs must be strings')
  end
end
  