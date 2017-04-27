function [ xmin ] = purecmaes(input1,input2,inputn)
clear
clc

%PURECMAES Copied from Wikipedia, edited 
%   Detailed explanation goes here
% --------------------  Initialization --------------------------------  
  % User defined input parameters (need to be edited)
  strfitnessfct = 'quadslipcost';  % name of objective/fitness function
  
  %edited parameters: afr, abr, afl, abl, kb, kf, x0, theta0 
  %N = 11;  %Full              % number of objective variables/problem dimension
 
  %just alpha values
  N = 11;
  xmean = rand(N,1);% objective variables initial point
  %% Set seeds
% a0fl= x(1); For reference
% a0fr= x(2);
% a0bl= x(3);
% a0br = x(4);
% kf= x(5);
% kb= x(6);
% dx0= x(7);
% y0= x(8);
% t0= x(9);
% dt0 = x(10);

xmean(1) = 1;
xmean(2) = 1;
xmean(3) = 1;
xmean(4) = 1;
xmean(5) = 2;
xmean(6) = 0.8;
xmean(7) = 0;
xmean(8) = 0.5;
xmean(9) = 0.5;
xmean(10) = -0.5;
xmean(11) = -0.5;


%     1.3123
%     0.9231
%     1.0946
%     1.2098
%     1.0862
%     1.4441
%     0.5652
%     0.9764
%     0.0185
%     1.2606

%change these seeds per gait?    
    
    
  
  %sigma = 0.3;          % coordinate wise standard deviation (step size)
  sigma = 0.1;
  stopfitness = 1e-8;  % stop if fitness < stopfitness (minimization)
  stopeval = 1e3*N^2;   % stop after stopeval number of function evaluations
  
  %% Strategy parameter setting: Selection  
  lambda = 4+floor(3*log(N));  % population size, offspring number
  mu = lambda/2;               % number of parents/points for recombination
  weights = log(mu+1/2)-log(1:mu)'; % muXone array for weighted recombination
  mu = floor(mu);        
  weights = weights/sum(weights);     % normalize recombination weights array
  mueff=sum(weights)^2/sum(weights.^2); % variance-effectiveness of sum w_i x_i

  %% Strategy parameter setting: Adaptation
  cc = (4+mueff/N) / (N+4 + 2*mueff/N);  % time constant for cumulation for C
  cs = (mueff+2) / (N+mueff+5);  % t-const for cumulation for sigma control
  c1 = 2 / ((N+1.3)^2+mueff);    % learning rate for rank-one update of C
  cmu = min(1-c1, 2 * (mueff-2+1/mueff) / ((N+2)^2+mueff));  % and for rank-mu update
  damps = 1 + 2*max(0, sqrt((mueff-1)/(N+1))-1) + cs; % damping for sigma 
                                                      % usually close to 1
  %% Initialize dynamic (internal) strategy parameters and constants
  pc = zeros(N,1); ps = zeros(N,1);   % evolution paths for C and sigma
  B = eye(N,N);                       % B defines the coordinate system
  D = ones(N,1);                      % diagonal D defines the scaling
  C = B * diag(D.^2) * B';            % covariance matrix C
  invsqrtC = B * diag(D.^-1) * B';    % C^-1/2 
  eigeneval = 0;                      % track update of B and D
  chiN=N^0.5*(1-1/(4*N)+1/(21*N^2));  % expectation of 
                                      %   ||N(0,I)|| == norm(randn(N,1)) 
  %% -------------------- Generation Loop --------------------------------
  counteval = 0;  % the next 40 lines contain the 20 lines of interesting code 
  while counteval < stopeval
    
      % Generate and evaluate lambda offspring
      for k=1:lambda,
          arx(:,k) = xmean + sigma * B * (D .* randn(N,1)); % m + sig * Normal(0,C) 
          arfitness(k) = feval(strfitnessfct, arx(:,k)); % objective function call
          counteval = counteval+1
      end
    
      % Sort by fitness and compute weighted mean into xmean
      [arfitness, arindex] = sort(arfitness); % minimization
      xold = xmean;
      xmean = arx(:,arindex(1:mu))*weights;   % recombination, new mean value
    
      % Cumulation: Update evolution paths
      ps = (1-cs)*ps ... 
            + sqrt(cs*(2-cs)*mueff) * invsqrtC * (xmean-xold) / sigma; 
      hsig = norm(ps)/sqrt(1-(1-cs)^(2*counteval/lambda))/chiN < 1.4 + 2/(N+1);
      pc = (1-cc)*pc ...
            + hsig * sqrt(cc*(2-cc)*mueff) * (xmean-xold) / sigma;

      % Adapt covariance matrix C
      artmp = (1/sigma) * (arx(:,arindex(1:mu))-repmat(xold,1,mu));
      C = (1-c1-cmu) * C ...                  % regard old matrix  
           + c1 * (pc*pc' ...                 % plus rank one update
                   + (1-hsig) * cc*(2-cc) * C) ... % minor correction if hsig==0
           + cmu * artmp * diag(weights) * artmp'; % plus rank mu update

      % Adapt step size sigma
      sigma = sigma * exp((cs/damps)*(norm(ps)/chiN - 1)); 
    
      % Decomposition of C into B*diag(D.^2)*B' (diagonalization)
      if counteval - eigeneval > lambda/(c1+cmu)/N/10  % to achieve O(N^2)
          eigeneval = counteval;
          C = triu(C) + triu(C,1)'; % enforce symmetry
          [B,D] = eig(C);           % eigen decomposition, B==normalized eigenvectors
          D = sqrt(diag(D));        % D is a vector of standard deviations now
          invsqrtC = B * diag(D.^-1) * B';
      end
    
      % Break, if fitness is good enough or condition exceeds 1e14, better termination methods are advisable 
      if arfitness(1) <= stopfitness || max(D) > 1e7 * min(D)
          break;
      end

  end % while, end generation loop

  xmin = arx(:, arindex(1)); % Return best point of last iteration.
                             % Notice that xmean is expected to be even
                          % better.
                          
end
%% ---------------------------------------------------------------  
function f=quadslipcost(x)
    if size(x,1) < 2 error('dimension must be greater one'); end
    %here is where we are gonna call our sim 
    %need to figure out what our cost function will be
    %example cost function: f = 100*sum((x(1:end-1).^2 - x(2:end)).^2) + sum((x(1:end-1)-1).^2);

set(0, 'DefaultAxesFontSize', 14);
set(0,'DefaultAxesXGrid','on','DefaultAxesYGrid','on')



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%x is dimension of 1,N
% General params
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
set_param('SLIPquadwalk/S-R Flip-Flop1','initial_condition','flic')
set_param('SLIPquadwalk/S-R Flip-Flop2','initial_condition','blic')
set_param('SLIPquadwalk/S-R Flip-Flop3','initial_condition','fric')
set_param('SLIPquadwalk/S-R Flip-Flop4','initial_condition','bric')
x0 = 0;

x
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

%time_of_sim is the last time clock from simulation 



%values from the simulation are going to the workspace but not seen by cost
%function 
%cost function should include stability and metabolics
%evaluation of stability: time until simulation ends
%simulation enders: dx <0, y_body<0, body angle past +/- 180 deg
   
end

