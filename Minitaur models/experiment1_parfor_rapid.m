%% 16-868 Final Project Experiment Gait Parameter Sweep

%% Notification setup
notify_recip = {'avolkovjr@cmu.edu'};
subj_err = 'Minitaur Simulation: Something Went Wrong';
subj_complete = 'Minitaur Simulation: All Done!';

%% Start the clock!
tic

%% What parameters to sweep?
period_vals = linspace(0.3,0.6,2);
fore_lag_vals = linspace(0,0.8,2);
lr_sync_vals = [0 1];

%% Simulation Duration
tDuration = 5;

%% Compile the Simulink file
mdl = 'experiment_toplevel';
open_system(mdl);
set_param(mdl,'SimulationMode','rapid-accelerator');
rtp = Simulink.BlockDiagram.buildRapidAcceleratorTarget(mdl);
close_system(mdl,0);

%% Set up the parameter sets object
num_period_vals = length(period_vals);
num_fore_lag_vals = length(fore_lag_vals);
num_lr_sync_vals = length(lr_sync_vals);
numParamSets = num_period_vals*num_fore_lag_vals*num_lr_sync_vals;

paramSets = cell(1, numParamSets);
idx = 1;experiment_toplevel
for i = 1:num_lr_sync_vals
    for j = 1:num_period_vals
        for k = 1:num_fore_lag_vals
            paramSets{idx} = ...
                Simulink.BlockDiagram.modifyTunableParameters(rtp, ...
                'lr_sync',lr_sync_vals(i), ...
                'period',period_vals(j), ...
                'fore_lag',fore_lag_vals(k));
            idx = idx+1;
        end
    end
end

simCmdParamValStructs = cell(1, numParamSets);
externalInput = cell(1, numParamSets);

paramValStruct.StopTime = num2str(tDuration);
paramValStruct.CaptureErrors = 'on';
paramValStruct.SimulationMode = 'rapid';
paramValStruct.RapidAcceleratorUpToDateCheck = 'off';
paramValStruct.RapidAcceleratorParameterSets = [];

idx = 1;
for paramSetsIdx = 1:numParamSets
        simCmdParamValStructs{idx} = paramValStruct;
        simCmdParamValStructs{idx}.RapidAcceleratorParameterSets = ...
            paramSets{paramSetsIdx};
        idx = idx + 1;
end

%% Run the experiment trials in parallel!
% Wrapped in a try-catch to survive individual experiment failures
err = [];
try
    % Set up parfor parallelization
    parpool;

    out = cell(1, numParamSets);

    parfor_progress(numParamSets);

    parfor i = 1:numParamSets

        t = getCurrentTask();

        simout = sim(mdl,simCmdParamValStructs{i});

        out{i} = struct('lr_sync',lr_sync,...
            'period',period, ...
            'fore_lag',fore_lag, ...
            'body_state', simout.get('body_state'), ...
            'P_mech', simout.get('P_mech'), ...
            'P_in', simout.get('P_in'), ...
            'GRF_z', simout.get('GRF_z'), ...
            'GRF_y', simout.get('GRF_y'));

        parfor_progress;

    end

    parfor_progress(0);

    toc

catch err
    warning(['The following bad thing happened: ' getReport(err)]);
    msg = sprintf('Something went wrong @ %s', datestr(now));
    send_msg(notify_recip, subj_err, msg);
end
    
delete(gcp('nocreate'));

%% Save the data
datetime=datestr(now);
datetime=strrep(datetime,':','_'); %Replace colon with underscore
datetime=strrep(datetime,'-','_'); %Replace minus sign with underscore
datetime=strrep(datetime,' ','_'); %Replace space with underscore
filename=['vars_' datetime];
save(filename);

if isempty(err)
    msg = sprintf('The simulation finished @ %s', datestr(now));
    send_msg(notify_recip, subj_complete, msg);
end