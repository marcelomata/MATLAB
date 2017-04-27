% HW 2_2
close all
clear
clc
set(0, 'DefaultAxesFontSize', 14);
set(0,'DefaultAxesXGrid','on','DefaultAxesYGrid','on')

hw2_2func = @(t,x)[exp(x) - 1]

[t,x] = ode45(hw2_2func, [0,10], 1);

plot(t,x, 'k-')

xlabel('t')
ylabel('x')
title('Figure 3. Finite escape time of a nonlinear system')

