% HW 4_2
close all
clear
clc
set(0, 'DefaultAxesFontSize', 14);
set(0,'DefaultAxesXGrid','on','DefaultAxesYGrid','on')

N = 100;
frame = 10;

hw4_2func = @(t,x)[x(1) - x(1)^3 + x(2);3*x(1)-x(2)];

figure(1)
for i=1:N
    x1 = rand*frame*2 - frame;
    x2 = rand*frame*2 - frame;
    [t,x] = ode45(hw4_2func, [0,10], [x1 x2]);
    plot(x1,x2, 'ro', 'markersize', 5)
    hold on
    plot(x(:,1),x(:,2), 'k-')
end
hold on
plot([0,2,-2], [0 6 -6], 'b.', 'markersize', 30);
axis([-frame frame -frame frame])
xlabel('x_1');
ylabel('x_2');