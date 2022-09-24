#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
    int length;
    printf("Enter the length of the array: ");
    scanf("%d", &length);
    while(length <= 0)
    {
        printf("the length must be an integer number! Try again.\n");
        printf("Enter the length of the array: ");
        scanf("%d", &length);
    }

    int *array = malloc(length * sizeof(int));
    
    for(int j = 0; j < length; j++)
    {
        printf("Enter the element #%d: ", j);
        scanf("%d", &array[j]);
    }

    int maxElement = INT_MIN;
    for(int j = 0; j < length; j++)
    {
        if(array[j] > maxElement)
        {
            maxElement = array[j];
        }
    }

    int *indexes = calloc(maxElement, sizeof(int));
    
   for(int i = 0; i < 10; i++)
   {
        indexes[array[i]]++;    
   }

    int max = INT_MIN;
    int element = 0;
    
    for(int j = 0; j < maxElement + 1; j++)
    {
        if(indexes[j] >= max)
        {
            max = indexes[j];
            element = j;
        }
    }
    
    printf("The most frequent element is %d", element); 
    free(indexes);
    free(array); 
    return 0; 
}

