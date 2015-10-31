//9. Implement any scheme to find the optimal solution for the Traveling Salesperson problem and then solve the same problem instance using any approximation algorithm and determine the error in the approximation.

// Compute Nearest Neighbour
#include<stdio.h>
#include<malloc.h>

#define MAX_CITIES 20
//Max distance is assumed to be this value.
//Distance between two cities should be less than this value
#define INT_MAX 50000
#define true 1

int finalCityPath[MAX_CITIES];
int distances[MAX_CITIES][MAX_CITIES];
int dimension=0;

void nearestNeighbour(int *_cityPath)
{

	// Allocate an "already visited" array (the +1 is cause I start my array from index 1)
	bool *visited = (bool *) calloc(sizeof(bool), dimension+1);
 
	// Start from city one
	int cityVisited = 1;
 
	int minPath = INT_MAX;
	int *cityPath = _cityPath;
	int ii = 1;
	int j;
	int minPathCity = 0;
 
        int temp=0, totalCost=0;
	// Iterate all cities 
	while(cityVisited <= dimension)
	{
	
		// Iterate through all cites near ii
		for(j=1; j<=dimension;j++)
		{
			// if distance from city ii to j is lower then the minPath 
			if(distances[ii][j] < minPath)
			{
				// if I've not already choose the city
				if(!visited[j])
				{
					// replace the minPath
					minPath = distances[ii][j];
					minPathCity = j;
					//printf("New neighbor for %3d: %3d\n", ii, j);
				}
			}
		}
  
		// set 
		cityPath[cityVisited] = ii;
  
		// set ii as already visited
		visited[ii] = true;
		// ii is the next city
		ii = minPathCity;
		// reset minPath to INT_MAX for the next round
		minPath = INT_MAX;
		// increment cityVisited counter
		cityVisited++;
	}
 
	// Add retour to the first city
	cityPath[cityVisited] = cityPath[1];

        //Print the path selected
        printf("Path Traversed is: ");
        printf("%d", cityPath[1]);
        temp = 2;
        while(cityPath[temp] != cityPath[1])
        {
           printf("  %d", cityPath[temp]);
           totalCost += distances[cityPath[temp-1]][cityPath[temp]];
           temp++;
        }
        
        printf("  %d\n",cityPath[1]); 

        //add the final cost from last node to first node
        totalCost += distances[cityPath[temp-1]][cityPath[temp]];
        printf("Total Cost = %d\n", totalCost); 

} 


int main()
{
   int i=0, j=0;

   //initialize distance array
   for(i=0; i<MAX_CITIES; i++)
   {
     for(j=0; j<MAX_CITIES; j++)
     {
         distances[i][j] = INT_MAX;
     }
   }

   //initialize citypath array
   for(i=0; i<MAX_CITIES; i++)
   {
      finalCityPath[i] = INT_MAX;
   }
    
   printf("Enter the number of cities: ");
   scanf("%d", &dimension);

   printf("Enter the graph in matrix form\n");
   for(i=1; i<=dimension; i++)
   {
     for(j=1; j<=dimension; j++)
     {
         scanf("%d", &distances[i][j]);
     }
   }
      
   nearestNeighbour(finalCityPath);
}

