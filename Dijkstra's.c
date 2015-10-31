//QUESTION:
//5. From a given vertex in a weighted connected graph, find shortest paths to other vertices using Dijkstra's algorithm.

#include<stdio.h>


void dijkstra(int n,int cost[10][10],int src)
{
	int i,j,u,v,d[10],s[10],min;
	for(i=1;i<=n;i++)
	{
		d[i] = cost[src][i];
		s[i] = 0;
	}
	s[src] = 1;
	for(i=1;i<=n;i++)
	{
		min=9999;
		for(j=1;j<=n;j++)
		{
			if(s[j]==0 && d[j]<min)
			{
				min=d[j];
				u=j;
			}
		}
		s[u]=1;
		for(v=1;v<=n;v++)
		{
			if(s[v] == 0)
			{
				if(d[u]+cost[u][v]<d[v])
				{
				 d[v]=d[u]+cost[u][v];
				}
			}
		}
	}
		printf("\n The shortest paths are: \n");
		for(i=1;i<=n;i++)
		{
			printf("%d -- > %d = %d \n",src,i,d[i]);
		}
}

void main()
{
	int i,j,n,cost[10][10],d[10],s[10],src;

	printf("\n Enter the number of nodes :");
	scanf("%d",&n);
	printf("\n Enter the cost adjacency matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
		}
	}
	printf("\n Enter the source:");
	scanf("%d",&src);
	dijkstra(n,cost,src);

}

