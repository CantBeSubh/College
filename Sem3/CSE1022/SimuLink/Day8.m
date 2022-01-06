clear all
clc
syms l1 l2 t1 t2 x y alph;

l1 = input('Enter link 1: ');
l2 = input('Enter link 2: ');
x = input('Enter x: ');
y = input('Enter y: ');


t2 = acos(x^2 + y^2 - l1^2 - l2^2/2*l1*l2);

c2 = cos(t2);
s2 = sin(t2);

alph = atan(l1 + l2*c2/l2*s2);

t1 = alph - atan(x/y);
t1
t2
alph