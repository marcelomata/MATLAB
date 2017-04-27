close all
clear


l0 = 1; %[m]
%k = 10000; %[N/m]

simtime = 29;
set(0, 'DefaultAxesFontSize', 14);
set(0,'DefaultAxesXGrid','on','DefaultAxesYGrid','on')                                                                                                                                                                                                             

% % General params
m = 80; %[kg]
J = 4.58; %[kg m^2]
g = 9.81; %[m/s^2]
L = 0.5; %[m]

% x = [1.1817
% 1.0111
% 1.0580
% 1.3428
% 0.6391
% 0.0816
% -0.0397];

% % distance opt bound
% 1.0323
% 0.9835
% 0.7941
% 1.2812
% 1.1157
% 0.0156
% 0.1068

% better bound
% 0.9764
% 1.0608
% 0.9182
% 1.2557
% 1.6454
% 0.0812
% 0.3329

% okay bound
% 1.1817
% 1.0111
% 1.0580
% 1.3428
% 0.6391
% 0.0816
% -0.0397

% a0fl= x(1)*deg2rad(67);
% a0fr= x(1)*deg2rad(67);
% a0bl= x(2)*deg2rad(67);
% a0br = x(2)*deg2rad(67);
% kf= x(3)*5000;
% kb= x(4)*5000;
% dx0= x(5)*5;
% t0= x(6);
% dt0 = x(7);

% % Bounding stiffnesses
% kf = 4591; %[N/m]
% kb = 6278.5; %[N/m]

% % Galloping stiffnesses
% kf = 4064.5; %[N/m]
% kb = 0.7657*5000; %[N/m]

% % trotting stiffnesses
% kf = 10000; %[N/m]
% kb = 10000; %[N/m]

% pronking stiffnesses
kf = 5000;
kb = 5000;

% trotting and pronking angles 
a0fl = 67*pi/180; %[rad] %edited (originally 68)
a0fr = 67*pi/180; %[rad] %edited
a0bl = 67*pi/180; %[rad] %edited 
a0br = 67*pi/180; %[rad] %edited

% % bounding angles
% a0fl =  65.4188*pi/180; %[rad] %edited (originally 68)
% a0fr =  65.4188*pi/180; %[rad] %edited
% a0bl = 71.0736*pi/180; %[rad] %edited 
% a0br = 71.0736*pi/180; %[rad] %edited
% 
% % galloping angles
% a0fl = 1.2653*67*pi/180; %[rad] %edited (originally 68)
% a0fr = 0.7643*67*pi/180; %[rad] %edited
% a0bl = 1.1013*67*pi/180; %[rad] %edited 
% a0br = 1.0467*67*pi/180; %[rad] %edited
% 


t0 = 0*pi/180; %[rad]  % 0
x0 = 0; %[m] 0
y0 = 1; %[m] 1

dx0 = 5; %[m/s]  % 5
dy0 = 0; %[m/s] 0
% set_param('SLIPquad/EOM Integration1','dy0',0);
dt0 = deg2rad(0); %[rad/s] 0

% % Bounding "steady state" initial conditions, match with "better bound" 
% dx0= 7.9246;
% y0= 0.9750;
% t0= 0.0120;
% dt0 = -4.8943;
% dy0 = 0.1030;

% % trotting steady state ICS
x0 = 0;
y0 = 0.9571;
t0 = 0;
dx0 = 5.0788;
dy0 = 0.2157;
dt0 = 0;

%% Bounding
%  m = 1;
%  g = 1;
%  k = 20;
% L = 0.5;
% l0 = 1;
% J = 0.6;
% % 
%  dx0 = 0.4138;
% 
%  a0fl =  (pi/2)-0.1110; %[rad] %edited (originally 68)
% a0fr =  (pi/2)-0.111; % 0.1110;%[rad] %edited
% a0bl = (pi/2)-0.0925; %[rad] %edited 
% a0br = (pi/2)-0.0925; %[rad] %edited
% 
% %values from optimization
% % a0fl = 1.4728;
% % a0fr = 1.4728; 
% % a0br = 1.466;
% % a0bl = 1.466;
% 
% x0 = 0;
%  y0 = 1.0237; 
% % 
%  dy0 = 0.1683;
% t0 =0.056; %angle
%  dt0 =-0.3325; 
% % y0 = l0 + L*sin(t0)*1.1; %[m]

% a0fl= 1.2505*deg2rad(67);
% a0fr= 1.2505*deg2rad(67);
% a0bl= 0.8539*deg2rad(67);
% a0br = 0.8539*deg2rad(67);
% kf= 0.7525*5000;
% kb= 0.7525*5000;

set_param('SLIPquad/EOM Integration1/x0','Value',num2str(x0));
set_param('SLIPquad/EOM Integration1/y0','Value',num2str(y0));
set_param('SLIPquad/EOM Integration1/t0','Value',num2str(t0));

set_param('SLIPquad/EOM Integration1/dx0','Value',num2str(dx0));
set_param('SLIPquad/EOM Integration1/dy0','Value',num2str(dy0));
set_param('SLIPquad/EOM Integration1/dt0','Value',num2str(dt0));


set_param('SLIPquad/Back Left Flight/angle of attack','Value',num2str(a0bl));
set_param('SLIPquad/Back Right Flight/angle of attack','Value',num2str(a0br));
set_param('SLIPquad/Front Left Flight/angle of attack','Value',num2str(a0fl));
set_param('SLIPquad/Front Right Flight/angle of attack','Value',num2str(a0fr));

set_param('SLIPquad/Front Left Stance/k_fl','Value',num2str(kf))
set_param('SLIPquad/Front Right Stance/k_fr','Value',num2str(kf))
set_param('SLIPquad/Back Left Stance/k_bl','Value',num2str(kb))
set_param('SLIPquad/Back Right Stance/k_br','Value',num2str(kb))


%% general initial conditions

xrf0 = -l0*cos(a0fr) - L*cos(t0); %edited
xrb0 = -l0*cos(a0br) + L*cos(t0); %edited
yrf0 = l0*sin(a0fr) - L*sin(t0); %edited
yrb0 = l0*sin(a0br) + L*sin(t0); %edited


sim('SLIPquad')
%%
close all
plot(tout, forces(:,1:2))
xlabel('Time (s)')
ylabel('Normalized force (bw)')
axis([0 0.35 -0.4 1.5]);
legend('Horizontal','Vertical','Location', 'Northwest')
% legend('Front left/back right leg horizontal','Front left/back right leg vertical','Front right/back left leg horizontal','Front right/back left leg vertical','Location', 'Northwest')
% legend('Front leg horizontal','Front leg vertical','Back leg horizontal','Back leg vertical','Location', 'Northwest')



