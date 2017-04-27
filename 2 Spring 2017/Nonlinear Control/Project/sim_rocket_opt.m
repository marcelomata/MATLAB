% Function to simulate rocket
function J = sim_rocket_opt(x)
    close all ;

    % load constant parameters
    consts = get_consts() ;
    
    if(nargin < 1)
        %x0 = [10; 150; 1; 0; 0; 0; 0; 0; consts.m_nofuel+1.0*consts.max.m_fuel] ;
        %wind = 0 ;
        x0 = [(2*rand-1)*100;(1475*rand+25);(2*rand-1)*deg2rad(179);0;(2*rand-1)*10;(2*rand-1)*10;(2*rand-1)*deg2rad(179);0;consts.m_nofuel+1.0*consts.max.m_fuel];
        wind = (2*rand-1)*10;
    end
    
    x0 = [(2*rand-1)*100;(1475*rand+25);(2*rand-1)*deg2rad(179);0;(2*rand-1)*10;(2*rand-1)*10;(2*rand-1)*deg2rad(179);0;consts.m_nofuel+1.0*consts.max.m_fuel];
    wind = (2*rand-1)*10;
    
    % call student one-time setup
    ctrl = student_setup_opt(x0, consts, x) ;

    % Integrate system
    odeopts = odeset('Events',@odeevents_touchdown) ;
    if(ctrl.ode_type == 0)
        [t x] = ode45(@odefun_rocket, [0 60], x0, odeopts, wind, consts, ctrl) ;
    else
        [t x] = ode15s(@odefun_rocket, [0 60], x0, odeopts, wind, consts, ctrl) ;
    end
    
    J = compute_score(x(end,:)', consts) ;
end


% Function to describe the dynamics of the rocket
function [dx u] = odefun_rocket(t, x, wind, consts, ctrl)
    % Extract various states
    y = x(1) ;
    z = x(2) ;
    th = x(3) ; 
    psi = x(4) ;
    
    dy = x(5) ;
    dz = x(6) ;
    dth = x(7) ;
    dpsi = x(8) ;
    
    m = x(9) ;
    
    % Construct drift and control vector fields
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
        
    % Wind disturbance goes smoothly to zero for z <= 2*L
    if(z > 2*consts.L)
        d = wind/m*exp(-1/(z-2*consts.L)) ;
    else
        d = 0 ;
    end
    d_vec = [zeros(4,1);
             d;
             zeros(4,1)] ;
    
    % call student controller
    u = student_controller(t, x, consts, ctrl) ;
%    u = student_controller_stable_theta(t, x, consts, ctrl) ;


    % Check if fuel is over
    if(m <= consts.m_nofuel)
        u(1) = 0 ;
    end
   
    % Thrust / Torque saturations
    u(1) = min(max(u(1), consts.min.fT), consts.max.fT) ;
    u(2) = min(max(u(2), -consts.max.tau), consts.max.tau) ;
    
    % Output time-derivative of state
    dx = f_vec + g_vec*u + d_vec ;
end


% Exit integration on ground contact
function [value,isterminal,direction] = odeevents_touchdown(t, x, wind, consts, ctrl)
    z = x(2) ; th = x(3) ; L = consts.L ; r = consts.r ;
    % Make a list of possible contact points
    contact_points = [z-L*cos(th)-r*sin(th);
                      z-L*cos(th)+r*sin(th);
                      z+L*cos(th);
                      z-r*sin(th);
                      z+r*sin(th)] ;
    value = min(contact_points) ;
    isterminal = 1;   % Stop the integration
    direction = 0;   % all direction only
end