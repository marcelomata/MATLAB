% HW 7_2
close all
clear
clc
set(0, 'DefaultAxesFontSize', 14);
set(0,'DefaultAxesXGrid','on','DefaultAxesYGrid','on')


A = [0,0,1,0;0,0,0,1;9/8,0,0,0;981/200,0,0,0];
B = [0;0;5/1962;1/30];
Q = 10*eye(4);
R = 1;

[P,L,G] = care(A,B,Q);
P

load('sym_model_inv_pend_cart.mat');
fi = 1;

M = 25;
m = 20;
L = 9.81;
g = 9.81;
J = 1/3*m*L^2;

theta0 = 0.5;
s0 = 0;
dtheta0 = 0;
ds0 = 0;

D = subs(D);
H = subs(H);

[t,x] = ode45(@hw7_2func, [0,10], [theta0; s0; dtheta0; ds0],[], P,D,H);

plot(t,x(:,1),t,x(:,2))
legend('theta', 's')