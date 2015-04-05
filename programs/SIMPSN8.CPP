//conm
//integration of a tabluted function using
//simpson's 3/8 rule
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
float points[10][2],result=0;
int count=0;
void main()
{ float x,y;char buffer[20];
  printf("\n****Simpson's 3/8 Rule****\n");
  printf("\nNow Enter the Data Table:\n");
  do{fflush(stdin);
  printf("Enter Pair as x<space>y: ");
  scanf("%[0-9e. -]s",buffer);
  sscanf(buffer,"%f %f",&x,&y);
  if(!*buffer) continue;
  points[count][0]=x;
  points[count++][1]=y;
  }while(*buffer || count<2);
  int i=0;
  //simpsons 3/8 rule can only be applied to 4 closed points
  //extra points are evaluated with trapoziod rule
  int extras=count%4;
  for(i=0;i<extras;i++)
  result+=1.0/2*(points[i+1][0]-points[i][0])*
	  (points[i+1][1]+points[i][1]);

  for(;i<(count-1);i+=3)
     {  result+=1.0*3/8*(points[i+1][0]-points[i][0])*
	(points[i][1]+3*points[i+1][1]+3*points[i+2][1]
	+points[i+3][1]);
     }
 //applying simpsons 3/8 rule
printf("\nIntegration Result:->%f",result);
getch();
}