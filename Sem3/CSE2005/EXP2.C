#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
int i;
if(fork() == 0)
{
for(i=1;i<50;i++)
if(i%2 == 0)
printf("even %d\n",i);
}
else
{
for(i=1;i<50;i++)
if(i%2 != 0)
printf("odd %d\n",i);
}
}
