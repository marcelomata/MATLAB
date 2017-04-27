% HW 9_3
close all
clear
clc
set(0, 'DefaultAxesFontSize', 14);
set(0,'DefaultAxesXGrid','on','DefaultAxesYGrid','on')

x0 = [1;1;1;1];
x = fminsearch(@opt9_3, x0);