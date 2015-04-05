//interpolation using piece wise fit method
//12/02/04 (c) Vaibhav Jain
#include <stdio.h>
#include <conio.h>

float x[10],fx[10];
float num,result=0;
void main()
{int i,min,max,count;
 char buffer[20];
 clrscr();

 for(count=max=min=0;*buffer&&count<10;count++)
 {printf("Enter Pair as x<space>f(x): ");
  scanf("%[0-9e. -]s",buffer);
  fflush(stdin);
  sscanf(buffer,"%f %f",&x[count],&fx[count]);
  if(x[count]>x[max]&&*buffer)max=count;
  if(x[count]<x[min]&&*buffer)min=count;
 }
count--;

printf("\n\nEnter the value to be interpolated: ");
scanf("%f",&num);

for(i=0;i<count;i++)
{ if(x[i]<=num && x[i]>x[min]) min=i;
  if(x[i]>num &&x[i]<x[max]) max=i;
}

result=fx[max]*(num-x[min])-fx[min]*(num-x[max]);
result/=(x[max]-x[min]);

printf("\nInterpolation result for %f = %f",num,result);
getch();
}