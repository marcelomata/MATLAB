function [tip,R] = FK(angles,N,link_length)

TN = eye(4);
link_length = [0, link_length];
jointpos = [0;0;0];
for i = 1:N+1
    T(:,:,i) = Tgen(angles(i,:),link_length(i));
    TN = TN*T(:,:,i);
    TNlog(:,:,i) = TN;
    jointpos(:,i+1) = TN(1:3,4);
end
xtip = TN(1,4);
ytip = TN(2,4);
ztip = TN(3,4);
tip = [xtip;ytip;ztip];
R = TNlog(1:3,1:3,N);
end