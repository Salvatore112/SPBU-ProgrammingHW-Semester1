#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int binarySearch(int array[], int element, int left, int right);
void swap(int *firstNumber, int *secondNumber);
int partition(int array[], int low, int high);
void quickSort(int array[], int low, int high);

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
    int *numbers = malloc(amount * sizeof(int));
    
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
        printf("none of these numbers are in the array :(\n");
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

    if(left > right)
    {
        return -1;
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
