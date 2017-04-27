% Code to plot simulation results from Robot_2_Whl
%
% Copyright 2015-2016 The MathWorks, Inc.

% Reuse figure if it exists, else create new figure
try
    figure(h1_Robot_2_Whl)
catch
    h1_Robot_2_Whl=figure('Name','Robot_2_Whl');
end

% Generate simulation results if they don't exist
if(~exist('simlog_Robot_2_Whl','var'))
    sim('Robot_2_Whl')
end

% Get simulation results
temp_robotxy = logsout_Robot_2_Whl.getElement('Robot xy').Values;

temp_hWksp = get_param(bdroot,'ModelWorkspace');
temp_table = temp_hWksp.getVariable('table');
temp_platform = temp_hWksp.getVariable('platform');
temp_axle = temp_hWksp.getVariable('axle');
temp_wheel = temp_hWksp.getVariable('whl');

%temp_xcir = sin(0:0.2:2*pi)*peg.rad;
%temp_ycir = cos(0:0.2:2*pi)*peg.rad;

% Plot board
patch([-1 1 1 -1]*temp_table.length/2,[-1 -1 1 1]*temp_table.length/2,[1 1 1]*0.8);
hold on

% Plot robot path
fill(sin(0:0.1:2*pi)*temp_platform.radius+temp_robotxy.Data(1,1),...
     cos(0:0.1:2*pi)*temp_platform.radius+temp_robotxy.Data(1,2),...
     [115 167 89]/200);
plot(temp_robotxy.Data(:,1),temp_robotxy.Data(:,2),'Color',[115 167 89]/255,'LineWidth',3);
plot([1 1]*(temp_robotxy.Data(1,1)+temp_axle.length/2),...
     [1 1]*temp_robotxy.Data(1,2)+[1 -1]*temp_wheel.rad/2,'Color',[0.8 0.5 0.2],'LineWidth',2);
plot([1 1]*(temp_robotxy.Data(1,1)-temp_axle.length/2),...
     [1 1]*temp_robotxy.Data(1,2)+[1 -1]*temp_wheel.rad/2,'Color',[0.8 0.5 0.2],'LineWidth',2);
hold off

box on
axis([[-1 1]*temp_table.length/2 [-1 1]*temp_table.length/2]*1.1);
axis equal
title('Robot Path');
ylabel('Y-Position (m)');
xlabel('X-Position (m)');

% Remove temporary variables
clear temp_platform temp_robotxy temp_axle temp_table temp_hWksp temp_wheel

