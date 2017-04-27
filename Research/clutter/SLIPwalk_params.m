% params
m = 70; %[kg]
g = 9.81; %[m/s^2]
l = 1; %[m]
l0 = 1; %[m]
kv = 100000; %[N/ m/s]
k = 10000; % [N/m]
theta_th = 20*pi/180; %[rad]

% initial conditions
x0 = -l0*sin(theta_th); %[m]
y0 = sqrt(l0^2 - x0^2); %[m]
dx0 = 2.5; %[m/s]
dy0 = 0; %[m/s]