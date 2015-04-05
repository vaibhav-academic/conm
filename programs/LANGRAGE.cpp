//interpolation using lagrange`s method
#include <stdio.h>
#include <conio.h>
float x[10];
float fx[10];
int count=0;
float num,result;
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


for(result=i=0;i<count;i++)
{adder=fx[i];
 for(j=0;j<count;j++)
  if(j!=i)
	adder*=(num-x[j])/(x[i]-x[j]);
 result+=adder;
}
printf("\n Interpolation result for %f = %f",num,result);
getch();
}