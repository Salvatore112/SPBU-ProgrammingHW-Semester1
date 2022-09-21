#include <stdio.h>
#include <stdlib.h>

#define MIN -2147483648

void countingSort(int array[], int size);

int main()
{
    int length;
    printf("Enter the length of the array: ");
    scanf("%d", &length);
    
    int *array = malloc(length * sizeof(int));

    for(int i = 0; i < length; i++)
    {
        printf("Enter the element #%d: ", i);
        scanf("%d", &array[i]);
    }

    countingSort(array, length);
    
    printf("The sorted array: \n");
    for(int i = 0; i < length; i++)
    {
        printf("%d\n", array[i]);
    }  

    return 0;
}

void countingSort(int array[], int size)
{
    
    int maxElement = MIN;
    for(int i = 0; i < size; i++)
    {
        if(array[i] > maxElement)
        {
            maxElement = array[i];
        }
    }

    maxElement++;

    int *indexList = malloc(maxElement * sizeof(int));
    for(int j = 0; j < maxElement; j++)
    {
        indexList[j] = 0;
    }
    
    for(int j = 0; j < size; j++)
    {
        indexList[array[j]]++;
    }

    for(int j = 1; j < maxElement; j++)
    {
        indexList[j]+=indexList[j - 1];
    }
    
    for(int j = maxElement; j > 0; j--)
    {
        indexList[j]=indexList[j - 1];
    }
    indexList[0] = 0;

    int *outputArray = malloc(size * sizeof(int));

    for(int i = 0; i < size; i++)
    {
        outputArray[indexList[array[i]]] = array[i];
        indexList[array[i]]++;
    }

    for(int i = 0; i < size; i++)
    {
        array[i] = outputArray[i];
    } 
} 