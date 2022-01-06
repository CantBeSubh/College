clc
clear all
%2L :
syms x;
l1=10;
l2=20;
l3=30;
w2l=l1*l2*sin(x);
max=0;
max_value=0;
for a=0:8
    val=a*pi/2;
    temp=subs(w2l,val);
    if temp>max
        max=temp;
        max_value=rad2deg(val);
    end
end
max
max_value


thetha3= rad2deg(acos((sqrt((l2^2 + l3^2)^2)-(l2^2+l3^2))/6*l2*l3))

wPUMA=l2*l3*sqrt(l2^2 + l3^2 + 2*l2*l3*cos(thetha3))*abs(sin(thetha3))

max=0
max_value=0

wSCARA=l1*l2*sin(x)
for a=0:8
    val=a*pi/2;
    temp=subs(wSCARA,val);
    if temp>max
        max=temp;
        max_value=rad2deg(val);
    end
end
max
max_value