//conm
//Solving a Linear Equation using
//Gauss Seidal Iterative Method
#include <conio.h>
#include <stdio.h>
float matrix[3][4];
int rows=0,cols=0;
int maxiterations;
void main()
{ int cvars=0;
  clrscr();
  printf("****Gauss Seidal Iterative Method****\n");
  printf("\nEnter Number of variables: ");
  scanf("%d",&cvars);
  printf("\nNow Enter the Augment Matrix:");
  for(int i=0;i<cvars;i++)
   {printf("\nEnter Row[%d]->",i);
   for(int j=0;j<cvars+1;j++)
   scanf("%f",&matrix[i][j]);
   }
  rows=cvars,cols=cvars+1;
  printf("\nMax Number of Iterations: ");
  scanf("%d",&maxiterations);
  printf("\nMatrix::");
   for(i=0;i<rows;i++)
   {printf("\n");
     for(int j=0;j<cols;j++)
      printf("%.2f | ",matrix[i][j]);
   }
//check if any cooficient is zero
for(i=0;i<rows;i++)
if(matrix[i][i]==0)
	{for(int j=0;j<rows;j++)
	     if(matrix[j][i]!=0 && matrix[i][j]!=0) break;
	 if(j>=rows)
	   {printf("Invalid Matrix:one or more Cooficients are zero");
	    return;}
	 //perform rows interchange
	 for(int k=0;k<cols;k++)
	 {float temp=matrix[i][k];
	  matrix[i][k]=matrix[j][k];
	  matrix[j][k]=temp;
	 }
	}
for(i=0;i<rows;i++)  //make coffienent of one variabe in each
   { for(int j=0,coff=matrix[i][i];j<cols;j++)	//each equation =1
	 matrix[i][j]/=coff;
     matrix[i][i]=0;
    }
//the initial guess of each variable =0
//now lets roll!!!
  while(maxiterations-->0)
  { for(int i=0;i<rows;i++)
     {float sum=0;
      matrix[i][i]=0; // let the new value intially be zero
      for(int j=0;j<cols-1;j++)
       sum+= matrix[i][j]*matrix[j][j];// multiply each coffiecent with its varible
       matrix[i][i]=matrix[i][cols-1]-sum;//new value= constant-(vars*coffs);
    }
  printf("\n\n%d:Solutions:-> |",maxiterations);
  for(int k=0;k<rows;k++)
    printf("%.3f | ",matrix[k][k]);
  getch();
 }
printf("\n\nSolutions:-> |");
 for(i=0;i<rows;i++)
    printf("%.3f | ",matrix[i][i]);
getch();
}
