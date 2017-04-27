% params
m = 70; %[kg]
g = 9.81; %[m/s^2]
l = 1; %[m]
l0 = 1; %[m]
k = 23000; %[N/m]
kv = 0; %[N/ m/s]
theta_th = 15*pi/180; %[rad]

% initial conditions
x0 = -l*sin(theta_th); %[m]
y0 = sqrt(l^2 - x0^2); %[m]
dx0 = 3; %[m/s]
dy0 = -1; %[m/s]