//conm
//solving ordinary diffrential equations
//using Eulers Method of form dy/dx=f(x,y)
#include <conio.h>
#include <stdio.h>
float initx=0,inity=1;//boundary conditions
float tx,step;
//gives the value of f(x,y)
float fx(float x,float y) {return x*x+y*y;}
void main()
{printf("\nEnter Target X: ");//destination x
 scanf("%f",&tx);
 printf("Step Size?:");scanf("%f",&step);
 float x=initx,y=inity;
 //calculate no. of steps required
 long steps=(tx-initx)/step+1;
 while(steps--)
 {y=y+step*fx(x,y);//apply eulers formulae
  x+=step;
  printf("\nF(%f)=%f",x,y);
  getch();
 }
printf("\nY(%f)=%f",x,y);
getch();
}
