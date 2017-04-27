close all
clear
clc

simtime = 30;
set(0, 'DefaultAxesFontSize', 14);
set(0,'DefaultAxesXGrid','on','DefaultAxesYGrid','on')

% params
m = 80; %[kg]
mfoot = 0.0145*m;
J = 4.58; %[kg m^2]
g = 9.81; %[m/s^2]
L = 0.5; %[m]
l0 = 1; %[m]
Jleg = mfoot*l0^2; %[kg m^2]
k = 10000; %[N/m]

a0 = 68*pi/180; %[rad]

% initial conditions
t0 = 0*pi/180; %[rad]
x0 = 0; %[m]
y0 = l0; %[m]

xrf0 = -l0*cos(a0) - L*cos(t0);
xrb0 = -l0*cos(a0) + L*cos(t0);
yrf0 = l0*sin(a0) - L*sin(t0);
yrb0 = l0*sin(a0) + L*sin(t0);

n = 2;


dx0 = 4.5; %[m/s]

Esys = 1850;
y0 = 1;
dy0 = 0; %[m/s]
dt0 = deg2rad(0); %[rad/s]

sim('SLIPquad')

% for i  = 1:n
%     dx0 = dx0v(i); %[m/s] 4.5 - 5.4
%     
%     Esys = 1850;
%     y0 = 1;
%     dy0 = 0; %[m/s]
%     dt0 = deg2rad(0); %[rad/s]
%     
%     sim('SLIPquad')
%     
%     CoTv(i) = CoTvec(end);
% end
% 
% CoTv