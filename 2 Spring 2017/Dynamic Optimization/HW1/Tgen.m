function T = Tgen(x,link_length)

cr = cos(x(1));
sr = sin(x(1));
cp = cos(x(2));
sp = sin(x(2));
cy = cos(x(3));
sy = sin(x(3));

Rx = [1 0 0;0 cr sr;0 -sr cr];
Ry = [cp 0 sp;0 1 0;-sp 0 cp];
Rz = [cy -sy 0;sy cy 0;0 0 1];
T = zeros(4,4);
T(1:3,1:3) = Rx*Ry*Rz;
T(1,4) = link_length;
T(4,4) = 1;

end