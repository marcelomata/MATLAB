function dx = nonlinsyseval(t,x,D,H,K)
dx = zeros(4,1);
theta = x(1);
D = subs(D);
H = subs(H);

dx(1) = x(3);
dx(2) = x(4);
dx(3:4) = inv(D)*(-H+[0;-K*x]);
end