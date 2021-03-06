function [r, p, y] = part1(N,target, link_length, min_roll, max_roll, min_pitch, max_pitch, min_yaw, max_yaw, obstacles)
%% Function that uses optimization to do inverse kinematics for a snake robot

%%Outputs 
  % [r, p, y] = roll, pitch, yaw vectors of the N joint angles
  %            (N link coordinate frames)
%%Inputs:
    % target: [x, y, z, q0, q1, q2, q3]' position and orientation of the end
    %    effector
    % link_length : Nx1 vectors of the lengths of the links
    % min_xxx, max_xxx are the vectors of the 
    %    limits on the roll, pitch, yaw of each link.
    % limits for a joint could be something like [-pi, pi]
    % obstacles: A Mx4 matrix where each row is [ x y z radius ] of a sphere
    %    obstacle. M obstacles.
    
    options =  optimset('Algorithm', 'interior-point')
    x0 = zeros(N+1,3);
    [x, eval] = fmincon(@(angles)costfcn(angles,N,link_length,target, min_roll, max_roll, min_pitch, max_pitch, min_yaw, max_yaw,obstacles), x0,[],[],[],[],[min_roll,min_pitch,min_yaw],[max_roll,max_pitch,max_yaw],@(angles)nonlinconstr(angles,N,link_length,target,obstacles), options)
    r = x(1:N,1);
    p = x(1:N,2);
    y = x(1:N,3);
end