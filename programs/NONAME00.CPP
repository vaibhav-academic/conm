//conm
//Solving a Linear Equation using
//Gauss Elemination Method
#include <conio.h>
#include <stdio.h>
float matrix[4][5];
int rows=0,cols=0;
int partialpivot(int row)// perform pivot on row with a non zero row
{  for(int i=row;i<rows;i++)
    if(matrix[i][row]!=0) break;
  if(i>=rows) return 0; // pivot not possible
  for(int j=row;j<cols;j++)
  {float temp=matrix[row][j];
   matrix[row][j]=matrix[i][j];
   matrix[i][j]=temp;
  }
 return 1;
}

void main()
{ int cvars=0;
  clrscr();
  printf("*********************Gauss Elemination Method*****************\n");
  printf("\nEnter Number of variables: ");
  scanf("%d",&cvars);
  printf("\nNow Enter the Augment Matrix:");
  for(int i=0;i<cvars;i++)
   {printf("\nEnter Row[%d]->",i);
   for(int j=0;j<cvars+1;j++)
   scanf("%f",&matrix[i][j]);
   }
  rows=cvars,cols=cvars+1;
  printf("\nMatrix::");
   for(i=0;i<rows;i++)
   {printf("\n");
     for(int j=0;j<cols;j++)
      printf("%.2f | ",matrix[i][j]);
   }

for(i=0;i<rows;i++)
{ if(matrix[i][i]==0 && partialpivot(i)==0)
   {// the first element is zero and pivoting is also not possible
    printf("\nThe System in Inconsistent or reductant");
    getch();
    return;
   }
  for(int j=cols-1;j>=0;j--)
	matrix[i][j]/=matrix[i][i]; //divide each element in row by first element
  for(j=i+1;j<rows;j++)//iterate through next rows
    for(int k=cols-1;k>=i;k--)//iterate through each element in this row
      matrix[j][k]-=matrix[i][k]*matrix[j][i];//subtract this element with
					      //product of rows first element
					      //by pivoting rows corrosponding
					      //element
}
//upper trangulization is complete now perform back substitution
for(i=rows-1;i>=0;i--) // iterate through each row backward
{float sum=0;	       //intialize subtractant to zero
 for(int j=i+1;j<cols-1;j++)// iterate through each non unity element
    sum+= matrix[i][j]*matrix[j][cols-1];// add to subtractend product of
					// of the element & its corrosponding
					//augument matrix element;
 matrix[i][cols-1]-=sum; // subtract subtractend from the current augument element
}
printf("\n\nMatrix::");
 for(i=0;i<rows;i++)
 {printf("\n");
     for(int j=0;j<cols;j++)
      printf("%.2f | ",matrix[i][j]);
}
getch();
}
