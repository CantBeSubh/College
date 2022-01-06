syms n;
n=input('Number of links: ');
for i=1:n
    fprintf('Link %d',i);
    l(i)=input(' ');
end
for j=1:n
    fprintf('Angle %d',j);
    t(i)=input(' ');
end
rz1=[cosd(t(1)) -sind(t(1)) 0 0;sind(t(1)) cosd(t(1)) 0 0;0 0 1 0; 0 0 0 1];
tx1=[1 0 0 l(1);0 1 0 0 ;0 0 1 0;0 0 0 1];
rz2=[cosd(t(2)) -sind(t(2)) 0 0;sind(t(2)) cosd(t(2)) 0 0;0 0 1 0; 0 0 0 1];
tx2=[1 0 0 l(2); 0 1 0 0 ;0 0 1 0;0 0 0 1];
rz3=[cosd(t(3)) -sind(t(3)) 0 0;sind(t(3)) cosd(t(3)) 0 0;0 0 1 0; 0 0 0 1];
tx3=[1 0 0 l(3); 0 1 0 0 ;0 0 1 0;0 0 0 1];

h1=rz1*tx1;
h2=rz2*tx2;
h3=rz3*tx3;

ee=h1*h2*h3;

disp(ee);
