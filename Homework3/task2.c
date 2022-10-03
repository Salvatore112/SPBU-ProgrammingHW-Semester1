#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define lengthT 10

int binarySearch(int array[], int element, int left, int right);
void swap(int *firstNumber, int *secondNumber);
int partition(int array[], int low, int high);
void quickSort(int array[], int low, int high);
bool tests();
bool checkSorted(int array[], int arrayLength);

int main()
{
    srand(time(0));
    int length;
    int amount;

    printf("Enter the length of the array: ");
    scanf("%d", &length);
    while(length <= 0)
    {
        printf("Invalid input you must enter a natural number.\n");
        printf("Enter the length of the array: ");
        scanf("%d", &length);
    }
    
    printf("How many numbers do you want to check if they're in the array?: ");
    scanf("%d", &amount);
    while(amount <= 0)
    {
        printf("Invalid input you must enter a natural number.\n");
        printf("Enter the length of the array: ");
        scanf("%d", &amount);
    } 
    
    int *array = malloc(length * sizeof(int));
    if(array == NULL)
    {
        printf("Memory is not available!\n");
        exit(1);
    }

    int *numbers = malloc(amount * sizeof(int));
    if(numbers == NULL)
    {
        printf("Memory is not available!\n");
        exit(1);
    }
    
    for(int i = 0; i < length; i++)
    {
        array[i] = rand() % 101;
    }
    for(int i = 0; i < amount; i++)
    {
        numbers[i] = rand() % 101;
    }
    
    quickSort(array, 0, length - 1);
    
    printf("Generated array: ");
    for(int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("Generated numbers: ");
    for(int i = 0; i < amount; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    

    int count = 0;
    
    for(int j = 0; j < amount; j++)
    {
        if(binarySearch(array, numbers[j], 0, length - 1) > 0)
        {
            printf("The number %d is in the array! \n", numbers[j]);
            count++;
        }
    }

    if(count == 0)
    {
        printf("none of these numbers are in the array \n");
    }
    
    free(numbers);
    free(array);
    return 0;
}

int binarySearch(int array[], int element, int left, int right)
{
    if(left > right)
    {
        return -1;
    }
    
    int mid = left + (right - left)/2;
    
    if(array[mid] == element)
    {
        return mid;
    }
    
    else if(array[mid] > element)
    {
        return binarySearch(array, element, left, mid - 1);
    }
    
    else
    {
        return binarySearch(array, element, mid + 1, right);
    }
}

void swap(int *firstNumber, int *secondNumber)
{
    int temp = *firstNumber;
    *firstNumber = *secondNumber;
    *secondNumber = temp;
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

void quickSort(int array[], int low, int high)
{
    if(low < high)
    {
        int pivotIndex = partition(array, low, high);
        quickSort(array, 0, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}

bool tests()
{
    
    int testArray2[lengthT] = {1, 5, 8, 3, 7, 9, 2, 3, 4, 100};
    quickSort(testArray2, 0, 9);
    if(!checkSorted(testArray2, lengthT))
    {   
        printf("Failed when the pivot is the biggest element");
        return false;
    }

    int testArray3[lengthT] = {122, 5, 8, 3, 7, 9, 2, 3, 4, 1};
    quickSort(testArray3, 0, 9);
    if(!checkSorted(testArray3, lengthT))
    {   
        printf("Failed when the pivot is the smallest element");
        return false;
    }
    
    int testArray1[lengthT] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    quickSort(testArray1, 0, 9);
    if(!checkSorted(testArray1, lengthT))
    {   
        printf("Failed when the elements are the same");
        return false;
    }
    
    int testArray[lengthT] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    quickSort(testArray, 0, 9);
    if(!checkSorted(testArray, lengthT))
    {   
        printf("Failed when the array is sorted");
        return false;
    }
    return true;
}

bool checkSorted(int array[], int arrayLength)
{   
    for(int i = 0; i < arrayLength - 1; i++)
    {
        if(array[i] > array[i + 1])
        {
            return false;
        }
    }
    return true;
}
