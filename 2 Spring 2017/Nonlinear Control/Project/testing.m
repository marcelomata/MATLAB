consts = get_consts() ;
m = 175;
z = linspace(0,1500,1501);
wind = 10;
for i = 1:length(z)
    
    if(z(i) > 2*consts.L)
        d(i) = wind/m*exp(-1./(z(i)-2*consts.L)) ;
    else
        d(i) = 0 ;
    end
    
end

plot(z,d)