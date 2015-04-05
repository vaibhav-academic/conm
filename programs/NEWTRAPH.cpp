//CONM
// root of a equation with newton raphalson method;
//06/02/03 (c) Vaibhav Jain
#include <math.h>
#include <stdio.h>
#include <conio.h>
#define SIGN(x) ((x<0.0)?-1:1)
#define APPROX 0.00003
double fx(double x)
{return (x*x-4*x+4);}
double dfx(double x)
{return (2*x-4);}

int main()
{double x=10,y,dy;
 unsigned iterations=0;
 clrscr();
 y=fx(x);
 dy=dfx(x);
 while(fabs(y)>APPROX)
	{x=x-y/dy;
	 y=fx(x);
	 dy=dfx(x);
	 iterations++;
	 printf("Iteration%d: x=%f\n",iterations,x);
	}
printf("\nThe Root of the Equation is :%f\nTotal Iterations=%u"
	,x,iterations);
getch();
return 0;
}
