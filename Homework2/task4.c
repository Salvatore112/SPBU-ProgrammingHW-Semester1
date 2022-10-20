#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define lengthT 10

void displayArray(int array[],int size);
void swap(int *firstValue,int *secondValue);
void partition(int array[], int high, int low);
bool partitionTests();

int main() {
    if (!partitionTests()) {
        return 1;
    }
    
    srand(time(0));
    
    int size;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    while (size <= 0) {
        printf("Invalid input, try again");
        printf("Enter the size of the array: ");
        scanf("%d", &size);
    }

    int *array = malloc(size * sizeof(int));
    if (malloc == NULL) {
        printf("Memory is not available!\n");
        return 1;
    }
    
    for (int i = 0; i < size; i++) {
        array[i] = rand()%100;
    }
    
    printf("Array before the reverse: ");
    displayArray(array, size);

    partition(array, size - 1, 0);
    
    printf("\nArray after the reverse: ");
    displayArray(array, size);
    
    free(array);
}

void displayArray(int array[],int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

void swap(int *firstValue,int *secondValue) {
    int temp = *firstValue;
    *firstValue = *secondValue;
    *secondValue = temp;
}

void partition(int array[], int high, int low) {
    int pivotVal = array[low];
    int i = high;
    
    for (int j = high; j > low; j--) {
        if (array[j] >= pivotVal) {
            swap(&array[i], &array[j]);
            i--;
        }
    }
    swap(&array[i], &array[low]);
}

bool partitionTests() {
    for (int i = 0; i <= 10; i++) {
        int testArray[lengthT];
        for (int i = 0; i < lengthT; i++) {
            testArray[i] = rand()%100;
        
        }
        
        int key = testArray[0];
        
        partition(testArray, 9, 0);

        int j = 0;

        while (testArray[j] != key) {
            if (testArray[j] >= key) {
                printf("Test failed on the array");
                displayArray(testArray, lengthT);
                return false;
            }
            j++;
        }
    }
    return true;
}
