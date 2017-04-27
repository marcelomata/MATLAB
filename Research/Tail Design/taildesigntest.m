clear all
clc

mb = 6;
It = 0; % moment of inertia of the tail about its own COM?
Ib = 0.1;

[x,eval] = fmincon(@(x)taildesignfunc(x,mb, It, Ib), [0.5,0.2,0],[],[],[],[],[0 0 0], [50,1,50])

mt = x(1);
mr = mb*mt/(mb+mt);
lt = x(2);
lb = x(3);

Ineff = (It + mr*lt^2)/(It+Ib+mr*(lt^2+lb^2))