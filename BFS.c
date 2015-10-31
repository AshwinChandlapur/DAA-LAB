//Print all the nodes reachable from a given starting node in a digraph using BFS method.

#include<stdio.h>

int main()
{

	int a[10][10],q[10],n,source,f=0,r=0,visited[10],i,j;

	printf("enter the no. of order\n");
	scanf("%d",&n);
	printf("enter the matrix\n");
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

	printf("entre the source node\n");
	scanf("%d",&source);
	for(i=1; i<=n; i++)
	{
		visited[i]=0;

	}
	visited[source]=1;
	q[r]=source;
	while(f<=r)
	{
		i=q[f];
		f=f+1;
		for(j=1; j<=n; j++)
		{
			if(a[i][j]==1&&visited[j]!=1)
			{
				r=r+1;
				q[r]=j;
				visited[j]=1;
			}
		}
	}
	
	printf("the visited nodes are\n");
	for(i=1; i<=n; i++)
	{
		if(visited[i]==1)
		{
			printf("the nodes can be reached from %d to %d\n",source,i);
		}
		else
		{
		    printf("the nodes can't be reached from %d to %d\n",source,i);
		}
	}

        return 0;
}

