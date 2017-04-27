function cost = sim_rocket_opt_cost(x)

for i = 1:20
    costVec(i) = 1/(sim_rocket_opt(x)+0.00001);
end

cost = mean(costVec)

end