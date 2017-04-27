% HW 7_2
close all
clear
clc
set(0, 'DefaultAxesFontSize', 14);
set(0,'DefaultAxesXGrid','on','DefaultAxesYGrid','on')

A = [0 1;1 0];
B = [0;1];
K = transpose(roots([1 1.4 1]));

Acl = A + B*K;

P = lyap(Acl, eye(2));

theta0 = 0.1;
dtheta0 = 0;

[t,x] = ode45(@hw7_3func, [0,10], [theta0; dtheta0],[], P);

plot(t,x(:,1),t,x(:,2))