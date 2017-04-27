clear
% cart symbolic quantities
syms M s ds dds real
% pendulum symbolic quantities
syms m J theta dtheta ddtheta   real
% symbolic constants
syms L g real

% Configuration coordinates and velocities
% theta is in radians, positive counter-clockwise
% u is in meters
q = [theta; s] ;
dq = [dtheta; ds] ;
ddq = [ddtheta; dds] ;

% Position of cart and pendulum's center of mass
p_cart = [s; 0] ;
p_pend = p_cart + L*[-sin(theta); cos(theta)] ;

% Velocity of cart and pendulum's center of mass
v_cart = jacobian(p_cart, q)*dq ;
v_pend = jacobian(p_pend, q)*dq ;

% Kinetic Energy
KE_cart = 1/2*M*v_cart'*v_cart ;
KE_pend_trans = 1/2*m*v_pend'*v_pend ;
KE_pend_rot = 1/2*J*dtheta^2 ;
KE = simplify(KE_cart + KE_pend_trans + KE_pend_rot) ;

% Potential Energy
PE = m*g*p_pend(2) ;

% Lagrangian
Lag = KE - PE ;

% Lagrangian equations of motion
LHS = jacobian(jacobian(Lag, dq)', [q;dq])*[dq;ddq]  -  jacobian(Lag, q)' ;
D = jacobian(LHS, ddq) ;
H = simplify(LHS - D*ddq) ;
B = [0; 1] ;

% Equations of Motion
G=jacobian(PE,q).';
G=simplify(G);
D=simplify(jacobian(KE,dq).');
D=simplify(jacobian(D,dq));

save('sym_model_inv_pend_cart.mat') ;