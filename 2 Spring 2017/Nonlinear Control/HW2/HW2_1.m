% HW 2_1
close all
clear
clc
set(0, 'DefaultAxesFontSize', 14);
set(0,'DefaultAxesXGrid','on','DefaultAxesYGrid','on')

mu = 1;
N = 100;

figure(1)
for i=1:N
    x0 = rand*10 - 5;
    dx0 = rand*10 - 5;
    [t,x] = ode45(@hw2_1func, [0,10], [x0 dx0],[], mu);
    plot(x0,dx0, 'r.', 'markersize', 20)
    hold on
    plot(x(:,1),x(:,2), 'k-')
end
axis equal
axis([-5 5 -5 5])
xlabel('x')
ylabel('$\dot{x}$', 'interpreter', 'latex')
title('Figure 1. Limit cycle of Van der Pol oscillator, different initial conditions')

clear t x

x0 = 2;
dx0 = 0;
muvec = [0,0.5,1,2,3];

figure(2)
for i=1:length(muvec)
    mu = muvec(i);
    [t,x] = ode45(@hw2_1func, [0,10], [x0 dx0],[], mu);
    hold on
    plot(x(:,1),x(:,2), '-')
end
plot(x0,dx0, 'r.', 'markersize', 20)
axis equal
axis([-5 5 -5 5])
xlabel('x')
ylabel('$\dot{x}$', 'interpreter', 'latex')
title('Figure 2. Limit cycle of Van der Pol oscillator, different \mu values')
legend({'$\mu = 0$','$\mu = 0.5$','$\mu = 1$','$\mu = 2$','$\mu = 3$'},'Interpreter','latex')
