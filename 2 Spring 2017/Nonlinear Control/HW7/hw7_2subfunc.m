function [f,g] = hw7_2subfunc(x,D,H)
theta = x(1);
s = x(2);
dtheta = x(3);
ds = x(4);

f = subs([dtheta;ds;(inv(D)*(-H))]);
g = subs([0;0;(inv(D)*([0;1]))]);

end
