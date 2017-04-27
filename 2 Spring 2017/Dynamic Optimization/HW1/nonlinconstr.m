function [c,ceq] = nonlinconstr(angles,N,link_length,target, obstacles)
[tip,R] = FK(angles,N,link_length);

% Locate joint positions
jointpos = [0;0;0];
for i = 1:N
    jointpos(:,i+1) = FK(angles,i,link_length);
end

% Interpolate link positions
n = 20;
checkcost = -1;
for i = 1:N % each link
    for j = 1:3 % x,y,z
        links((n*(i-1)+1):(n*(i-1)+n),j) = linspace(jointpos(j,i), jointpos(j,i+1), n); % generate link interior points
    end
end

% check against obstacles
for i = 1:N % For each link...
    for k = 1:n*N % for each interior point...
        for l = 1:length(obstacles(:,1)) % for each obstacle...
            check = norm(links(k,:) - obstacles(l,1:3)); % compute distance to center
            if check < obstacles(l,4) % if within radius...
                checkcost = 10*(obstacles(l,4) - check);  % violate constraint
            else
                checkcost = 0.1*(obstacles(l,4) - check);  % stay away
            end
        end
    end
end

ceq = norm(tip - target(1:3)');
c = checkcost;
end