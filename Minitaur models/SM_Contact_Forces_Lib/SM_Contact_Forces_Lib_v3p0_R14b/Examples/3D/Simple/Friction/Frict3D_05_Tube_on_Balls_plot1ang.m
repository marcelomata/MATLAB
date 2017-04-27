% Code to plot simulation results from Frict3D_05_Tube_on_Balls
%
% Copyright 2015 The MathWorks, Inc.

% Reuse figure if it exists, else create new figure
try
    figure(h1_Frict3D_05_Tube_on_Balls)
catch
    h1_Frict3D_05_Tube_on_Balls=figure('Name','Frict3D_05_Tube_on_Balls');
end

% Generate simulation results if they don't exist
if(~exist('simlog_Frict3D_05_Tube_on_Balls','var'))
    sim('Frict3D_05_Tube_on_Balls')
end

% Get simulation results
temp_b1rx = simlog_Frict3D_05_Tube_on_Balls.Gimbal_Joint_Ball_1.Rx.q.series;
temp_b1ry = simlog_Frict3D_05_Tube_on_Balls.Gimbal_Joint_Ball_1.Ry.q.series;
temp_b1rz = simlog_Frict3D_05_Tube_on_Balls.Gimbal_Joint_Ball_1.Rz.q.series;

temp_tupy = simlog_Frict3D_05_Tube_on_Balls.Bushing_Joint.Py.p.series;
temp_tury = simlog_Frict3D_05_Tube_on_Balls.Bushing_Joint.Ry.q.series;

% Plot results
ah(1) = subplot(2,1,1);
plot(temp_b1rx.time,temp_b1rx.values('deg'),'r','LineWidth',1)
hold on
plot(temp_b1ry.time,temp_b1ry.values('deg'),'g','LineWidth',1,'LineStyle','--')
plot(temp_b1rz.time,temp_b1rz.values('deg'),'b','LineWidth',1,'LineStyle','-.')
hold off
grid on
title('Ball 1 Orientation');
ylabel('Angle (deg)');
legend({'Rx','Ry','Rz'},'Location','Best')

subplot(2,1,2);
[hAx, hLine1, hLine2] = plotyy(temp_tupy.time,...
    temp_tupy.values('m'),temp_tury.time,temp_tury.values('deg'));
grid on
set(hAx(1),'YLim',[-1 1]*0.25);
set(hAx(2),'YLim',[-1 1]*30);
set([hLine1 hLine2],'LineWidth',1);
ylabel(hAx(1),'Position (m)');
ylabel(hAx(2),'Angle (deg)');
title('Tube Position and Orientation');
xlabel('Time (s)');
legend({'Axial Position','Axial Angle'},'Location','Best')

linkaxes([ah hAx],'x');

% Remove temporary variables
clear temp_b1rx temp_b1ry temp_b1rz temp_tupy temp_b2Q temp_tury
