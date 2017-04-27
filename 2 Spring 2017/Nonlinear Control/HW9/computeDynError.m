function dynError = computeDynError(f,u,N,m,g,I,dt,posCOM,thetaCOM,posEndEffector,velCOM,dthetaCOM, posCOMNext,thetaCOMNext,velCOMNext,dthetaCOMNext)

% compute accelerations from F = ma
ddx = u(1)/m;
ddy = u(2)/m - g;
ddtheta = u(3)/I;
for i = 1:N % add in contact force contributions
    ddx = ddx + f(2*i-1);
    ddy = ddy + f(2*i);
    r = posEndEffector(i) - posCOM; % pi is position of end effector, pc is position of mass center, should be in R^2
    rxf = cross(r(i),f(2*i-1:2*i));
    ddtheta = ddtheta + rxf(3);
end

% Forward integrate to get estimates for next COM position and velocity
posCOMEst = posCOM + velCOM*dt;
thetaCOMEst = thetaCOM + dthetaCOM*dt;
velCOMEst = velCOM + [ddx;ddy]*dt;
dthetaCOMEst = dthetaCOM + ddtheta*dt;

% Compute error between estimates and trajectory-given values
dynError = norm(posCOMEst - posCOMNext) + norm(thetaCOMEst - thetaCOMNext) + norm(velCOMEst - velCOMNext) + norm(dthetaCOMEst - dthetaCOMNext);