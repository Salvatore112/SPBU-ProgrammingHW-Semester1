#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bubble_sort(int array[], int length);

int main()
{
    int length;
    
    printf("Enter the length of the array: ");
    scanf("%d", &length);

    int *array = malloc(length * sizeof(int));

    for(int i = 0; i < length; i++)
    {
        printf("Enter the element #%d: ", i);
        scanf("%d: ", &array[i]);
    }
    
    bubble_sort(array, length);

    for(int i = 0; i < length; i++)
    {
        printf("%d\n", array[i]);
    }

    return 0;
}

void bubble_sort(int array[], int length)
{
    int temp;
    int i = 0;
    bool swapped = false;
    
    do
    {
        swapped = false;
        
        for(int j = 0; j < length - 1 - i; j++)
        {
            if(array[j] > array[j + 1])
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
