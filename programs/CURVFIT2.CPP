//conm
//least square curve fitting method
//fits a exponential function of form y=ae^(-bx)
//to a given set of data
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
float sumx[3]={0},sumy[2]={0};
float matrix[2][3];

void GaussElemination(float **,int cvars)
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
{ printf("\n***Exponential Curve Fitting Method***\n");
  printf("\nEnter the data set:\n");
 float x,y;char buffer[20];
 do
 {fflush(stdin);
  printf("Enter Pair as x<space>y: ");
  scanf("%[0-9e. -]s",buffer);
  sscanf(buffer,"%f %f",&x,&y);
  if(!*buffer) continue;
  y=log(y);
  sumx[0]++;	//increment counter
  sumx[1]+=x;	//increment sum(x)
  sumx[2]+=x*x;	//increment sum(x^2)
  sumy[0]+=y;	//increment sum(y)
  sumy[1]+=x*y;	//increment sum(xy)
  }while(*buffer);
// forming the system matrix
matrix[0][0]=sumx[0]; //count
matrix[0][1]=sumx[1]; //sum(x)
matrix[0][2]=sumy[0]; //sum(y)

matrix[1][0]=sumx[1]; //Sum(x)
matrix[1][1]=sumx[2]; //sum(x^2)
matrix[1][2]=sumy[1]; //sum(x*y)



//solving the matrix using gaussian elemination
GaussElemination((float**)matrix,2);
printf("\nSolutions:-> ");
printf("a=%.2f , ",exp(matrix[0][2]));
printf("b=%.2f  ",-matrix[1][2]);
getch();
}