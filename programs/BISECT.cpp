//root of a equation x^3-2x^2-x=0
//usigng the bisection method;
#include <math.h>
#include <stdio.h>
#include <conio.h>
#define SIGN(x) ((x<0.0)?-1:1)
#define APPROX 0.003
double fx(double x)
{return (x*x*x-2*x*x-x);}

int main()
{double hi=100,lo=-10;
 double fhi,x,y;
 unsigned iterations=0;
 fhi=fx(hi);
 if(SIGN(fhi)==SIGN(fx(lo)))
	{fprintf(stderr,"\n!!Error:Invalid Domain Provided");
	return 1;}

 while(SIGN(hi-lo)*(hi-lo)>APPROX)
	{x=(hi+lo)/2;
	 y=fx(x);
	 if(y==0.0) break;
	 else
	 if(SIGN(y)==SIGN(fhi)) hi=x,fhi=y;
	 else lo=x;
	 iterations++;
	}
printf("\nThe Root of the Equation is :%f\nTotal Iterations=%u"
	,x,iterations);
getch();
return 0;
}
