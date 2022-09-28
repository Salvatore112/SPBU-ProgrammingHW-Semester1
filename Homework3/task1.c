#include <stdio.h>
#include <stdlib.h>

void display(int array[], int size);
void insertionSort(int array[], int low, int high);
void swap(int *firstVal, int *secondVal);
int partition(int array[], int low, int high);
int quickSort(int array[], int low, int high);

int main()
{
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    while(size <= 0)
    {
        printf("Invalid input! (size must be greater than 0)\n");
        printf("Enter the size of the array: ");
        scanf("%d", &size);
    }
    
    int *array = malloc(size * sizeof(int));

    if(array == NULL)
    {
        printf("Memory is not available\n");
        exit(1);
    }

    for(int i = 0; i < size; i++)
    {
        printf("Enter the element #%d: ", i);
        scanf("%d", &array[i]);
    }

    printf("\nThe array before the sort: ");
    display(array, size);
    
    quickSort(array, 0, size - 1);

    printf("\nThe array after the sort: ");
    display(array, size);
    
    free(array);
    return 0;
}

void display(int array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}

void insertionSort(int array[], int low, int high)
{
    for(int i = low; i < high; i++)
    {
        int key = array[i];
        int j = i - 1;
        while(j >= 0 && array[j] >= key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void swap(int *firstVal, int *secondVal)
{
    int temp = *firstVal;
    *firstVal = *secondVal;
    *secondVal = temp;
}

int partition(int array[], int low, int high)
{
    int pivotVal = array[high];
    
    int i = low;
    
    for(int j = low; j < high; j++)
    {
        if(array[j] <= pivotVal)
        {
            swap(&array[j], &array[i]);
            i++;
        }
    }
    swap(&array[high], &array[i]);
    return i;
}

int quickSort(int array[], int low, int high)
{
    if(high - low + 1 < 10)
    {
        insertionSort(array, low, high + 1);
        return 0;
    }
    
    if(low < high)
    {
        int pivotIndex = partition(array, 0, high);
        if(pivotIndex + 1 < 10)
        {
            insertionSort(array, 0, pivotIndex + 1);
        }
        else
        {
            quickSort(array, 0, pivotIndex - 1); 
        }
        if(high - pivotIndex + 1 < 10)
        {
            insertionSort(array, pivotIndex + 1, high + 1);
        }
        else
        {
            quickSort(array, pivotIndex + 1, high);
        }
    }
} 
