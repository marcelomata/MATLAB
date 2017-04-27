function dx = hw3_2func(t,x,s,b,r)
dx = zeros(3,1);
dx(1) = s*(x(2) - x(1));
dx(2) = x(1)*(r - x(3)) - x(2);
dx(3) = x(1)*x(2) - b*x(3);
end
