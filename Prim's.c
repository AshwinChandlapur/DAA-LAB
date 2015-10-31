//10. Find Minimum Cost Spanning Tree of a given undirected graph using Prim's algorithm.

#include<stdio.h>
int a[10][10];
void prims(int n)
{
  int i,j;
  int mincost=0,min,u,v,visited[10],ne=0;
  for(i=1;i<=n;i++)
  {
     visited[i]=0;
  }
  visited[1]=1;
  while(ne<n-1)
  {
     min=999;
     for(i=1;i<=n;i++)
     {
       if(visited[i]==1)
       {
       for(j=1;j<=n;j++)

       {
	  if(a[i][j]<min)
	  {
	     min=a[i][j];
	     u=i;
	     v=j;
	  }
       }
     }

  }
  if(visited[u]==0||visited[v]==0)
  {
    printf("from vertex  %d to %d cost=%d\n ",u,v,min);
    ne++;
    visited[v]=1;
    mincost=mincost+min;
  }
  a[u][v]=a[v][u]=9999;
 }
 printf("The min cost is %d",mincost);
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
			 scanf("%d",&a[i][j]);
		  }
	 }
	 prims(n);

         return 0;
}

