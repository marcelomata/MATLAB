% HW 9_3
close all
clear
clc
set(0, 'DefaultAxesFontSize', 14);
set(0,'DefaultAxesXGrid','on','DefaultAxesYGrid','on')

x10 = 1.2;
x20 = 0;
x30 = 0;
x40 = 0;
x0 = [x10 x20 x30 x40];
t0 = 0;
tf = 100;

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

%Tuning parameters
K = [0.4644; 0.9932];
a = [1.3953; 1.2370];
threshold = 0.01;

tic
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
toc

plot(t,x(:,1),'-',t,x(:,2),'--')
legend('theta', 's','location', 'northeast')
title('9.1. Nonlinear System Response, State Feedback')
xlabel('Time [s]')
ylabel('States')


