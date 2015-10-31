//6. Find Minimum Cost Spanning Tree of a given undirected graph using Kruskal's algorithm.

#include<stdio.h>
int cost[10][10];

void kruskals(int n)
{
   int i,j,ne=0,parent[10],min,mincost=0,a,b,u,v;
   for(i=1;i<=n;i++)
     parent[i]=0;
	 
  while(ne!=n-1)
  {
    min=999;
    for(i=1;i<=n;i++)
    {
       for(j=1;j<=n;j++)
       {
			if(cost[i][j]<min)
			{
				min=cost[i][j];
				a=i;
				u=i;
				b=j;
				v=j;
			}
       }
    }
	
    while(parent[u]!=0)
        u=parent[u];
    while(parent[v]!=0)
        v=parent[v];
    
	if(u!=v)
    {   
        printf("vertex(%d,%d)\n",a,b,min);
        ne++;
        parent[v]=u;
        mincost=mincost+min;
    }
	
    cost[a][b]=cost[b][a]=999;
  }
  
 printf("cost of spanning tree is=%d \n",mincost);
}

int main()
{
	int i,j,n;

	printf("enter the no of nodes\n");
	scanf("%d",&n);
	printf("enter matrix\n");

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
		}
	}
	
	kruskals(n);

    return 0;
}

