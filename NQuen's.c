//12. Implement N Queen's problem using Back Tracking.
#include<stdio.h>
#include<stdlib.h>

void print_solution(int n,int x[])
{
	char c[10][10];
	int i,j;
	// No Queens has placed initially
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			c[i][j]='x';

		}
	}
	// Place the Queens on the chess board
	for(i=1;i<=n;i++)
	{
		c[i][x[i]]='q';
	}
	// Print where the queens have been placed on chess board
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%c",c[i][j]);
		}
		printf("\n");
	}
}

int place(int x[],int k)
{
	int i;
	for(i=1;i<k;i++)
	{
		//Check whether two Queens attack vertically or diagnolly
		if(x[i]==x[k]||i-x[i]==k-x[k]||i+x[i]==k+x[k])
		{
			return 0;	//Queen cannot be placed in the Kth column
		}
	}
	return 1;		//Kth Queen can be placed
}

void nqueens(int n)
{
	int x[10];				// Initial Solution vector
	int count=0;			//Number of solutions
	int k=1;				//Select the first Queen
	x[k]=0;				//But not placed in the chessboard
	while(k!=0)				//A Queen exists?
	{
		x[k]+=1;			//Place Queen in the next column

		//Satisfy both Explicit and Implicit conditions
		while((x[k]<=n)&&(!place(x,k)))
		{
			x[k]+=1;		//Place Queen in the next column
		}
		if(x[k]<=n)			//if Queen Successfully Placed?
		{
			if(k==n)		//if all Queens are placed
			{
				count++;
				printf("solution %d is\n",count);
				print_solution(n,x);
			}
			else
			{
				k++;		//Select the next Queen
				x[k]=0;	//but do not place
			}
		}
		else
		{
			k--;			//Backtrak and select previous Queen
		}
	}
	return;
}

int main()
{
	int n;

	printf("enter the no of queens\n");
	scanf("%d",&n);
	nqueens(n);
	
	return 0;
}

