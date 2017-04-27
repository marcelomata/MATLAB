function cost = costfcn(angles,N,link_length,target, min_roll, max_roll, min_pitch, max_pitch, min_yaw, max_yaw,obstacles)

% Run FK
[tip,R] = FK(angles,N,link_length);

% Compute target orientation (R matrix)
x = target(1);
y = target(2);
z = target(3);
theta = 2*acos(target(4));
ax = target(5)/sin(theta/2);
ay = target(6)/sin(theta/2);
az = target(7)/sin(theta/2);
c = cos(theta);
s = sin(theta);
Rquat = [c + ax^2*(1-c), ax*ay*(1-c) - az*s, ax*az*(1-c) + ay*s; ay*ax*(1-c) + az*s, c+ay^2*(1-c), ay*az*(1-c) - ax*s; az*ax*(1-c) - ay*s, az*ay*(1-c) + ax*s, c+az^2*(1-c)];

% Locate joint positions
jointpos = [0;0;0];
for i = 1:N
    jointpos(:,i+1) = FK(angles,i,link_length);
end

% Draw links and obstacles
plot3(jointpos(1,:),jointpos(2,:),jointpos(3,:))
xlabel('x');
ylabel('y');
zlabel('z');
axis equal
hold on
for i = 1:length(obstacles(:,1))
    [xo,yo,zo] = sphere;
    surf(obstacles(i,4)*xo+obstacles(i,1),obstacles(i,4)*yo+obstacles(i,2),obstacles(i,4)*zo+obstacles(i,3))
    hold on
end
drawnow
hold off

% Calculate distances from current Euler angles to average angles
avg_roll = (max_roll + min_roll)/2;
avg_pitch = (max_pitch + min_pitch)/2;
avg_yaw = (max_yaw + min_yaw)/2;
for i = 1:N+1
    meanangles(i,1) = avg_roll;
    meanangles(i,2) = avg_pitch;
    meanangles(i,3) = avg_yaw;
end

% Compute cost
poserror = (tip(1) - x)^2 + (tip(2) - y)^2 + (tip(3) - z)^2
orienterror = norm(Rquat - R)
angleerror = norm(angles - meanangles)

cost = poserror + orienterror + 0.1*angleerror;
    
end