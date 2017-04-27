close all
clear
clc
set(0, 'DefaultAxesFontSize', 14);
set(0,'DefaultAxesXGrid','on','DefaultAxesYGrid','on')

m = 80;
mfoot = 0.0001;
l0 = 1;
lh = 0.1;
rh = 0.1;

k = 10000;
b = 0;
mu = 1;

sim('SLIP_Walker')