% HW 3_2
close all
clear
clc
set(0, 'DefaultAxesFontSize', 14);
set(0,'DefaultAxesXGrid','on','DefaultAxesYGrid','on')

s = 10
b = 8/3;
r = 28;
tf = 50
x0 = 10;
y0 = 10;
z0 = 10;

[t,x] = ode45(@hw3_2func, [0,tf], [x0 y0 z0],[], s,b,r);

figure(1)
plot3(x(:,1),x(:,2),x(:,3));
xlabel('x');
ylabel('y');
zlabel('z');
title('Figure 1. Lorenz Attractor');

figure(2)
for i = 1:3
    [t,x] = ode45(@hw3_2func, [0,tf], [x0+0.1*i y0 z0],[], s,b,r);
    switch i
        case 1
            h = '-';
        case 2
            h = '--';
        case 3
            h = '-.';
    end
    subplot(3,1,1)
    plot(t,x(:,1),'LineStyle',h);
    title('Figure 2. Chaotic Nature of Lorenz System')
    xlabel('t');
    ylabel('x');
    hold on
    subplot(3,1,2)
    plot(t,x(:,2),'LineStyle',h);
    xlabel('t');
    ylabel('y');
    hold on
    subplot(3,1,3)
    plot(t,x(:,3),'LineStyle',h);
    xlabel('t');
    ylabel('z');
    hold on
end