function Z = sparsemultipart(Z1,Z2,info)

%
% Find the elements in Z1 that are in the convex hull of Z2, where Z2 is bipartite
%

% AP Feb 01 0

[Y,I] = find(sum(Z2,1)==0);
sizeinf = length(info);
  
if sizeinf == 1
   error('Error in sparsemultipart option - at least two sets are required');
end 

for i = 1:sizeinf
  Z3{i} = inconvhull(Z1(:,info{i}),Z2(:,info{i}));
end

for i = 1:sizeinf-1
  Z3{i+1} = [repmat(Z3{i},size(Z3{i+1},1),1),kron(Z3{i+1},ones(size(Z3{i},1),1))];
end
Z3 = Z3{sizeinf};
Z = zeros(size(Z3,1),size(Z2,2));
lgth = 0;
for i = 1:sizeinf
   Z(:,info{i})= Z3(:,(1+lgth):(lgth+length(info{i})));
   lgth = length(info{i})+lgth;
end
Z(:,I) = zeros(size(Z,1),size(I,2));