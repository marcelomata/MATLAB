close all
clear all
clc

N = 7;
x = 1.5;
y = 1.5;
z = 2;
q0 = cos(pi/8);
q1 = 0;
q2 = 0;
q3 = 1*sin(pi/8);
target = [x,y,z,q0,q1,q2,q3];
link_length = ones(1,N);
min_roll = -pi;
min_pitch = -pi;
min_yaw = -pi;
max_roll = pi;
max_pitch = pi;
max_yaw = pi;
%obstacles = [1,1,1,0.2;1,0,0,0.3];
obstacles = [1,1,1,0.2;1,0,0,0.3;0,1,1,0.2;1,1,2,0.2;2,2,2,0.4];

[r,p,y] = part1(N,target, link_length, min_roll, max_roll, min_pitch, max_pitch, min_yaw, max_yaw, obstacles);

