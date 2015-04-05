//conm
//Diffrence table interpolation method
//10/02/04 (c) Vaibhav Jain
#include <stdio.h>
#include <conio.h>
float x[10];
float fx[10];
int count=0;
float num,result=0;
float adder;
void main()
{int i=0,j;char buffer[20];
 clrscr();
 do
 {printf("Enter Pair as x<space>f(x): ");
  scanf("%[0-9e. -]s",buffer);
  fflush(stdin);
  sscanf(buffer,"%f %f",&x[i],&fx[i]);
  i++;
 }while(*buffer &&i<10);
count=i-1;

printf("\n\nEnter the value to be interpolated: ");
scanf("%f",&num);

for(i=0;i<count;i++)
{adder=fx[0];
 for(j=0;j<i;j++)
 adder*=(num-x[j]);
 result+=adder;
 for(j=0;j<(count-1)-i;j++)
 fx[j]=(fx[j+1]-fx[j])/(float)(x[j+i+1]-x[j]);
}
printf("\nInterpolation result for %f = %f",num,result);
getch();
}