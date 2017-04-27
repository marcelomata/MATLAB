function qpCost = qpFunc(x,c,n,N,D,m,g,I,dt,posCOM,thetaCOM,posEndEffector,velCOM,dthetaCOM, posCOMNext,thetaCOMNext,velCOMNext,dthetaCOMNext)

% Assign contact forces and control inputs
f = x(1:n*N); % format as f_x1, f_y1, f_x2, f_y2, ...
u = x(n*N+1:end); % u_x, u_y, u_c

dynError = computeDynError(f,u,m,g,I,dt,posCOM,thetaCOM,posEndEffector,velCOM,dthetaCOM, posCOMNext,thetaCOMNext,velCOMNext,dthetaCOMNext);

% Define regularization matrices for QP solver
for i = 1:N % for each end effector
    Wjj(n*i-(n-1):n*i) = 1e-2/(c(i) + 1e-3); % eqn 7 in paper, penalizes low ci's
    if i <= 2;
        Wjj(n*i-(n-1):n*i) = Wjj(n*i-(n-1):n*i) * 4; % makes hands (i = 1,2) weaker than feet
    end
end
W = diag(Wjj);
R = eye(D);

qpCost = dynError + transpose(f)*W*F + transpose(u)*R*u;

end