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
x

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

set_param('SLIPquadwalk/Memory2','X0','flic')
set_param('SLIPquadwalk/Memory4','X0','blic')
set_param('SLIPquadwalk/Memory1','X0','fric')
set_param('SLIPquadwalk/Memory7','X0','bric')

set_param('SLIPquadwalk/Memory3','X0','[flx0 0]')
set_param('SLIPquadwalk/Memory5','X0','[blx0 0]')
set_param('SLIPquadwalk/Memory6','X0','[frx0 0]')
set_param('SLIPquadwalk/Memory8','X0','[brx0 0]')


sim('SLIPquadwalk')
% dy = pos(end,2) - pos(1,2);
% dt = pos(end,3) - pos(1,3);
% ddx = vel(end,1) - vel(1,1);
% ddt = vel(end,3) - vel(1,3);
% f = 10*abs(dy)+abs(dt)+abs(ddx)+0.5*abs(ddt) + (pos(1,2)>1)*10000+min(x(1),0)^2*10000+min(x(2),0)^2*10000; %+ 5*max(abs(pos(:,3))) %some fn based on simulation
f = (50 - pos(end,1))^2 % + (pos(1,2)>1)*10000 + min(x(1),0)^2*10000 + min(x(2),0)^2*10000 + (x(1)>pi)*10000+ (x(2)>pi)*10000
% if f<25^2
%    x
% end