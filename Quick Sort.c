//QUESTION:
//1. Sort a given set of elements using the Quicksort method and determine the time required to sort the elements. Repeat the experiment for different values of n, the number of elements in the list to be sorted and plot a graph of the time taken versus n.
//The elements can be read from a file or can be generated using the random number generator.

#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>
#include <time.h>

//MAXIMUM 10000 elements can be sorted. If you give n value more than 10000 it will crash.
//increase the max value if you want to input more numbers
#define max 10000

int part(int a[],int low,int high);
void sort(int a[],int low,int high);

/*function to find the difference of start and end time*/
long timediff(struct timeval *time2, struct timeval *time1{
     long t1, t2;
     t2 = time2->tv_sec * 1000000 + time2->tv_usec;
     t1 = time1->tv_sec * 1000000 + time1->tv_usec;

     return t2 - t1;
}

int main()
{
    int a[max];
    int n;
    int k,i,f;

/*declaring two time variables time1 and time2 of type timeval*/
    struct timeval time1, time2;     
    srand(time(NULL));

    printf("enter the number of elements\n");
    scanf("%d",&n);

    printf("Elements generated randomly\n");

    for(i = 0 ; i < n ; i++)
    {
        a[i] = rand()%max;     /*randomly generated array elements*/
        printf("%d\n",a[i]);
    }

    gettimeofday(&time1, NULL);  /*function call to note current time*/

    sort(a,0,n - 1); /*call to sort array elements a low=0, high=n-1 */

    gettimeofday(&time2, NULL); /*gives time after execution of sort funct*/

    printf("Sorted elements\n");

    for(i = 0 ; i < n ; i++)
    {
        	printf("%d\n",a[i]);
    }

    printf("Using getitmeofday : Time taken is %ld usec\n", timediff(&time2, &time1));
    return 0;
}

void sort(int a[max],int low, int high)
{
    	int mid,j;
    	if(low < high)
    	{
        		j = part(a,low,high);/*j is the pivot position*/
        		sort(a,low,j - 1);
        		sort(a,j + 1,high);
    	}
}
/*this function finds the pivot position in the array and returns j*/
int part(int a[max], int low,int high)
{
    	int i,j,temp;
    	int pivot;

    	i = low;
    	j = high;
    	pivot = a[low];

    	while(i <= j)
    	{

    		while(i <= high && pivot >= a[i])  /*condition to increment i*/
        			i++;

    		while(pivot < a[j])  /*condition to decrement j*/
        			j--;

    		if(i < j)  /*comparision of i and j -positions in array*/
    		{
        			temp = a[i];
        			a[i] = a[j];
        			a[j] = temp;
    		}

    	}

    	temp = a[j]; 
    	a[j] = pivot;
    	a[low] = temp;

    	return j;
}

