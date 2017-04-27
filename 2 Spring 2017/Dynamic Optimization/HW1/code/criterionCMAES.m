%% optimization criterion: joints is vector of joint angles
function [score, gradient] = criterion(joints)
    global target linkLengths min_roll min_pitch min_yaw max_roll max_pitch max_yaw obstacles

    joints = reshape(joints,[length(linkLengths) 3]);

    %forward kinematics
    [pose, positions] = fk(joints,linkLengths,target);
    
    %joints near limit their limits cost
    for i=1:length(joints)
        roll_average(i) = mean([min_roll(i) max_roll(i)]);
        pitch_average(i) = mean([min_pitch(i),max_pitch(i)]);
        yaw_average(i) = mean([min_yaw(i),max_yaw(i)]);
        difference_matrix(i,:) = [abs(joints(i,1)-roll_average(i)), abs(joints(i,2)-pitch_average(i)), abs(joints(i,3)-yaw_average(i))];
    end
    joint_limit_cost = 0.25 * norm(difference_matrix);
    
    %final pose cost
    final_pose_cost = 5 * norm(pose(1:7)-target(1:7));  
    
    %avoid obstacle cost
    numPoints = 10;
    zeroVector = [0;0;0];
    positions = [zeroVector positions];
    for i = 1:length(linkLengths) % each link
        for j = 1:3 % x,y,z
            checkPoints((numPoints*(i-1)+1):(numPoints*(i-1)+numPoints),j) = linspace(positions(j,i), positions(j,i+1), numPoints); %generate link interior
        end
    end
    for i=1:length(obstacles(:,1))
        for j=1:length(checkPoints)
           distances(i,j) = norm(checkPoints(j,:)-obstacles(i,1:3));
        end
        minDistance(i) = min(distances(i,:));
        distToSphere(i) = minDistance(i) - (obstacles(i,4) + 0.1);
        if distToSphere(i)>=0
            distCost(i) = 0;
        else
            distCost(i) = 1;
        end    
    end
    obstacle_cost = sum(distCost);
    
    %total cost
    score = final_pose_cost + joint_limit_cost + obstacle_cost;
end