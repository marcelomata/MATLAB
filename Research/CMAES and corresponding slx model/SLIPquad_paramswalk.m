close all
clear


%k = 10000; %[N/m]

simtime = 29;
set(0, 'DefaultAxesFontSize', 14);
set(0,'DefaultAxesXGrid','on','DefaultAxesYGrid','on')                                                                                                                                                                                                             

% General params
m = 80; %[kg]
J = 4.58; %[kg m^2]
g = 9.81; %[m/s^2]
L = 0.5; %[m]
l0 = 1; %[m]

% % trotting stiffnesses
% kf = 1.7242*5000; %[N/m]
% kb = 1.6174*5000; %[N/m]
% 
% a0fl = 1.2377*deg2rad(67); %[rad] %edited (originally 68)
% a0fr = 1.2211*deg2rad(67); %[rad] %edited
% a0bl = 1*deg2rad(67); %[rad] %edited 
% a0br = 1*deg2rad(67); %[rad] %edited
% 
% 
% flx0 = -0.6622;
% blx0 = -0.5754;
% 
% x0 = 0; %[m] 0
% y0 = 2.0359; %[m] 1
% t0 = -0.1610; %[rad]  % 0
% 
% dx0 = 1.3388; %[m/s]  % 5
% %set_param('SLIPquad/EOM Integration1','dy0',0);
% dy0 = 1.7412; %[m/s] 0
% dt0 = 0.5069; %[rad/s] 0
x = [    1.1756
    0.9215
    0.8566
    1.1456
    1.9178
    0.9342
   -0.0728
    0.5320
    0.5747
   -0.4014
   -0.4636
];

% General params
m = 80; %[kg]
J = 4.58; %[kg m^2]
g = 9.81; %[m/s^2]
L = 0.5; %[m]
l0 = 1; %[m]

flic = 0;
blic = 0;
fric = 1;
bric = 1;
frx0 = 0;
brx0 = 0;
set_param('SLIPquadwalk/S-R Flip-Flop1','initial_condition','flic')
set_param('SLIPquadwalk/S-R Flip-Flop2','initial_condition','blic')
set_param('SLIPquadwalk/S-R Flip-Flop3','initial_condition','fric')
set_param('SLIPquadwalk/S-R Flip-Flop4','initial_condition','bric')
x0 = 0;

a0fl= x(1)*deg2rad(67);
a0fr= x(1)*deg2rad(67);
a0bl= x(2)*deg2rad(67);
a0br = x(2)*deg2rad(67);
kf= x(3)*3000;
kb= x(4)*3000;
dx0= x(5);
y0= x(6);
t0= x(7);
dt0 = x(8); %[rad] %edited (originally 68)
flx0 = x(9);
blx0 = x(10);
dy0 = x(11);

set_param('SLIPquadwalk/EOM Integration1/x0','Value',num2str(x0));
set_param('SLIPquadwalk/EOM Integration1/y0','Value',num2str(y0));
set_param('SLIPquadwalk/EOM Integration1/t0','Value',num2str(t0));

set_param('SLIPquadwalk/EOM Integration1/dx0','Value',num2str(dx0));
set_param('SLIPquadwalk/EOM Integration1/dy0','Value',num2str(dy0));
set_param('SLIPquadwalk/EOM Integration1/dt0','Value',num2str(dt0));


set_param('SLIPquadwalk/Back Left Flight/angle of attack','Value',num2str(a0bl));
set_param('SLIPquadwalk/Back Right Flight/angle of attack','Value',num2str(a0br));
set_param('SLIPquadwalk/Front Left Flight/angle of attack','Value',num2str(a0fl));
set_param('SLIPquadwalk/Front Right Flight/angle of attack','Value',num2str(a0fr));

set_param('SLIPquadwalk/Front Left Stance/k_fl','Value',num2str(kf))
set_param('SLIPquadwalk/Front Right Stance/k_fr','Value',num2str(kf))
set_param('SLIPquadwalk/Back Left Stance/k_bl','Value',num2str(kb))
set_param('SLIPquadwalk/Back Right Stance/k_br','Value',num2str(kb))

% set_param('SLIPquadwalk/Memory2','X0','flic')
% set_param('SLIPquadwalk/Memory4','X0','blic')
% set_param('SLIPquadwalk/Memory1','X0','fric')
% set_param('SLIPquadwalk/Memory7','X0','bric')



set_param('SLIPquadwalk/Memory3','X0','[flx0 0]')
set_param('SLIPquadwalk/Memory5','X0','[blx0 0]')
set_param('SLIPquadwalk/Memory6','X0','[frx0 0]')
set_param('SLIPquadwalk/Memory8','X0','[brx0 0]')

sim('SLIPquadwalk')