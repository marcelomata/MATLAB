% HW 9_2
close all
clear
clc
set(0, 'DefaultAxesFontSize', 14);
set(0,'DefaultAxesXGrid','on','DefaultAxesYGrid','on')

x10 = 0;
x20 = 0;
x30 = 0;
x40 = 0;
t0 = 0;
tf = 50;

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

Alin = vpa(subs(Alin),4)
Blin = vpa(subs(Blin),4)


K1 = 1.0e+03 *[7.4144   -0.1272    8.2927   -0.4420]

e = 0.1;
[t,x] = ode45(@nonlinsyseval9_2, [t0 tf], [x10,x20,x30,x40],[],D,H,K1,e);

plot(t,x(:,1),'-',t,x(:,2),'--')
legend('theta', 's','location', 'northeast')
title('9.2. Nonlinear System Response, State Feedback')
xlabel('Time [s]')
ylabel('States')


