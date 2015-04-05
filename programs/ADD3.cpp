//conm
//Algorithm for binary addition discovered
// by Vaibhav Jain
//13/02/04 (c) Vaibhav
#include <stdio.h>
#include <conio.h>
long unsigned add(long unsigned a,unsigned long b)
{return b?add(a^b,(a&b)<<1):a;}

void main()
{unsigned long a=-10000l;
 unsigned long b=2032l;
printf("\n%ld+%ld=%ld",a,b,add(a,b));
getch();
}