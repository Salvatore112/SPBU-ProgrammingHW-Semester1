#include "sort.h"

int partition(int array[], int low, int high)
{
    int pivotVal = array[high];
    int i = low;
    
    for (int j = low; j < high; j++)
    {
        if (array[j] < pivotVal)
        {
            swap(&array[j], &array[i]);
            i++;
        }
    }
    swap(&array[i], &array[high]);
    return i;
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(array, low, high);
        quickSort(array, 0, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}

bool qsortTests()
{
    int test1[testLength] = {7, 7, 7, 7, 7, 7, 7, 7, 7, 7};
    quickSort(test1, 0, testLength - 1);
    if (!isSorted(test1, testLength))
    {
        printf("Failed on an array of the same elements\n");
        return false;
    }
    
    int test2[testLength] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    quickSort(test2, 0, testLength - 1);
    if (!isSorted(test2, testLength))
    {
        printf("Failed on an sorted array\n");
        return false;
    }

    int test3[testLength] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    quickSort(test3, 0, testLength - 1);
    if (!isSorted(test3, testLength))
    {
        printf("Failed on an reversed array\n");
        return false;
    }

    int test4[testLength] = {124, 211, 2233, 4424, 225, 6142, 72, 812, 21239, 0};
    quickSort(test4, 0, testLength - 1);
    if (!isSorted(test4, testLength))
    {
        printf("Failed when the first pivot is the smallest element\n");
        return false;
    }

    int test5[testLength] = {124, 211, 2233, 4424, 225, 6142, 72, 812, 21239, 9999};
    quickSort(test5, 0, testLength - 1);
    if (!isSorted(test5, testLength))
    {
        printf("Failed when the first pivot is the biggest element\n");
        return false;
    }
    return true;
} 

bool isSorted(int array[], int length){
    for (int i = 0; i < length - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            return false;
        }
    }
    return true;
}

void swap(int *oneValue, int *anotherValue)
{
    int temp = *oneValue;
    *oneValue = *anotherValue;
    *anotherValue = temp;
}