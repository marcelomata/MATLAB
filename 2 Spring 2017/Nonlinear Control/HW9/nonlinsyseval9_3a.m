function dx = nonlinsyseval9_3a(t,x,D,H,k,K,a,threshold)
% disp(['t = ',num2str(t)]);
dx = zeros(4,1);
theta = x(1);
s = x(2);
dtheta = x(3);
ds = x(4);
M = 25;
m = 20;
L = 9.81;
g = 9.81;
J = 1/3*m*L^2;

D = subs(D);
H = subs(H);

dx(1) = x(3);
dx(2) = x(4);

% if (sqrt(x(1)^2 + x(3)^2) - threshold >= 0)
%     u = (-k(1)*x(1) - k(3)*x(3))/cos(x(1));
% else
%     u = -k(1)*x(1) - k(3)*x(3) - k(2)*(x(2) - x(5)) - k(4)*(x(4) - x(6));
% end

u = (-k(1)*x(1) - k(3)*x(3))/cos(x(1));
dx(3:4) = inv(D)*(-H+[0;u]);
% 
% if (sqrt(x(1)^2 + x(3)^2) - threshold >= 0)
%     dx(5) = dx(2);
%     dx(6) = dx(4);
% else
%     dx(5) = x(6);
%     dx(6) = - a(1)*x(5)/(1 + K(1)*abs(x(5))) - a(2)*x(6)/(1+K(2)*abs(x(6)));
% end

end