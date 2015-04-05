//conm
//forward interpolation using newton gregory method
//12/02/04 (c) Vaibhav Jain

#include <stdio.h>
#include <conio.h>

float fx[10],diff,start;
unsigned int count=0;
float num,result;

void main()
{int i,j,fac;
 clrscr();
 printf("Enter Number of observations:\t");
 scanf("%u",&count);
 printf("Enter Common Diffrence:\t\t");
 scanf("%f",&diff);
 printf("Enter First Term:\t\t");
 scanf("%f",&start);
 for(printf("\n\n"),i=0;i<count;i++)
	{printf("Enter f(%f) -->",start+diff*i);
	  scanf("%f",fx+i);
	 }
 printf("\n\nEnter interpolation value:\t");
 scanf("%f",&num);

num-=start;
num/=diff;
for(result=0,fac=1,i=0;i<count;fac*=++i)
{float adder=fx[0];
 for(j=0;j<i;j++) adder*=(num-j);
 result+=adder/(float)fac;

 for(j=0;j<(count-1)-i;j++)
   fx[j]=(fx[j+1]-fx[j]);
}

printf("\nInterpolation result for %f = %f",num,result);
getch();
}