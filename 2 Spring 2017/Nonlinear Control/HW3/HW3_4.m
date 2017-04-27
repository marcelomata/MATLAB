% HW 3_4
close all
clear
clc
set(0, 'DefaultAxesFontSize', 14);
set(0,'DefaultAxesXGrid','on','DefaultAxesYGrid','on')

delta = 0.75;
N = 100;
dt = delta/N;
tvec = [0:dt:delta];
f = sin(tvec);
x0 = 1;

phi = x0*ones(1,N+1);
for n = 1:5
    Pphi(n,1) = x0;
    phi(n+1,1) = x0; % Initialize phi
    for k = 2:N+1
        phi(n+1,k) = Pphi(n,k-1) + sin(phi(n,k))*dt; % Compute new phi
        Pphi(n,k) = phi(n+1,k); % Update Phi (phi_n+1)
    end
end

figure(1)
subplot(2,1,1)
plot(tvec,phi(end,:), ':k')
hold on

hw3_4func = @(t,x)[sin(x)];
[t,x] = ode45(hw3_4func, tvec, x0);

plot(t,x, 'b--')

xlabel('t', 'interpreter', 'latex')
ylabel('$\phi (x)$', 'interpreter', 'latex')

legend('Contraction Mapping', 'Numerical Integration', 'Location', 'Northwest')
title('Figure 3. Contraction Mapping Approximation of $\dot{x} = sin(x)$', 'interpreter', 'latex')

subplot(2,1,2)
plot(t,phi(end,:)'-x)

xlabel('t', 'interpreter', 'latex')
ylabel('error', 'interpreter', 'latex')