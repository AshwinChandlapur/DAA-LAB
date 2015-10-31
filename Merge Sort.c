//QUESTION:
//2. Using OpenMP, implement a parallelized Merge Sort algorithm to sort a given set of elements and determine the time required to sort the elements. Repeat the experiment for different values of n, the number of elements in the list to be sorted and plot a graph of the time taken versus n. The elements can be read from a file or can be generated using the random number generator.

#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#include<time.h>

#define MAX 20

int b[MAX];

long timediff(struct timeval *time1, struct timeval *time2)
{
    long t1, t2;
    t1 = time1->tv_sec * 1000000 + time1->tv_usec;
    t2 = time2->tv_sec * 1000000 + time2->tv_usec;

    return t1 - t2;
}

void merge(int a[],int low,int mid,int high)
{
    int i,h,j,k;
    
    h=i=low;
    j= mid + 1;
  
    while((h<=mid) && (j<=high))
        if (a[h]<a[j])
            b[i++]=a[h++];
        else
            b[i++]=a[j++];

    if (h>mid)
        for(k=j;k<=high;k++)
            b[i++]=a[k];
    else
        for(k=h;k<=mid;k++)
            b[i++]=a[k];

    for(k=low;k<=high;k++)
        a[k]=b[k];
}


void mergesort(int a[],int low,int high)
{
    int mid;

    if (low<high)
    {
        mid=(low+high)/2;

        #pragma intel omp parallel taskq shared(a,mid) 
        {
            #pragma intel omp task captureprivate(a,mid)
            mergesort(a,low,mid);
            
            #pragma intel omp task captureprivate(a,mid)
            mergesort(a,mid+1,high);
        }
  
        merge(a,low,mid,high);
    }
}

int main()
{           
    int i,n=MAX;
    int a[MAX];
    struct timeval time1, time2;

    for(i=0;i<MAX;i++)
        a[i] = MAX - i;

    gettimeofday(&time1, NULL);
    mergesort(a,0,n-1);
    gettimeofday(&time2, NULL);

    printf("AFTER SORTING\n");

    for(i=0;i<MAX;i++)
        printf("%d\n", a[i]);

    printf("Using getitmeofday : Time taken is %ld usec\n", timediff(&time2, &time1));

    return 0;
}

