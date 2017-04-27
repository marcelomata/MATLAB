% parameters
m = 80; %[kg]
l0 = 1; %[m]
g = 9.81; %[m/s^2]
k = 20000; %[N/m]
a0 = 68*pi/180; %[rad] 

% initial conditions
x0 = 0; %[m]
y0 = l0; %[m]

dx0 = 5; %[m/s]
dy0 = 0; %[m/s]

sim('smm')