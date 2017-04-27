%% 16745 Dynamic Optimization Assignment 3

%{
Main function evaluation script

Written by: Joe Norby et al
%}
close all
clear
clc

% address (in this order):
% kinematic constraints
% figure out why costs aren't changing
% angle between end effector and contact forces?

N = 4;
K = 10;
x0 = ones((6*(N+1) + N)*K,1); % Initialize s-vector

opts = optimset('TolFun', 1e-7);
% Three phases, add small gaussian noise to the input of each to break
% symmetries
s1 = fminsearch(@(s)computeCost_1(s,N,K), x0, opts)
s2 = fminsearch(@(s)computeCost_2(s,N,K), s1 + 0.0001*wgn((6*(N+1) + N)*K,1,1), opts)
s3 = fminsearch(@(s)computeCost_3(s,N,K), s2 + 0.0001*wgn((6*(N+1) + N)*K,1,1), opts)
