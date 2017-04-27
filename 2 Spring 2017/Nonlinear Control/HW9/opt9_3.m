function cost = opt9_3(param)

% HW 9_3

x10 = 1;
x20 = 9;
x30 = 0.1;
x40 = -0.1;
x0 = [x10 x20 x30 x40];
t0 = 0;
tf = 25;

load('sym_model_inv_pend_cart.mat');
syms u p v t;
fi = 1;

f = [dtheta;ds;(inv(D)*(-H+[0;u]))];
x = [theta;s;dtheta;ds];
Alin = jacobian(f,x);
Blin = jacobian(f,u);

M = 25;
m = 20;
L = 9.81;
g = 9.81;
J = 1/3*m*L^2;

theta = 0;
dtheta = 0;
s = p + v*t;
ds = v;
u = 0;

Alin = vpa(subs(Alin),4);
Blin = vpa(subs(Blin),4);

k = 1.0e+03 *[7.4144   -0.1272    8.2927   -0.4420];

% Tuning parameters
K = [param(1);param(2)];
a = [param(3);param(4)];
threshold = 0.01;

opts = odeset('Events',@events1);
if (sqrt(x0(1)^2 + x0(3)^2) - threshold > 0)
    [t,x] = ode45(@nonlinsyseval9_3a, [t0 tf], [x10,x20,x30,x40],opts,D,H,k,K,a,threshold);
    Ts = t(end);
    xs = x(end,:);
    [t2,x2] = ode45(@nonlinsyseval9_3b, [Ts tf], [xs xs(2) xs(4)],[],D,H,k,K,a,threshold);
    t = [t;t2];
    x = [x;x2(:,1:4)];
else
    [t,x] = ode45(@nonlinsyseval9_3b, [t0 tf], [x10,x20,x30,x40,x20,x40],[],D,H,k,K,a,threshold);
end

param
cost = norm(x(end,:))

end