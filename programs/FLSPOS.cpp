// root of a equation with false position method;
#include <math.h>
#include <stdio.h>
#include <conio.h>
#define SIGN(x) ((x<0.0)?-1:1)
#define APPROX 0.00003
double fx(double x)
{return x*x-25;}

int main()
{double x1=7,y1,x2=4,y2;
 double x,y;
 unsigned iterations=0;
 y1=fx(x1);
 y2=fx(x2);
 clrscr();
 if(SIGN(y2)==SIGN(y1))
	{fprintf(stderr,"\n!!Error:Invalid Domain Provided");
	return 1;}

 while(fabs(y1)>APPROX)
	{x=-y1*(x2-x1)/(y2-y1)+x1;
	 y1=fx(x);
	 x1=x;
	 iterations++;
	 printf("\nIteration %d: y=%f",iterations,x);
	}
printf("\nThe Root of the Equation is :%f\nTotal Iterations=%u"
	,x,iterations);
getch();
return 0;
}
