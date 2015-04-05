//conm
//Algorithm for binary addition discovered
//by Vaibhav Jain
//13/02/04 (c) Vaibhav
#include <stdio.h>
#include <conio.h>
void main()
{unsigned long a=10000l,b=2032l;
 unsigned long xor,carry;
 xor=a^b;carry=a&b;
 while(carry<<=1)
 {unsigned long a,b;
  a=xor,b=carry;
  xor=a^b;
  carry=a&b;
 }
printf("\nthe addition of %ld,%ld=%ld",a,b,xor);
getch();
}