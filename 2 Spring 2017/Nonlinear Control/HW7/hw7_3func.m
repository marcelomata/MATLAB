function dx = hw7_3func(t,x,P)
f = [x(2);sin(x(1))];
g = [0;1];
LfV = 2*transpose(x)*P*f;
LgV = 2*transpose(x)*P*g;

if (LgV == 0)
   u = 0;
else
   u = -(LfV + sqrt(LfV^2 + LgV^4))/LgV; 
end

dx = f+g*u;
end
