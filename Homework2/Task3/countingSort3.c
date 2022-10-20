#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN -100
#define lengthT 10

void countingSort(int array[], int size);
bool checkSorted(int array[], int arrayLength);
bool testsSorts();

int main() {
    if (!testsSorts()) {
        return 1;
    }
    
    int length;
    printf("Enter the length of the array: ");
    scanf("%d", &length);
    
    int *array = malloc(length * sizeof(int));
    if (array == NULL) {
        printf("Memory is not available\n");
        return 1;
    }

    for (int i = 0; i < length; i++) {
        printf("Enter the element #%d: ", i);
        scanf("%d", &array[i]);
    }

    countingSort(array, length);
    
    printf("The sorted array: \n");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }  

    return 0;
}

void countingSort(int array[], int size)
{
    int maxElement = MIN;
    for (int i = 0; i < size; i++) {
        if (array[i] > maxElement) {
            maxElement = array[i];
        }
    }

    maxElement++;

    int *indexList = malloc(maxElement * sizeof(int));
    if (indexList == NULL) {
        printf("Memory is not available");
        exit(1);
    }

    for (int j = 0; j < maxElement; j++) {
        indexList[j] = 0;
    }
    
    for (int j = 0; j < size; j++) {
        indexList[array[j]]++;
    }

    for (int j = 1; j < maxElement; j++) {
        indexList[j]+=indexList[j - 1];
    }
    
    for (int j = maxElement; j > 0; j--) {
        indexList[j]=indexList[j - 1];
    }
    indexList[0] = 0;

    int *outputArray = malloc(size * sizeof(int));
    if(outputArray == NULL) {
        printf("Memory is not available");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        outputArray[indexList[array[i]]] = array[i];
        indexList[array[i]]++;
    }

    for (int i = 0; i < size; i++) {
        array[i] = outputArray[i];
    } 

    free(indexList);
    free(outputArray);
} 

bool testsSorts() {
    int testArray1[lengthT] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    countingSort(testArray1, lengthT);
    if (!checkSorted(testArray1, lengthT)) {   
        printf ("Sort Failed when the elements are the same\n");
        return false;
    }
    
    int testArray2[lengthT] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    countingSort(testArray2, lengthT);
    if (!checkSorted(testArray2, lengthT)) {   
        printf ("Sort Failed when the array is sorted\n");
        return false;
    }

    int testArray3[lengthT] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    countingSort(testArray3, lengthT);
    if (!checkSorted(testArray3, lengthT)) {   
        printf ("Sort Failed when the array is reversed\n");
        return false;
    }
    return true;
}

bool checkSorted(int array[], int arrayLength) {   
    for (int i = 0; i < arrayLength - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}
