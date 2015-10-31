//QUESTION: 
//4. Implement 0/1 Knapsack problem using Dynamic Programming.

#include<stdio.h>
#define MAX 10

int C[MAX][3];
int n , capacity;
int V[MAX][MAX];


void knapsack(void);
void print_sol(void);

int main(void)
{
    int i;
    
    printf("Enter the number of items\n");
    scanf("%d",&n);

    for(i = 0 ; i < n ; i++)
    {
        C[i][0] = i;

        printf("Enter profit of item %d\n",i + 1);
        scanf("%d", &C[i][1]);

        printf("Enter weight of item %d\n",i + 1);
                scanf("%d", &C[i][2]);

    }

    printf("Enter the capacity of the knapsack\n");
    scanf("%d",&capacity);

    knapsack();
    print_sol();

    return 0;
}

void knapsack(void)
{
    int i , j;

    for(i = 0 ; i <= n ; i++)
    {
        for(j = 0 ; j <= capacity ; j++)
        {
            if(i == 0 || j == 0)
                V[i][j] = 0;
            else if(C[i - 1][2] > j)
                V[i][j] = V[i - 1][j];
            else
            {
                if(V[i - 1][j] > (V[i - 1][j - C[i - 1][2]] + C[i - 1][1]) )
                    V[i][j] = V[i - 1][j];
                else
                    V[i][j] = V[i - 1][j - C[i - 1][2]] + C[i - 1][1];
            }
        }
    }
}

void print_sol(void)
{
    int x[MAX] = {0}; //array to show whether a particlar object is selected or not
    //if item i is selected x[i] = 1
    
    int i = n , j = capacity;

    while(i != 0 && j != 0)
    {
        if(V[i][j] != V[i - 1][j])
        {
            x[i - 1] = 1;
            j = j - C[i - 1][2];
        }

        i--;
    }

    for(i = 0 ; i < n ; i++)
    {
        if(x[i] == 1)
            printf("%d is selected\n",i + 1);
    }
}

