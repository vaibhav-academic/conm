//binary Multiplication  of two integers
// with out using Multiplication operator
#include <stdio.h>
#include <conio.h>
unsigned overflow=0;
unsigned long add(unsigned long A,unsigned long B)
{unsigned long carry=0,sum=0,a,b;

 unsigned long mask=1;
//do the loop 16 times;
while(mask)
 {  carry<<=1;
    a=A&mask;b=B&mask;
    sum=(a^b^carry);
    B&=~mask;
    B|=sum;
    carry= (a&b&~carry)|(a&carry&~b)|
	   (b&carry&~a)|(a&b&carry);
 mask<<=1;
 }
overflow=!!carry;
return B;
}
unsigned long multiply(unsigned A,unsigned B)
{unsigned long mask=1;
 unsigned long result=0,oper=B;
 while(mask)
 { ~(A&mask)|(A&MASK);
  result=add(result,oper);
  oper<<=1;
  mask<<=1;
 }
return 0l;
}
void main()
{unsigned A=2,B=3;
unsigned long C;
//C=multiply(A,B);
printf("\n%ld",c);
if(overflow) puts("  With Overflow");
getch();
}
