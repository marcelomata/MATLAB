clear all;

% Parameters to be sweeped
period = Simulink.Parameter(1);
fore_lag = Simulink.Parameter(0);
period.CoderInfo.StorageClass = 'SimulinkGlobal';
fore_lag.CoderInfo.StorageClass = 'SimulinkGlobal';

minitaurParameters;

% Experiment Initial Setup -- appropriate variables changed in loops
fore_lag = 0;
lr_sync = 1;
period = 1.5;
phi_0 = 0.5*asin(l1/l2);
r_0 = l2;
r_x = 0.5*l1;
r_y = 0.3*l1;

% What to sweep

period_vals = linspace(0.5,4,4);
fore_lag_vals = linspace(0,0.9,4);

output = cell(numel(period_vals), numel(fore_lag_vals));

% Set up parfor parallelization
parpool;

model = 'experiment_toplevel';
load_system(model);
set_param(model,'SimulationMode','accelerator');

% Fast restart not helpful with parfor the way it's setup now. Can try
% outer parfor loop with inner for loops scanning parameters (with fast
% restart on in each thread).
%set_param(model,'FastRestart','on')


for i=1:size(output, 1)
   parfor j=1:size(output, 2)
      
      cwd = pwd;
      addpath(pwd);
      tmpdir = sprintf('tmp%d-%d',i,j);
      mkdir(tmpdir);
      cd(tmpdir);
      load_system(model);
       
      % period = period_vals(i);
      % fore_lag = fore_lag_vals(j);
      assignin('base', 'lr_sync',lr_sync);
      assignin('base', 'period',period);
      assignin('base', 'phi_0',phi_0);
      assignin('base', 'r_0',r_0);
      assignin('base', 'r_x',r_x);
      assignin('base', 'r_y',r_y);
      assignin('base', 'period', period_vals(i));
      assignin('base', 'fore_lag', fore_lag_vals(j));
        
      fprintf('Running (%g,%g)...\n', i, j);
      tic
      simout = sim(model, 'SimulationMode', 'accelerator','StopTime', '5','CaptureErrors','on'); % accelerator
      toc
      output{i,j} = struct('body_state', simout.get('body_state'), ...
            'P_mech', simout.get('P_mech'), ...
            'P_in', simout.get('P_in'), ...
            'GRF_z', simout.get('GRF_z'), ...
            'GRF_y', simout.get('GRF_y'));
      
      fprintf('done.\n');
      
      close_system(model,0);
      cd(cwd);
      evalin('base', 'clear mex');
      rmdir(tmpdir,'s');
      rmpath(cwd);
       
   end
end

delete(gcp('nocreate'));
close_system(model,0);

datetime=datestr(now);
datetime=strrep(datetime,':','_'); %Replace colon with underscore
datetime=strrep(datetime,'-','_');%Replace minus sign with underscore
datetime=strrep(datetime,' ','_');%Replace space with underscore
filename=['vars_' datetime];
save(filename);


