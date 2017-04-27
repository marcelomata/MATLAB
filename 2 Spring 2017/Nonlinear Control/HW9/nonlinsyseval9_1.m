function dx = nonlinsyseval9(t,x,D,H,K,p,v)
t
dx = zeros(4,1);
theta = x(1);
D = subs(D);
H = subs(H);
u = -K*(x - [0;p+v*t;0;v]);

dx(1) = x(3);
dx(2) = x(4);
dx(3:4) = inv(D)*(-H+[0;u]);
end