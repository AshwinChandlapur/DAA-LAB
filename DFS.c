
//Check whether a graph is connected or not using DFS method

#include<stdio.h>

int a[10][10],n,visited[10];

void dfs(int source)
{
   int j;
   visited[source]=1;
   for(j=1;j<=n;j++)
   {
      if(a[source][j]==1&&visited[j]!=1)
      {
	  dfs(j);
      }
   }
}


int main()
{
   int source,i,j,flag=0;

   printf("Enter the no of nodes : ");
   scanf("%d",&n);
   printf("Enter the matrix:\n");
   for(i=1;i<=n;i++)
     for(j=1;j<=n;j++)
       scanf("%d",&a[i][j]);

   printf("Enter the source node : ");
   scanf("%d",&source);

   dfs(source);



   for(i=1;i<=n;i++)
     if(visited[i]==0)
       {
	 flag=1;
       }

   if(flag==0)
   printf("Graph is Connected\n");
   else
   printf("Graph is Not connected\n");

   return 0;
}

