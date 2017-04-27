function dx = hw7_2func(t,x,P,D,H)
t
[f,g] = hw7_2subfunc(x,D,H);
LfV = 2*transpose(x)*P*f;
LgV = 2*transpose(x)*P*g;

if (LgV == 0)
   u = 0;
else
   u = -(LfV + sqrt(LfV^2 + LgV^4))/LgV; 
end

dx = double(f + g*u);
end
