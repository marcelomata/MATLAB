%% 16745 Dynamic Optimization Assignment 3

%{
Phase 3 cost function script
Cost = LTask + LCI + LPhysics, final cost function

Written by: Joe Norby et al
%}

function cost = computeCost_3(s,N,K)
% N = number of end effectors
% K = number of  movement phases

% Assumes s vector is encoded as:
% s = [pc;rc;p1...N;r1...N;             % from time 1 to time K
%      pcdot;rcdot;p1...Ndot;r1...Ndot; % from time 1 to time K
%      c1...N                           % from time 1 to time K
%     ]                   

% Need to:
% add kinematic constraints on joints

% Set up model params
L = 0.5;  % length of joints
l = 0.5;  % distance from COM to hip/shoulder joints
mu = 0.5; % Coefficient of friction
m = 50;   % body mass
I = 2;    % body inertia
g = 9.81; % gravity

% Set up dimensionality params
n = 2; % dimensionality of each contact force (F_x,F_y)
D = 3; % number of control directions (x,y,theta)

% Set up timekeeping params
tPhase = 0.5; % duration of movement phase
dt = 0.1; % cost function eval time step
tFinal = tPhase*K; % final time WAS K-1, check if there are errors in timekeeping
tVec = 0:dt:tFinal; % vector of times for evaluation
knots = 0:tPhase:tFinal; % times of knots for spline interpolation

% Initialize costs
LTask = 0;
LCI = 0;
LPhysics = 0;

% Initialize vectors of body/end effector positions and orientations
% Specify initial pose here
posCOMVec = [0;0];
thetaCOMVec = [0];
posEndEffectorVec = [-(l+2*L);0;-(l+2*L);0;(l+2*L);0;(l+2*L);0;]; % hard coded for 4 end effectors
thetaEndEffectorVec = [0;0;pi;pi];
velCOMVec = [0;0];
dthetaCOMVec = [0];
velEndEffectorVec = zeros(2*N,1);
dthetaEndEffectorVec = zeros(N,1);

% Retrieve vectors of body/end effector positions and orientations
for ii = 2:K+1
    posCOMVec = [posCOMVec; s((3*(N+1))*(ii-1)+1:(3*(N+1))*(ii-1) + 2)];
    thetaCOMVec = [thetaCOMVec; s((3*(N+1))*(ii-1)+3)];
    posEndEffectorVec = [posEndEffectorVec; s((3*(N+1))*(ii-1)+4:(3*(N+1))*ii - N)];
    thetaEndEffectorVec = [thetaEndEffectorVec; s((3*(N+1))*ii - N + 1:(3*(N+1))*ii)];
    velCOMVec = [velCOMVec; s(3*K*(N+1)+ (3*(N+1))*(ii-1)+1:3*K*(N+1)+ (3*(N+1))*(ii-1) + 2)];
    dthetaCOMVec = [dthetaCOMVec; s(3*K*(N+1)+ (3*(N+1))*(ii-1)+3)];
    velEndEffectorVec = [velEndEffectorVec; s(3*K*(N+1)+ (3*(N+1))*(ii-1)+4:3*K*(N+1)+ (3*(N+1))*ii - N)];
    dthetaEndEffectorVec = [dthetaEndEffectorVec; s(3*K*(N+1)+ (3*(N+1))*ii - N + 1:3*K*(N+1)+ (3*(N+1))*ii)];
end

ciVec = s(6*(N+1)*K + 1:end);

for ii = 1:length(tVec)-1
    t = tVec(ii); % assign current time
    phi = floor(t/tPhase)+1; % index of current phase
    timeFrame = [knots(phi), knots(phi+1)];
    cVec = ciVec(N*(phi-1)+ 1:N*phi); % select current vector of c_(i,phi)
    
    % Variables for retrieve different widths of portions of vectors
    two = phi*2-1:phi*2;
    one = phi;
    
    % Perform interpolations to get current COM, end effector positions,
    % orientations
    posCOMSpline = spline(timeFrame,[velCOMVec(two), posCOMVec(two), posCOMVec(two+2) velCOMVec(two+2)]);
    posCOM = ppval(posCOMSpline,t);
    posCOMNext = ppval(posCOMSpline,t+dt);
    
    thetaCOMSpline = spline(timeFrame,[dthetaCOMVec(one), thetaCOMVec(one), thetaCOMVec(one+1) dthetaCOMVec(one+1)]);
    thetaCOM = ppval(thetaCOMSpline,t);
    thetaCOMNext = ppval(thetaCOMSpline,t+dt);
    
    for i = 1:N
        posEndEffectorSpline = spline(timeFrame,[velEndEffectorVec(two+(i-1)*2), posEndEffectorVec(two+(i-1)*2), posEndEffectorVec(two+2+(i-1)*2), velEndEffectorVec(two+2+(i-1)*2)]);
        posEndEffector(i*2-1:i*2) = ppval(posEndEffectorSpline,t);
    end
    
    velCOMSpline = spline(timeFrame,[velCOMVec(two), velCOMVec(two+2)]);
    velCOM = ppval(velCOMSpline,t);
    velCOMNext = ppval(velCOMSpline,t+dt);
    
    dthetaCOMSpline = spline(timeFrame,[dthetaCOMVec(one), dthetaCOMVec(one+1)]);
    dthetaCOM = ppval(dthetaCOMSpline,t);
    dthetaCOMNext = ppval(dthetaCOMSpline,t+dt);
    
    for i = 1:N
        velEndEffectorSpline = spline(timeFrame,[velEndEffectorVec(two+(i-1)*2), velEndEffectorVec(two+2+(i-1)*2)]);
        velEndEffector(i*2-1:i*2) = ppval(velEndEffectorSpline,t);
    end
     
    % Compute LCI
    for i = 1:N
        e = posEndEffector(2*i);       % y component of end effector i (distance between effector and floor, should be zero if in contact)
        dex = velEndEffector(2*i - 1); % velocity of end effector i in x direction(should be zero)
        dey = velEndEffector(2*i);     % velocity of end effector i in y direction(should be zero)
        LCI = LCI + cVec(i)*(norm(e) + norm(dex) + norm(dey));  % compute LCI cost (see eqn 2)
    end
    
    % Perform QP to find contact forces f and control input u
    x0 = zeros(n*N + D,1); % initial guess of all zeros
    A = zeros(N,n*N + D);  % friction cone constraints
    for i = 1:N
        A(i,2*i-1) = 1;
        A(i,2*i) = -mu;
    end
    b = zeros(N,1);        % friction cone constraints
    options = optimset('Display', 'Off');
    X = fmincon(@(x)qpFunc(x,cVec,n,N,D,m,g,I,dt,posCOM,thetaCOM,posEndEffector,velCOM,dthetaCOM, posCOMNext,thetaCOMNext,velCOMNext,dthetaCOMNext),x0,A,b,[],[],[],[],[],options);
    f = X(1:n*N);
    u = X(n*N+1:end);
    
    % Compute physics cost
    LPhysics = LPhysics + computeDynError(f,u,N,m,g,I,dt,posCOM,thetaCOM,posEndEffector,velCOM,dthetaCOM, posCOMNext,thetaCOMNext,velCOMNext,dthetaCOMNext);
    
    LTask = LTask + norm(f) + norm(u);
end

posError = [];
posError(1) = posCOMVec(end-1) - (posEndEffectorVec(end-N*2+1) + posEndEffectorVec(end-N*2+3))/2; % This assumes that the feet correspond to end effectors 1,2
posError(2) = posCOMVec(end) - 2*L + 0.5 ; %COM should be 0.5m above hips, and legs fully extended
posError(3) = thetaCOMVec(end) - pi/2; % torso should be vertical

% lStand is cost of error between final position and desired position
lStand = norm(posError);

% Task cost is sum of pos error, contact forces, and control input
LTask = LTask + lStand;

% For first phase, only optimize for task
cost = LTask + LPhysics + LCI
end



