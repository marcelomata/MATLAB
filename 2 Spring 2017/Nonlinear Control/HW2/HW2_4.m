%% HW 2_4
tic
close all
clear
clc

set(0, 'DefaultAxesFontSize', 14);
set(0,'DefaultAxesXGrid','on','DefaultAxesYGrid','on')
set(0,'DefaultLineMarkerSize',3)


N = 100000; % number of transformations
x0 = [0;0];
figure()
plot(x0(1),x0(2), 'r.');
hold on

ifs = [0 0.2625 -0.3941 0 8.0172 243.2220 0.1905
0.1816 0 0 0.1719 68.5607 8.2813 0.0575
0.1805 0 0 0.1625 69.2141 200.2813 0.0540
0 0.2094 -0.3904 0 205.5478 241.0286 0.1506
0 0.2011 -0.3879 0 323.8162 239.5663 0.1436
0.0576 0 0.0756 0.2438 289.9241 135.4628 0.0259
0.0598 0.0028 -0.0719 0.2531 255.1894 175.6563 0.0282
0.2281 0 0 0.1875 418.4187 8.8438 0.0788
0 0.2374 -0.3148 0 402.2686 239.5539 0.1376
0 -0.2262 0.3197 0 570.6928 50.6466 0.1332]; % matrix of transformation parameters

fcolorvec = [0,0,0
    0,1,0
    0,0,1
    1,1,0
    1,0,1
    0,1,1
    1,0.5,0
    1,0,0.5
    0.5,1,0
    0,1,0.5]; % matrix of color combinations

% generate frequency bins
newbin = 0;
bins = [0];
for i = 1:length(ifs(:,1))
    newbin = newbin + ifs(i,7);
    bins = [bins;newbin];
end

xold = x0;
for i = 1:N
    p = rand;
    for j = 1:length(ifs(:,1))
        if p >= bins(j) && p<= bins(j+1)
            M = [ifs(j,1), ifs(j,2);ifs(j,3), ifs(j,4)];
            c = [ifs(j,5);ifs(j,6)];
            fcolor = fcolorvec(j,:);
        elseif p>=bins(end)
            M = [ifs(10,1), ifs(10,2);ifs(10,3), ifs(10,4)];
            c = [ifs(10,5);ifs(10,6)];
            fcolor = fcolorvec(10,:);
        end
    end
    
    xnew = M*xold + c; % apply transformation
    plot(xnew(1),xnew(2), '.', 'color',fcolor)
    xold = xnew;
end
axis equal
xlabel('x1')
ylabel('x2')
title('Figure 4. IFS Output')
toc