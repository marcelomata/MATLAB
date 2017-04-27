% Function to setup and perform any one-time computations
% Input parameters
%   x - state of the rocket, x=[y,z,th,psi,dy,dz,dth,dpsi,m]^T
%   consts - structure that contains various system constants
% Output parameters
%   ctrl  -  any student defined control parameters
function ctrl = student_setup(x0, consts)
    % We provide possibility to switch the ode solver if needed.
    % Default ode_type should work in almost all cases.  Don't change this unless you know what you are doing.
    ctrl.ode_type = 0 ; % zero => ode45, non-zero=> ode15s.

    
    % Replace code below with any one time control design computation if needed.
    % Ex: ctrl.K = lqr(A, B, Q, R) ;
    ctrl.K = [0.0000    0.0018    0.0997    0.4690   -0.0005    0.0353    0.4850    1.8646    0.0000;
              0.0000    0.0000   -0.0036    1.0045    0.0000    0.0000   -0.0469    3.8980    0.0000] ;

    %ctrl.K = zeros(2,9);
end