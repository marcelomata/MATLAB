close all
clear
clc

simtime = 30;
set(0, 'DefaultAxesFontSize', 14);
set(0,'DefaultAxesXGrid','on','DefaultAxesYGrid','on')

%% General params
% m = 80; %[kg]
% J = 4.58; %[kg m^2]
% g = 9.81; %[m/s^2]
% L = 0.5; %[m]
% l0 = 1; %[m]
% %k = 10000; %[N/m]

%% Pronking
% k = 5000; %[N/m]
% a0fl = 68*pi/180; %[rad] %edited (originally 68)
% a0fr = 68*pi/180; %[rad] %edited
% a0bl = 68*pi/180; %[rad] %edited 
% a0br = 68*pi/180; %[rad] %edited

%% Bounding
m = 1;
g = 1;
k = 20;
L = 0.5;
l0 = 1;
J = 0.6;

a0fl =  (pi/2)-0.1110; %[rad] %edited (originally 68)
a0fr =  (pi/2)-0.111; % 0.1110;%[rad] %edited
a0bl = (pi/2)-0.0925; %[rad] %edited 
a0br = (pi/2)-0.0925; %[rad] %edited
dx0 = 0.4138;
y0 = 1.0237; 
dy0 = 0.1683;
t0 =0.056; %angle
dt0 =-0.3325; 


%% general initial conditions
%t0 = 0*pi/180; %[rad]  % Seyfarth - 91 deg, active - 45
x0 = 0; %[m]
%y0 = l0 + L*sin(t0)*1.1; %[m]

xrf0 = -l0*cos(a0fr) - L*cos(t0); %edited
xrb0 = -l0*cos(a0br) + L*cos(t0); %edited
yrf0 = l0*sin(a0fr) - L*sin(t0); %edited
yrb0 = l0*sin(a0br) + L*sin(t0); %edited


%dx0 = 5.00; %[m/s]  % Seyfarth - 5.00, active - 5
%dy0 = 0; %[m/s]
%dt0 = deg2rad(0); %[rad/s]  % Seyfarth - -5.5 deg/s, active - 0

sim('SLIPquad')