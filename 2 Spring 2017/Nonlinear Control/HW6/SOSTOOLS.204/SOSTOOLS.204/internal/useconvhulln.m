function [A,B]= useconvhulln(Z2)

% AP Apr 03 02
% AP Feb 01 03

% First, find the convex hull of Z2

convh = convhulln(Z2);
facets = size(convh,1);
[nZ1,nZ2] = size(Z2);

% Form the hyperplanes
% A hyperplane of the form [x1 ... xn -ones][A';b'] = 0
% [A';b'] is in the nullspace of the matrix [x1,...,xn -ones].
% Ignore it if it has dimension greater than 1
% Normalise if possible.

for i = 1:facets
    vert = [Z2(convh(i,:),:) -ones(nZ2,1)];
    nullvert = null(vert,'r');
    if size(nullvert,2) == 1  
        if nullvert(end) ~=0
            nullvert = nullvert./nullvert(end);
        end
        coeff(:,i) = nullvert(1:end-1);
        cold(i,1) = nullvert(end); 
    end
end

coeff = coeff';

% Condition the matrix a bit

coeffcold = [coeff cold];
coeffcold = round(coeffcold*100000)/100000;

% Discard same hyperplanes (due to convhulln result)
[coeff2cold,Ix,Iy] = unique(coeffcold,'rows');

%Remove a possible zero row

yind = find(sum(coeff2cold.^2,2) == 0);
if ~isempty(yind)
    Ix = [Ix([1:yind-1],1);Ix(yind+1:end,1)];
end

coeff2 = coeff(Ix,:);
convhnew = convh(Ix,:);
cnew = cold(Ix);
facetsnew = size(convhnew,1);

% Make inequalities out of them by testing a point not on the hyperplane
% Notation: convex hull is now Ax-b<=0
for fac = 1:facetsnew
    for ind = 1:nZ1
        matr = find(convhnew(fac,:) - ind*ones(1,nZ2) == 0);
        tests(fac) = coeff2(fac,:)*Z2(ind,:)'-cnew(fac);
        if isempty(matr) & abs(tests(fac)) > 1e-8
            break
        end
    end
    if tests(fac)>0
        coeff2(fac,:)=-coeff2(fac,:);
        cnew(fac)=-cnew(fac);
    end
end

A = coeff2;
B = cnew;
