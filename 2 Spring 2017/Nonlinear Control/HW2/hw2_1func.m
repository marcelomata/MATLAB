function dx = hw2_1func(t,x,mu)
dx = zeros(2,1);
dx(1) = x(2);
dx(2) = mu*(1 - x(1)^2)*x(2) - x(1);
end
