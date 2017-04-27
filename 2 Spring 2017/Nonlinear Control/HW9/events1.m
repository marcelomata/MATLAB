function [value,isterminal,direction] = events1(t,x,D,H,k,K,a,threshold)
% Locate the time when threshold is activated and stop integration.
value = sqrt(x(1)^2 + x(3)^2) - threshold; % detect y-1/2 = 0
% disp(['value = ',num2str(value)]);
isterminal = 1; % stop the integration
direction = -1; % negative direction