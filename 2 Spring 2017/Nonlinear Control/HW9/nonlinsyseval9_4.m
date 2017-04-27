function dx = nonlinsyseval9_4(t,x,D,H,k,K,a,threshold)
t
dx = zeros(4,1);
D = double(subs(D));
H = double(subs(H));

dx(1) = x(3);
dx(2) = x(4);

u = (-k(1)*x(1) - k(3)*x(3))/cos(x(1)) + (-k(2)*x(2))/(1 + K(1)*abs(x(2))) + (-k(4)*x(4))/(1+K(2)*abs(x(4)));

dx(3:4) = inv(D)*(-H+[0;u]);
end