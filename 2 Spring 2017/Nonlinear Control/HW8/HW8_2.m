% HW 8_2
close all
clear
clc
set(0, 'DefaultAxesFontSize', 14);
set(0,'DefaultAxesXGrid','on','DefaultAxesYGrid','on')

syms s

A = [0,0,1;0,-1,0;0,0,-1];
B = [0;-1;1];
C = [1,0,0];
D = 0;
I = eye(3);

G = C*inv(s*I - A)*B + D

Ahat = [ (s + 1)^2/(s*(s + 1)^2),         0, (s + 1)/(s*(s + 1)^2);
   0, 1/(s + 1),             0;
   0,         0,     1/(s + 1)]