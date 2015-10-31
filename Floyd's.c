//11. Implement All-Pairs Shortest Paths Problem using Floyd's algorithm. Parallelize this algorithm, implement it using OpenMP and determine the speed-up achieved.


  #include<stdio.h>
  #include<omp.h>
  #include <sys/time.h>
  #include <time.h>

  int min(int,int);
  void floyds(int a[10][10],int);

  long timediff(struct timeval *time2, struct timeval *time1)
  {
     long t1, t2;
     t2 = time2->tv_sec * 1000000 + time2->tv_usec;
     t1 = time1->tv_sec * 1000000 + time1->tv_usec;

     return t2 - t1;
  }


  int main()
  {

    int a[10][10],i,j,n;
    struct timeval time1, time2;

    omp_set_num_threads(5);
    printf("Enter the number of nodes\n");
   scanf("%d",&n);

   printf(" Enter the Matrix for the Graph\n");
   for(i=1;i<=n;i++)
   {
     for(j=1;j<=n;j++)
      {
       scanf("%d",&a[i][j]);
      }


   }

  gettimeofday(&time1, NULL);
  floyds(a,n);
  gettimeofday(&time2, NULL);

  printf("Matrix is \n");


  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      printf("%d\t",a[i][j]);
    }

    printf("\n");
  }
  
  printf("Using getitmeofday : Time taken is %ld usec\n", timediff(&time2, &time1));

   return 0;
}


  int min(int x, int y)

  {
     if(x < y)
     {
       return x;
     }

     else

     {
       return y;
     }

  }



  void floyds(int a[10][10], int n)
  {

   int i,j,k;
#pragma omp parallel for
   for(k=1; k<=n;k++)
   {
   printf("Thread %d of total threads %d\n", omp_get_thread_num(), omp_get_num_threads());
     for (i=1;i<=n;i++)
      {
        for(j=1;j<=n;j++)
        {
          a[i][j] = min(a[i][j], a[i][k]+a[k][j]);
        }

      }
  }
}

