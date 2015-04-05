// root of a equation with secant method;
//06/02/2004 (c) Vaibhav Jain
#include <math.h>
#include <stdio.h>
#include <conio.h>
#define SIGN(x) ((x<0.0)?-1:1)
#define APPROX 0.0000001
double fx(double x) {return (x*x-4*x+4);}

int main()
{double x1=5,x2,y1,y2,x,y=APPROX;
 unsigned iterations=0;
 y1=fx(x1);x2=x1-1;y2=fx(x2);clrscr();
 clrscr();
 while(fabs(y)>=APPROX)
	{x=x1-y1/(y1-y2)*(x1-x2);
	 y=fx(x);
	 x2=x1,y2=y1;
	 x1=x,y1=y;
	 iterations++;
	 printf("Iteration%d: x=%f\n",iterations,x);
	}
printf("\nThe Root of the Equation is :\
	%f\nTotal Iterations=%u",x,iterations);
getch();
return 0;
}