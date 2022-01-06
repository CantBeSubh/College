mdl_puma560
p560.teach()
l(1)=Link([0,0,0,pi/2,0]);
l(2)=Link([0,0,0.3,0,0]);
l(3)=Link([0,0,0.24,0,0]);
l(4)=Link([0,0,0.18,0,0]);
puma=SerialLink(l);
puma.plot([0,0,0,0,0,0]);