close all
clear
clc

simtime = 30;
set(0, 'DefaultAxesFontSize', 14);
set(0,'DefaultAxesXGrid','on','DefaultAxesYGrid','on')
%% General simulation

close all
clear
clc

simtime = 30;
set(0, 'DefaultAxesFontSize', 14);
set(0,'DefaultAxesXGrid','on','DefaultAxesYGrid','on')

fi = 1;

% params
model = 1; % 1 = passive leg spring, 2 = active leg spring
m = 80; %[kg]
J = 4.58; %[kg m^2]
g = 9.81; %[m/s^2]
L = 0.1; %[m] % Seyfarth - 0.1, active - 0.75
rp = 0.005; %[m] % Seyfarth - 0.1, active - 0.0 testing modelFun at 0.005, borderline at 0.0047
l0 = 1; %[m]
k = 20000; %[N/m] 20000
kv = 0; %[N/ m/s]
kt = 100;

a0 = 67*pi/180; %[rad]  % Seyfarth - 67 deg, active - 25

% initial conditions
t0 = 70*pi/180; %[rad]  % Seyfarth - 91 deg, active - 45
x0 = 0*(-l0 + L*cos(t0)); %[m]
y0 = l0 + L*sin(t0); %[m]

xr0 = -l0*cos(a0) + L*cos(t0);
yr0 = l0*sin(a0) + L*sin(t0);
r0 = sqrt(xr0^2 + yr0^2);

y0 = 1.065; %[m]  % Seyfarth - 1.065, active - 1
dx0 = 5.00; %[m/s]  % Seyfarth - 5.00, active - 5
dy0 = 0; %[m/s]
dt0 = deg2rad(0); %[rad/s]  % Seyfarth - -5.5 deg/s, active - 0

% % apex IC's at t ~= 1000
% y0 = 1.1148;
% t0 = 1.5708;
% dx0 = 4.7461;
% dt0 = -0.0054;

% % 1st apex avg IC's - DONT WORK
% y0 = 1.02878;
% t0 = 1.62736;
% dx0 = 4.90314;
% dy0 = 0.00263128;
% dt0 = 0.0189181;

sim('ASLIPrun2_returnmap')

energy = 1/2*m*vel(:,1).^2 + 1/2*m*vel(:,2).^2 + 1/2*J*vel(:,3).^2 + m*g*pos(:,2) + 1/2*k*dl.^2;

% % STATE  PLOTS
% figure(fi)
% fi = fi+1;
% plot(tout,pos(:,1),tout,pos(:,2))
% xlabel('t [s]')
% ylabel('Position [m]')
% legend('x', 'y', 'Location', 'Northeast')
% 
% figure(fi)
% fi = fi+1;
% plot(tout,vel(:,1),tout,vel(:,2))
% xlabel('t [s]')
% ylabel('Velocity [m/s]')
% legend('dx', 'dy', 'Location', 'Northeast')
% 
% figure(fi)
% fi = fi+1;
% subplot(2,1,1)
% plot(tout,pos(:,3))
% xlabel('t [s]')
% ylabel('pitch angle \theta [rad]')
% 
% subplot(2,1,2)
% plot(tout,vel(:,3))
% xlabel('t [s]')
% ylabel('pitch angular velocity \theta [rad/s]')

%%

close all
n = length(apexpos.Time);
time1 = interpft(apexpos.Time,n);
ttd = interpft(apexpos.Data(:,3),n);
Fs = 1/(time1(2) - time1(1));

fi = 4;
T = 0.001;
%F = griddedInterpolant(tdpos.Time,tdpos.Data(:,3),'pchip');
F = griddedInterpolant(pos2.Time,pos2.Data(:,3),'pchip');
%freq = 0:T:tdpos.Time(end);
freq = 0:T:pos2.Time(end);
ttdinterp = F(freq);


Y = fft(ttdinterp);
l = length(Y);
P2 = abs(Y/l);
P1 = P2(1:floor(l/2)+1);
P1(2:end-1) = 2*P1(2:end-1);
f = (1/T)*(0:(l/2))/l;
% figure(fi)
% fi = fi+1;
% plot(f(2:end),P1(2:end));
% title('Single-Sided Amplitude Spectrum of X(t)')
% xlabel('f (Hz)')
% ylabel('|P1(f)|')
% xlim([0 20]);

% [m,i] = max(P1(2:end));
% w = f(i+1);

KE = 0.5*m*vel(:,1).^2 + 0.5*m*vel(:,2).^2 + 0.5*J*vel(:,3).^2;
PE = m*g*pos(:,2);
KEapex = 0.5*m*apexvel.data(:,1).^2 + 0.5*m*apexvel.data(:,2).^2 + 0.5*J*apexvel.data(:,3).^2;
PEapex = m*g*apexpos.data(:,2);
KEapexavg = 0.5*m*apexvelavg.data(:,1).^2 + 0.5*m*apexvelavg.data(:,2).^2 + 0.5*J*apexvelavg.data(:,3).^2;
PEapexavg = m*g*apexposavg.data(:,2);

for i = 1:(length(PEapex) - 1)
    PEdot(i) = (PEapex(i+1) - PEapex(i))/(apexpos.time(i+1) - apexpos.time(i));
    KEdot(i) = (KEapex(i+1) - KEapex(i))/(apexpos.time(i+1) - apexpos.time(i));
end
PEdot(length(PEapex)) = PEdot(length(PEapex) - 1);
KEdot(length(KEapex)) = KEdot(length(KEapex) - 1);

for i = 1:(length(PEapex) - 1)
    PEddot(i) = (PEdot(i+1) - PEdot(i))/(apexpos.time(i+1) - apexpos.time(i));
    KEddot(i) = (KEdot(i+1) - KEdot(i))/(apexpos.time(i+1) - apexpos.time(i));
end
PEddot(length(PEapex)) = PEddot(length(PEapex) - 1);
KEddot(length(KEapex)) = KEddot(length(KEapex) - 1);



n = 0;

clear timemag PEmag
for i = 1:length(PEapex)
    phasePE(i) = atan2(-PEddot(i),PEdot(i));
    phaseKE(i) = atan2(-KEddot(i),KEdot(i));
    phasePEKE(i) = phasePE(i) - phaseKE(i);

    if phasePE(i)>0.2
        n = n+1;
        PEmag(n) = (PEapex(i)-0.7976)./phasePE(i)';
        timemag(n) = apexpos.time(i);
    end
end

% for i = 1:(length(x.data) - 1)
%     xdot(i) = (x.data(i+1) - x.data(i))/(x.time(i+1) - x.time(i));
% end
% xdot(length(x.data)) = xdot(length(x.data) - 1);
% for i = 1:(length(x.data) - 1)
%     xddot(i) = (xdot(i+1) - xdot(i))/(x.time(i+1) - x.time(i));
% end
% xddot(length(x.data)) = xddot(length(x.data) - 1);
% m = 0;
% clear xmag xtimemag
% for i = 1:length(x.data)
%     phasex(i) = atan2(-xddot(i),xdot(i));
%     if phasex(i)>0.2
%         m = m+1;
%         xmag(m) = (x.data(i))./phasex(i)';
%         xtimemag(m) = x.time(i);
%     end
% end

% figure(f)
% f = f+1;
% plot(apexvel.time, KE)
% xlabel('t')
% ylabel('KE')
% 
% figure(fi)
% fi = fi+1;
% plot(apexpos.time, PE)
% xlabel('t')
% ylabel('PE')

% figure(fi)
% fi = fi+1;
% plot(PE, KE);
% xlabel('PE')
% ylabel('KE')

% % matching phase
% figure(fi)
% fi = fi+1;
% plot(apexpos.time, phasePE, apexpos.time,(PE-0.7976));
% xlabel('time')
% ylabel('PE and phase')

% figure(fi)
% fi = fi+1;
% plot(xtimemag,  xmag);
% xlabel('time')
% ylabel('PE and phase')

% % PE Mag
% figure(fi)
% fi = fi+1;
% plot(timemag, PEmag);
% xlabel('time')
% ylabel('PEmag')

figure(fi)
fi = fi+1;
plot3(apexpos.time, PEapex, KEapex);
xlabel('t');
ylabel('PE')
zlabel('KE')


figure(fi)
fi = fi+1;
subplot(2,2,1)
plot(PEapex,  PEdot);
xlabel('PE')
ylabel('PEdot')
subplot(2,2,2)
plot(PEdot, PEddot)
xlabel('PEdot')
ylabel('PEddot')
subplot(2,2,3)
plot(KEapex,  KEdot);
xlabel('KE')
ylabel('KEdot')
subplot(2,2,4)
plot(KEdot, KEddot)
xlabel('KEdot')
ylabel('KEddot')

% % Relative phases
% figure(fi)
% fi = fi+1;
% subplot(3,1,1)
% plot(apexpos.time, phasePE);
% xlabel('time')
% ylabel('PE Phase')
% subplot(3,1,2)
% plot(apexpos.time, phaseKE);
% xlabel('time')
% ylabel('KE Phase')
% subplot(3,1,3)
% plot(apexpos.time, phasePEKE);
% xlabel('time')
% ylabel('Relative PE KE Phase')

% % x angle
% figure(fi)
% fi = fi+1;
% plot(x.time, x.data);
% xlabel('time')
% ylabel('x')

% % Curve fitting
% figure(fi)
% fi = fi+1;
% modelFun = @(b,x) (b(1).*exp(b(2).*x)).*sin(b(3).*x + b(4)) + b(5).*exp(b(6).*x) + b(7);
% start = [0.1,-0.1,0.8, 2.3,0.05,0.01,1]; %works  from 10-400
% nlm = fitnlm(apexpos.time,PE,modelFun,start)
% xx = linspace(0,apexpos.time(end), 4*length(apexpos.time))';
% line(xx,predict(nlm,xx),'linestyle','--','color','k')

figure(fi)
fi = fi+1;
subplot(2,1,1)
plot(apexpos.time,PEapex);
xlabel('time')
ylabel('PE')
hold on

% Identify indexes for apex and trunk
for i=1:length(apexpos.time)
    apexperiodindex(i) = find(tout==apexpos.time(i));
end
for i=1:length(ptime)
    trunkperiodindex(i) = find(apexvel.time==ptime(i));
end

% Separate trunk data
theta = pos(:,3);
apextheta = apexpos.data(:,3);
xapexavg = apexposavg.data(:,1);
yapexavg = apexposavg.data(:,2);
thetaapexavg = apexposavg.data(:,3);
dxapexavg = apexvelavg.data(:,1);
dyapexavg = apexvelavg.data(:,2);
dthetaapexavg = apexvelavg.data(:,3);

% % Calculate averages from apex to apex with full data
% for i = 1:(length(apexperiodindex)-1)
%     PEapexavg(i) = mean(PE(apexperiodindex(i):apexperiodindex(i+1)));
%     KEapexavg(i) = mean(KE(apexperiodindex(i):apexperiodindex(i+1)));
%     thetaapexavg(i) = mean(theta(apexperiodindex(i):apexperiodindex(i+1)));
% end
% PEapexavg(length(apexperiodindex)) = PEapexavg(end);
% KEapexavg(length(apexperiodindex)) = KEapexavg(end);
% thetaapexavg(length(apexperiodindex)) = thetaapexavg(end);

% Calculate averages over trunk period with unaveraged and averaged
% quantities
for i = 1:(length(trunkperiodindex)-1)
    PEtrunkavg(i) = mean(PEapexavg(trunkperiodindex(i):trunkperiodindex(i+1)));
    KEtrunkavg(i) = mean(KEapexavg(trunkperiodindex(i):trunkperiodindex(i+1)));
    xtrunkavg(i) = mean(xapexavg(trunkperiodindex(i):trunkperiodindex(i+1)));
    ytrunkavg(i) = mean(yapexavg(trunkperiodindex(i):trunkperiodindex(i+1)));
    thetatrunkavg(i) = mean(thetaapexavg(trunkperiodindex(i):trunkperiodindex(i+1)));
    dxtrunkavg(i) = mean(dxapexavg(trunkperiodindex(i):trunkperiodindex(i+1)));
    dytrunkavg(i) = mean(dyapexavg(trunkperiodindex(i):trunkperiodindex(i+1)));
    dthetatrunkavg(i) = mean(dthetaapexavg(trunkperiodindex(i):trunkperiodindex(i+1)));
end
PEtrunkavg(length(trunkperiodindex)) = PEtrunkavg(end);
KEtrunkavg(length(trunkperiodindex)) = KEtrunkavg(end);
xtrunkavg(length(trunkperiodindex)) = xtrunkavg(end);
ytrunkavg(length(trunkperiodindex)) = ytrunkavg(end);
thetatrunkavg(length(trunkperiodindex)) = thetatrunkavg(end);
dxtrunkavg(length(trunkperiodindex)) = dxtrunkavg(end);
dytrunkavg(length(trunkperiodindex)) = dytrunkavg(end);
dthetatrunkavg(length(trunkperiodindex)) = dthetatrunkavg(end);

plot(ptime,PEtrunkavg)

subplot(2,1,2)
plot(apexvel.time, KEapex)
xlabel('t')
ylabel('KE')
hold on
plot(ptime,KEtrunkavg)

figure(fi)
fi = fi+1;
plot(apexposavg.time, apexposavg.data(:,2),apexposavg.time, apexposavg.data(:,3), ptime, ytrunkavg, ptime, thetatrunkavg);
xlabel('time')
ylabel('positions')
legend('y', 't', 'y avg', 't avg')

figure(fi)
fi = fi+1;
plot(apexvelavg.time, apexvelavg.data(:,1),apexvelavg.time, apexvelavg.data(:,3), ptime, dxtrunkavg,ptime,dthetatrunkavg);
xlabel('time')
ylabel('velocities')
legend('dx','dt', 'dx avg', 'dy avg')

figure(fi)
fi = fi+1;
plot3(ptime, PEtrunkavg, KEtrunkavg);
xlabel('t');
ylabel('PE')
zlabel('KE')

figure(fi)
fi = fi+1;
plot(apexpos.time, apexpos.data(:,3));
xlabel('time')
ylabel('trunk angle')
hold on
plot(ptime,thetatrunkavg)

figure(fi)
fi = fi+1;
plot(apexpos.time, PEapex);
xlabel('time')
ylabel('PE')
hold on
plot(apexpos.time, PEapexavg);
hold on
plot(ptime, PEtrunkavg);
legend('PE at apex', 'PE avg1', 'PE avg2')


for i = 1:(length(ptime) - 1)
    PEavgdot(i) = (PEtrunkavg(i+1) - PEtrunkavg(i))/(ptime(i+1) - ptime(i));
    KEavgdot(i) = (KEtrunkavg(i+1) - KEtrunkavg(i))/(ptime(i+1) - ptime(i));
end
PEavgdot(length(ptime)) = PEavgdot(length(ptime) - 1);
KEavgdot(length(ptime)) = KEavgdot(length(ptime) - 1);

for i = 1:(length(ptime) - 1)
    PEavgddot(i) = (PEavgdot(i+1) - PEavgdot(i))/(ptime(i+1) - ptime(i));
    KEavgddot(i) = (KEavgdot(i+1) - KEavgdot(i))/(ptime(i+1) - ptime(i));
end
PEavgddot(length(ptime)) = PEavgddot(length(ptime) - 1);
KEavgddot(length(ptime)) = KEavgddot(length(ptime) - 1);

figure(fi)
fi = fi+1;
plot(ptime, PEavgdot);
hold on
plot(ptime, PEavgddot);
xlabel('time');
ylabel('PE avg');
legend('PE dot', 'PE ddot');

figure(fi)
fi = fi+1;
plot(ptime, KEavgdot);
hold on
plot(ptime, KEavgddot);
xlabel('time');
ylabel('KE avg');
legend('KE dot', 'KE ddot');

%%

% y0 = ytrunkavg(1);
% t0 = thetatrunkavg(1);
% dx0 = dxtrunkavg(1);
% dy0 = dytrunkavg(1);
% dt0 = dthetatrunkavg(1);
% 
% sim('ASLIPrun2_returnmap')
% 
% % STATE  PLOTS
% figure(fi)
% fi = fi+1;
% plot(tout,pos(:,1),tout,pos(:,2))
% xlabel('t [s]')
% ylabel('Position [m]')
% legend('x', 'y', 'Location', 'Northeast')
% 
% figure(fi)
% fi = fi+1;
% plot(tout,vel(:,1),tout,vel(:,2))
% xlabel('t [s]')
% ylabel('Velocity [m/s]')
% legend('dx', 'dy', 'Location', 'Northeast')