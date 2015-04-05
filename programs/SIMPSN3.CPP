//conm
//integration of a tabluted function using
//simpson's 1/3 rule
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
float points[10][2],result=0;
int count=0;
void main()
{ float x,y;char buffer[20];
  printf("\n****Simpson's 1/3 Rule****\n");
  printf("\nNow Enter the Data Table:\n");
  do{fflush(stdin);
  printf("Enter Pair as x<space>y: ");
  scanf("%[0-9e. -]s",buffer);
  sscanf(buffer,"%f %f",&x,&y);
  if(!*buffer) continue;
  points[count][0]=x;
  points[count++][1]=y;
  }while(*buffer);
  int i=0;
  if(count%2==0)//total points are even solve first point with trapoziodal
  result= 1.0/2*(points[i+1][0]-points[i][0])/
	  (points[i+1][1]+points[i][1]);
  for(;i<(count-1);i+=2)
     {  result+=1.0/3*(points[i+1][0]-points[i][0])*
	(points[i][1]+4*points[i+1][1]+points[i+2][1]);
     }
 //applying simpsons 1/3 rule
printf("\nIntegration Result:->%f",result);
getch();
}