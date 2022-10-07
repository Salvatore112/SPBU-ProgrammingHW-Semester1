#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define lengthT 10

void bubbleSort(int array[], int length);
bool testsSorts();
bool checkSorted(int array[], int arrayLength);

int main()
{
    if (!testsSorts())
    {
        return 1;
    }

    int length;
    
    printf ("Enter the length of the array: ");
    scanf ("%d", &length);

    int *array = malloc(length * sizeof (int));

    for (int i = 0; i < length; i++)
    {
        printf ("Enter the element #%d: ", i);
        scanf ("%d: ", &array[i]);
    }
    
    bubbleSort(array, length);

    printf("The sorted array: ");
    for (int i = 0; i < length; i++)
    {
        printf ("%d ", array[i]);
    }

    return 0;
}

void bubbleSort(int array[], int length)
{
    int temp;
    int i = 0;
    bool swapped = false;
    
    do
    {
        swapped = false;
        
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = true;
            }
        }
        
        i++;

    } while (swapped);
}

bool testsSorts()
{
    int testArray1[lengthT] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    bubbleSort(testArray1, lengthT);
    if (!checkSorted(testArray1, lengthT))
    {   
        printf ("Sort Failed when the elements are the same\n");
        return false;
    }
    
    int testArray2[lengthT] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bubbleSort(testArray2, lengthT);
    if (!checkSorted(testArray2, lengthT))
    {   
        printf ("Sort Failed when the array is sorted\n");
        return false;
    }
    return true;

    int testArray3[lengthT] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    bubbleSort(testArray3, lengthT);
    if (!checkSorted(testArray3, lengthT))
    {   
        printf ("Sort Failed when the array is reversed\n");
        return false;
    }
    return true;
}

bool checkSorted(int array[], int arrayLength)
{   
    for (int i = 0; i < arrayLength - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            return false;
        }
    }
    return true;
}
