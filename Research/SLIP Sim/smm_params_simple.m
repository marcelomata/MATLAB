close all
clear
clc
set(0, 'DefaultAxesFontSize', 14);
set(0,'DefaultAxesXGrid','on','DefaultAxesYGrid','on')

% parameters
m = 80; % body mass [kg]
g = 9.81; % gravity [m/s^2]
k = 20000; % leg stiffness [N/m]
l0 = 1; % leg length [m]
a0 = 68*pi/180; % angle of attack (from horizontal) [rad]

% initial conditions
x0 = 0; %[m]
y0 = l0; %[m]
dx0 = 5; %[m/s]
dy0 = 0; %[m/s]

 sim('smm_simple')