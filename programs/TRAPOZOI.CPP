//conm
//integration of a tabluted function using
//trapozoidal rule
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
float points[10][2],result=0;
int count=0;
void main()
{ float x,y;char buffer[20];
  printf("\n**************Trapoziodal Rule**************\n");
  printf("\nNow Enter the Data Table:\n");
  do{fflush(stdin);
  printf("Enter Pair as x<space>y: ");
  scanf("%[0-9e. -]s",buffer);
  sscanf(buffer,"%f %f",&x,&y);
  if(!*buffer) continue;
  points[count][0]=x;
  points[count++][1]=y;
  }while(*buffer);
  for(int i=0;i<(count-1);i++)
	result+=1.0/2*(points[i+1][0]-points[i][0])*
	(points[i][1]+points[i+1][1]);
printf("\nIntegration Result:->%f",result);
getch();
}