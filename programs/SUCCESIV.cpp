// root of a equation with succesive approximation method;
#include <math.h>
#include <stdio.h>
#include <conio.h>
#define SIGN(x) ((x<0.0)?-1:1)
#define APPROX 0.02
double fx(double x)
{return (x*x+4)/4;}

int main()
{double x=0;
 unsigned maxiteration=500;
for(clrscr();maxiteration--;x=fx(x));
printf("\nThe Root of the Equation converged to :%f",x);
getch();
return 0;
}