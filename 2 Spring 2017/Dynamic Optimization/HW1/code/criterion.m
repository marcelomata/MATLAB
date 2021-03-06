%% optimization criterion: joints is vector of joint angles
function [score, gradient] = criterion(joints,target,linkLengths,min_roll,min_pitch,min_yaw,max_roll,max_pitch,max_yaw,answers, currentIteration)
    joints = reshape(joints,[length(linkLengths) 3]);

    %forward kinematics
    [pose, ~] = fk(joints,linkLengths,target);
    
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
    
    if currentIteration > 1
        %cost on previous solutions
        for i=2:size(answers,3)
            prev_solution_costs(i) = 1/norm(joints-answers(:,:,i));
        end
        prev_solution_cost = 1*sum(prev_solution_costs);
    else
        prev_solution_cost = 0;
    end
    
    %total cost
    score = final_pose_cost + joint_limit_cost + prev_solution_cost;
end