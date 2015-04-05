//conm
//least square curve fitting method
//fits a linear polynomial to a given set of data
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
float sumx[7]={0},sumy[3]={0};
float matrix[3][4];
int degree=0;
void GaussElemination(int cvars)
{ int rows=cvars,cols=cvars+1;
for(int i=0;i<rows;i++)
{ if(matrix[i][i]==0) exit(1);
  for(int j=cols-1;j>=0;j--)
	matrix[i][j]/=matrix[i][i]; //divide each element in row by first element
  for(j=i+1;j<rows;j++)//iterate through next rows
    for(int k=cols-1;k>=i;k--)//iterate through each element in this row
      matrix[j][k]-=matrix[i][k]*matrix[j][i];//subtract this element with
}
for(i=rows-1;i>=0;i--) // iterate through each row backward
{float sum=0;	       //intialize subtractant to zero
 for(int j=i+1;j<cols-1;j++)// iterate through each non unity element
    sum+= matrix[i][j]*matrix[j][cols-1];// add to subtractend product of
 matrix[i][cols-1]-=sum; // subtract subtractend from the current augument element
}
}

void main()
{ printf("**************Curve Fitting Method**************\n");
  printf("\nEnter Degree of curve to fit: ");
  scanf("%d",&degree);
  printf("\nNow Enter the data set:\n");
 float x,y;char buffer[20];
 do
 {fflush(stdin);
  printf("Enter Pair as x<space>y: ");
  scanf("%[0-9e. -]s",buffer);
  sscanf(buffer,"%f %f",&x,&y);
  if(!*buffer) continue;
  float xp=1;
  for(int i=0;i<=2*degree;i++) // calculating the cooficient terms
  {sumx[i]+=xp;
   if(i<=degree) sumy[i]+=y*xp;
   xp*=x;
  }
 }while(*buffer);
for(int i=0;i<=degree;i++)  // forming the system matrix
{  for(int j=0;j<=degree;j++)
   matrix[i][j]=sumx[i+j];
   matrix[i][j]=sumy[i];
}
//solving the matrix using gaussian elemination
GaussElemination(degree+1);
printf("\nSolutions:->| ");
for(i=0;i<=degree;i++)
printf("%.2f | ",matrix[i][degree+1]);
getch();
}