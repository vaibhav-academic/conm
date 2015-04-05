//conm
// root of a equation x*x-9
//with bisection method;
#include <math.h>
#include <stdio.h>
#include <conio.h>
#define SIGN(x) ((x<0.0)?-1:1)
#define APPROX 0.00001
double fx(double x)
{return (x*x-9);}


int getpointwithsign(int sign)
{int i=0;
for(i=0;i<=1000;i++)
 {if(SIGN(fx(i))==sign) return i;
  if(SIGN(fx(-i))==sign) return -i;
 }
return 0;
}

int main()
{double hi=0,lo,fhi,x,y;
 unsigned iterations=0;
 clrscr();
 hi=0,fhi=fx(0.0);
 lo=getpointwithsign(SIGN(fhi)*-1);
 if(lo==0) {puts("\nInvalid Function");return 1;}
 while(SIGN(hi-lo)*(hi-lo)>APPROX)
	{x=(hi+lo)/2;
	 y=fx(x);
	 if(y==0.0) break;
	 else
	 if(SIGN(y)==SIGN(fhi)) hi=x,fhi=y;
	 else lo=x;
	 iterations++;
	 printf("\nIteration %d: y=%f",iterations,x);
	}
printf("\nThe Root of the Equation is :%f\nTotal Iterations=%u",x,iterations);
getch();
return 0;
}
