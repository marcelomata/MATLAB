function dq = hw8_3func(t,q)
dq = zeros(4,1);

dq(1) = q(3);
dq(2) = q(4);                                                                                                                                                                                                                                                                                                                                                                                                                          
dq(3) = q(2)/2 - (3*q(1))/2 - (q(1) - q(2))^3/5;
dq(4) = (q(1) - q(2))^3/5 - q(2)/2 - (7*q(1))/2 + ((469*q(1))/50 - (223*q(2))/50 - (42*q(3))/5 + (223*(q(1) - q(2))^3)/125 - ((3*(q(1) - q(2))^2)/5 + 3/2)*((3*q(1))/2 - q(2)/2 + (q(1) - q(2))^3/5) + ((3*(q(1) - q(2))^2)/5 + 1/2)*((7*q(1))/2 + q(2)/2 - (q(1) - q(2))^3/5) - (21*q(4)*((3*(q(1) - q(2))^2)/5 + 1/2))/5 + (21*q(3)*((3*(q(1) - q(2))^2)/5 + 3/2))/5 + q(3)*(q(3)*((6*q(1))/5 - (6*q(2))/5) - q(4)*((6*q(1))/5 - (6*q(2))/5)) - q(4)*(q(3)*((6*q(1))/5 - (6*q(2))/5) - q(4)*((6*q(1))/5 - (6*q(2))/5)))/((3*(q(1) - q(2))^2)/5 + 1/2);