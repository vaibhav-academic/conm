//solving ordinary diffrential equations
//using Runge-Kutta 2nd Order Formule
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
 {float s1=fx(x,y);
  float s2=fx(x+step/2,y+s1*step/2);
  float s3=fx(x+step/2,y+s2*step/2);
  float s4=fx(x+step,y+s3*step);
  y=y+step*(s1+2*s2+2*s3+s4)/6;
  x+=step;
  printf("\nF(%f)=%f",x,y);
  getch();
 }
printf("\nY(%f)=%f",x,y);
getch();
}
