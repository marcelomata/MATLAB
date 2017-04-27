function Z3 = inconvhull(Z1,Z2)

% INCONVHULL --- Returns in Z3 the elements of Z1 that are
%                inside the convex hull of Z2
%
% This function returns the elements of Z1 that lie
% inside the convex hull of Z2. Z1 and Z2 must be matrices,
% each row of which is a point in n-space.
% Z1 is the set of monomials

% PP 20 Jan 03 % CDD
% AP 1 Feb 03 % convhulln + some other cases

% First, find the affine subspace where everything lives
% (for instance, in the homogeneous case)
nmons = size(Z2,1);

% Translate so it goes through the origin 
mr = mean(Z2);
Rzero = Z2 - repmat(mr,nmons,1) ;

% The columns of N generate the subspace 
N = null(Rzero);

% Z2*N should be constant 
cval = mean(Z2*N);

% Get only the monomials in the subspace
tol = .01 ;
ix = find(sum(abs(Z1*N-repmat(cval,size(Z1,1),1)),2)< tol) ;
nZ1 = Z1(ix,:);

% Now, the inequalities:
% Find an orthonormal basis for the subspace
% (I really should do both things at the same time...)

% Project to the lower dimensional space, so convhull works nicely

Q = orth(Rzero');

% This calls CDD, or whatever

if size(Z2*Q,2)>1
   if ~isempty(cddpath)
      [A,B] = vrep2hrep(Z2*Q);
   else 
      [A,B] = useconvhulln(Z2*Q);
   end
   % Find the ones that satisfy the inequalities, and keep them.
   ix = find(min(repmat(B,1,size(nZ1,1))-A*Q'*nZ1')>-tol);
   Z3 = nZ1(ix,:);
elseif size(Z2*Q,2)==1 % 1 Feb 03
   A = [1;-1];
   B = [max(Z2*Q);-min(Z2*Q)];
   ix = find(min(repmat(B,1,size(nZ1,1))-A*Q'*nZ1')>-tol);
   Z3 = nZ1(ix,:);
else
   Z3 = nZ1;
end

Z3 = unique(Z3,'rows'); % 1 Feb 03
