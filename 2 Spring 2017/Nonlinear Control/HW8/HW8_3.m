% HW 8_3
close all
clear
clc
set(0, 'DefaultAxesFontSize', 14);
set(0,'DefaultAxesXGrid','on','DefaultAxesYGrid','on')

syms q q1 q2 q3 q4

q = [q1;q2;q3;q4];

f = [q3;q4;-q1-0.5*(q1-q2)-0.2*(q1-q2)^3;-4*q1+0.5*(q1-q2)+0.2*(q1-q2)^3];
g = [0;0;0;1];
h = q1;

Lfh = jacobian(h,q)*f;
Lgh = jacobian(h,q)*g;
LgLfh = jacobian(Lfh,q)*g;
Lf2h = jacobian(Lfh,q)*f;
LgLf2h = jacobian(Lf2h,q)*g
Lf3h = jacobian(Lf2h,q)*f;
LgLf3h = jacobian(Lf3h,q)*g
Lf4h = jacobian(Lf3h,q)*f;

z = [h;Lfh;Lf2h;Lf3h]

v = [-4 -8.4 -8.92 -4.2]*z
u = inv(LgLf3h)*(-Lf4h + v)

qdot = f + g*u

[t,q] = ode45(@hw8_3func, [0 15], [0;1;0;0]);

plot(t,q(:,1), '-', t,q(:,2), '--')

xlabel('Time (s)')
ylabel('Position (m)')
title('8.3.e System response to nonlinear state feedback control')
legend('q_1', 'q_2', 'Location', 'Northeast')