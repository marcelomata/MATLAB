close all
clear
clc

simtime = 30;
set(0, 'DefaultAxesFontSize', 14);
set(0,'DefaultAxesXGrid','on','DefaultAxesYGrid','on')

% params
m = 80; %[kg]
J = 4.58; %[kg m^2]
Jleg = 0.0458; %[kg m^2]
g = 9.81; %[m/s^2]
L = 0.5; %[m]
mt = 1; %[kg]
Lt = 0.5; %[m]
Jt = mt*Lt^2; %[kg m^2]
l0 = 1; %[m]
k = 10000; %[N/m]

a0 = 68*pi/180; %[rad]

% initial conditions
t0 = 0*pi/180; %[rad]
x0 = 0; %[m]
y0 = l0; %[m]
phi0 = 3*pi/2+0.3;

xrf0 = -l0*cos(a0) - L*cos(t0);
xrb0 = -l0*cos(a0) + L*cos(t0);
yrf0 = l0*sin(a0) - L*sin(t0);
yrb0 = l0*sin(a0) + L*sin(t0);

dx0 = 5.00; %[m/s]
Esys = 1750;
y0 = 1;
dy0 = 0; %[m/s]
dt0 = deg2rad(0); %[rad/s]
dphi0 = 1;

sim('SLIPquadtail')