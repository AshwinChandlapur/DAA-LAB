//Warshall's Algorithm
#include<stdio.h>

int a[10][10],n;
void warshal()
{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				
				
					if(a[i][k]==1&&a[k][j]==1)
					{
						a[i][j]=1;
					}
			       
			}
		}
	}
}
void main()
{

	int i,j;

	printf("enter the no. of nodes\n");
	scanf("%d",&n);
	printf("enter the matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	warshal();
	printf("the transitive closure of the matrix is\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d",a[i][j]);
			printf("\t");
		}
		printf("\n");
	}

}

