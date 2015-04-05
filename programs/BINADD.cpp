//conm
//binary addition/subtraction of two integers
//with out using addition operator
//08/02/2004 (c) Vaibhav Jain
#include <stdio.h>
#include <conio.h>
void main()
{unsigned a=7,b=2,c=0;
 unsigned char carry=0,sum=0;
 unsigned count;
//do the loop 16 times;
for(count=~0;count;count>>=1)
 {  sum=((a&1)^(b&1)^carry);
    c|=sum<<(sizeof(int)*8-1);
    carry= (a&carry&&!(b&1))||(b&carry&&!(a&1))||
	   ((a&b&1)&&!(carry))||((a&b&1) &&carry);
    if(count==1) continue;
    a>>=1;b>>=1;c>>=1;
 }
printf("\nThe Sum is %d",c);
if(carry)printf(" With Overflow");
getch();
}