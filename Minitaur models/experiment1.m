clear all;

minitaurParameters;

% Experiment Initial Setup -- appropriate variables changed in loops
fore_lag = 0;
lr_sync = 1;
period = 1.5;
phi_0 = 0.5*asin(l1/l2);
r_0 = l2;
r_x = 0.3*l1;
r_y = 0.2*l1;

period_vals = [1 1.5];%linspace(0.5, 4, 2);
fore_lag_vals = [0.5];%linspace(0,0.9,2);

output = cell(numel(period_vals), numel(fore_lag_vals));

for i=1:size(output, 1)
   for j=1:size(output, 2)
      
      period = period_vals(i);
      fore_lag = fore_lag_vals(j);
      
      fprintf('Running (%g,%g)...', i, j);
      tic
      simout = sim('experiment_toplevel', 'SimulationMode', 'accelerator','StopTime', '20'); % accelerator
      toc
      output{i,j} = struct('body_state', simout.get('body_state'), ...
            'P_mech', simout.get('P_mech'), ...
            'P_in', simout.get('P_in'), ...
            'GRF_z', simout.get('GRF_z'), ...
            'GRF_y', simout.get('GRF_y'));
      
      fprintf('done.\n');
       
   end
end

datetime=datestr(now);
datetime=strrep(datetime,':','_'); %Replace colon with underscore
datetime=strrep(datetime,'-','_'); %Replace minus sign with underscore
datetime=strrep(datetime,' ','_'); %Replace space with underscore
filename=['vars_' datetime];
save(filename);


