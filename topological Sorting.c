//QUESTION
//3a.Obtain the Topological ordering of vertices in a given digraph.
// Topological ordering of vertices
#include<conio.h>
#include<stdio.h>
#define MAX 50
/***********************************************************************/
int indeg[MAX],check[MAX],n,adj[MAX][MAX],tseq[MAX],tlen;
void compute()
 {
     int i,j;
     for(i=1;i<=n;i++)
        indeg[i]=0;
     for(i=1;i<=n;i++)
     for(j=1;j<=n;j++)
        if(adj[j][i]==1)
          indeg[i]++;
    }
/***********************************************************************/
int get()
 {
   int i;
   for(i=1;i<=n;i++)
    if(indeg[i]==0 && check[i]==0)
     return i;
     return -1;
   }
/***********************************************************************/
void update(int vertex)
  {
   int i;
   for(i=1;i<=n;i++)
    if(adj[vertex][i]==1 && indeg[i]!=0)
      indeg[i]--;
    }
/***********************************************************************/
void topo()
 {
    int vertex,i;
    tlen=0;
    for(i=1;i<=n;i++)
     {
      tseq[i]=0;
      check[i]=0;
     }
    while(1)
     {
      vertex=get();
      if(vertex==-1)
	return;
      else
       {
	tlen++;
	tseq[tlen]=vertex;
	check[vertex]=1;
	update(vertex);
	}
      }
   }
/***********************************************************************/
void main()
 {
  int a[MAX],i,j;
   clrscr();
   printf("Enter the no of vertices:  ");
   scanf("%d",&n);
   printf("\nEnter the adjacency matrix: \n");
   for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
    scanf("%d",&adj[i][j]);
   compute();
    topo();
   if(tlen==n)
    {
     printf("\nTopological order found\n\n");
      for(i=1;i<=n;i++)
      printf("%d\t",tseq[i]);
      }
      else
      printf("\nTopological ordering doesnot exists. \n");
      getch();
  }

