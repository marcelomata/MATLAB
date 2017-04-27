%% 16745 Dynamic Optimization Assignment 3

%{
Phase 1 cost function script
Cost = LTask, physics is ignored

Written by: Joe Norby et al
%}

function cost = computeCost_1(s,N,K)

% Assumes s vector is encoded as:
% s = [pc;rc;p1...N;r1...N;             % from time 1 to time K
%      pcdot;rcdot;p1...Ndot;r1...Ndot; % from time 1 to time K
%      c1...N                           % from time 1 to time K
%     ]                   

% Set up model params
L = 0.5;  % length of joints
l = 0.5;  % distance from COM to joints

% Set up dimensionality params
N = 4; % number of end effectors
K = 10; % number of movement phases + 1 (number of knots)

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
for ii = 2:K
    posCOMVec = [posCOMVec; s((3*(N+1))*(ii-1)+1:(3*(N+1))*(ii-1) + 2)];
    thetaCOMVec = [thetaCOMVec; s((3*(N+1))*(ii-1)+3)];
    posEndEffectorVec = [posEndEffectorVec; s((3*(N+1))*(ii-1)+4:(3*(N+1))*ii - N)];
    thetaEndEffectorVec = [thetaEndEffectorVec; s((3*(N+1))*ii - N + 1:(3*(N+1))*ii)];
    velCOMVec = [velCOMVec; s(3*K*(N+1)+ (3*(N+1))*(ii-1)+1:3*K*(N+1)+ (3*(N+1))*(ii-1) + 2)];
    dthetaCOMVec = [dthetaCOMVec; s(3*K*(N+1)+ (3*(N+1))*(ii-1)+3)];
    velEndEffectorVec = [velEndEffectorVec; s(3*K*(N+1)+ (3*(N+1))*(ii-1)+4:3*K*(N+1)+ (3*(N+1))*ii - N)];
    dthetaEndEffectorVec = [dthetaEndEffectorVec; s(3*K*(N+1)+ (3*(N+1))*ii - N + 1:3*K*(N+1)+ (3*(N+1))*ii)];
end


posError = [];
posError(1) = posCOMVec(end-1) - (posEndEffectorVec(end-N*2+1) + posEndEffectorVec(end-N*2+3))/2; % This assumes that the feet correspond to end effectors 1,2
posError(2) = posCOMVec(end) - 2*L + 0.5 ; %COM should be 0.5m above hips, and legs fully extended
posError(3) = thetaCOMVec(end) - pi/2; % torso should be vertical

% lStand is cost of error between final position and desired position
lStand = norm(posError);

% Task cost is sum of pos error, contact forces, and control input
LTask = lStand;

% For first phase, only optimize for task
cost = LTask
end



