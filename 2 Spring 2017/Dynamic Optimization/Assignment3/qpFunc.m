%% 16745 Dynamic Optimization Assignment 3

%{
Cost function script for QP problem, used to compute LPhysics

Written by: Joe Norby et al
%}

function qpCost = qpFunc(x,cVec,n,N,D,m,g,I,dt,posCOM,thetaCOM,posEndEffector,velCOM,dthetaCOM, posCOMNext,thetaCOMNext,velCOMNext,dthetaCOMNext)

% Assign contact forces and control inputs
f = x(1:n*N); % format as f_x1, f_y1, f_x2, f_y2, ...
u = x(n*N+1:end); % u_x, u_y, u_c

dynError = computeDynError(f,u,N,m,g,I,dt,posCOM,thetaCOM,posEndEffector,velCOM,dthetaCOM, posCOMNext,thetaCOMNext,velCOMNext,dthetaCOMNext);

% Define regularization matrices for QP solver
for i = 1:N % for each end effector
    Wjj(n*i-(n-1):n*i) = 1e-2/(cVec(i) + 1e-3); % eqn 7 in paper, penalizes low ci's
    if i >= 3;
        Wjj(n*i-(n-1):n*i) = Wjj(n*i-(n-1):n*i) * 4; % makes hands (i = 3,4) weaker than feet
    end
end
W = diag(Wjj);
R = eye(D);

qpCost = dynError + transpose(f)*W*f + transpose(u)*R*u;

end