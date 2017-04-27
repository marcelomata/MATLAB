close all ;

% load constant parameters
consts = get_consts() ;
syms y z th psi m dy dz dth dpsi m dm
f_vec = [   dy
    dz
    dth
    dpsi
    0
    -consts.g
    0
    0
    0] ;

g_vec = [0,    0 ;
    0,    0 ;
    0,    0 ;
    0,    0 ;
    -consts.gamma*sin(psi+th)/m,    0 ;
    consts.gamma*cos(psi+th)/m,    0 ;
    -consts.L*consts.gamma*sin(psi)/consts.J,    0 ;
    0, 1/consts.JT ;
    -1,    0] ;

K_theta = lqr([0,1;0,0],[0;1],10*eye(2),1);
v = K_theta*