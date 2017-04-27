function dx = nonlinsyseval9_2(t,x,D,H,K,e)
t
dx = zeros(4,1);
theta = x(1);
D = subs(D);
H = subs(H);
xbar = [0;10*exp(-e*t);0;-e*10*exp(-e*t)];
u = -K*(x - xbar);

dx(1) = x(3);
dx(2) = x(4);
dx(3:4) = inv(D)*(-H+[0;u]);
end