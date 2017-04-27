function cost = taildesignfunc(x,mb, It, Ib)

mt = x(1);
mr = mb*mt/(mb+mt);
lt = x(2);
lb = x(3);

Ineff = (It + mr*lt^2)/(It+Ib+mr*(lt^2+lb^2));

cost = 1/Ineff^2 + 5*mt^2 + 2*lt^2;

end