#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define testLength 5

void selectionSortEven(int array[], int length);
bool isSortedInEven(int array[], int length);
bool tests();

int main()
{
    if(!tests())
    {
        return 1;
    }
    
    int size = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    while(size <= 0)
    {
        printf("Invalid input (enter a natural number)");
        printf("Enter the size of the array: ");
        scanf("%d", &size);
    }
    
    int *array = malloc(sizeof(int) * size);
    if(array == NULL)
    {
        printf("Memory is not avaialble!\n");
        return 1;
    }

    for(int i = 0; i < size; i++)
    {
        printf("Enter the element #%d: ", i);
        scanf("%d", &array[i]);
    }
    
    selectionSortEven(array, size);
    
    printf("Sorted array: ");
    
    for(int i = 0; i < size; i++)
    {
        printf("%d ",array[i]);
    }
    
    free(array);
    return 0;
}

void selectionSortEven(int array[], int length)
{
    for(int i = 0; i < length - 1; i += 2)
    {
        int minIndex = i;
        for(int j = i + 2; j < length; j+= 2)
        {
            if(array[j] < array[minIndex])
            {
                minIndex = j;
            }
            if(i != minIndex)
            {
                int temp = array[i];
                array[i] = array[minIndex];
                array[minIndex] = temp;
            }
        }
    }
}

bool isSortedInEven(int array[], int length)
{
    
    for(int i = 0; i < length - 2; i += 2)
    {
        if(array[i] > array[i + 2])
        {
            return false;
        }
    }
    
    return true;
}

bool tests()
{
    int test[testLength] = {5, 4, 3, 2, 1};
    selectionSortEven(test, testLength);
    if(!isSortedInEven(test, testLength))
    {
        printf("Failed on the example array\n");
        return false;
    }
    
    int test1[testLength] = {1, 2, 3, 4, 5};
    selectionSortEven(test1, testLength);
    if(!isSortedInEven(test1, testLength))
    {
        printf("Failed on the sorted array\n");
        return false;
    }

    int test2[testLength] = {9, 9, 9, 9, 9};
    selectionSortEven(test2, testLength);
    if(!isSortedInEven(test2, testLength))
    {
        printf("Failed on the array consisisting of the same element\n");
        return false;
    }
    return true;
}
