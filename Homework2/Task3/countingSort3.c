#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define TEST_LENGTH 10

int countingSort(int array[], int size);
bool checkSorted(const int array[], int arrayLength);
bool testsSorts();

int main() {
    if (!testsSorts()) {
        return 1;
    }

    int length = 0;
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

    if (countingSort(array, length) == 1) {
        printf("Out of memory\n");
        return 1;
    }

    printf("The sorted array: \n");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}

int countingSort(int array[], int size) {
    int maxElement = array[0];
    for (int i = 0; i < size; i++) {
        if (array[i] > maxElement) {
            maxElement = array[i];
        }
    }

    maxElement++;

    int *indexList = calloc(maxElement, sizeof(int));
    if (indexList == NULL) {
        return 1;
    }

    for (int j = 0; j < size; j++) {
        indexList[array[j]]++;
    }

    for (int j = 1; j < maxElement; j++) {
        indexList[j] += indexList[j - 1];
    }

    for (int j = maxElement; j > 0; j--) {
        indexList[j] = indexList[j - 1];
    }
    indexList[0] = 0;

    int *outputArray = malloc(size * sizeof(int));
    if (outputArray == NULL) {
        free(indexList);
        return 1;
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
    return 0;
}

bool testsSorts() {
    int testArray1[TEST_LENGTH] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    countingSort(testArray1, TEST_LENGTH);
    if (!checkSorted(testArray1, TEST_LENGTH)) {
        printf ("Sort Failed when the elements are the same\n");
        return false;
    }

    int testArray2[TEST_LENGTH] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    countingSort(testArray2, TEST_LENGTH);
    if (!checkSorted(testArray2, TEST_LENGTH)) {
        printf ("Sort Failed when the array is sorted\n");
        return false;
    }

    int testArray3[TEST_LENGTH] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    countingSort(testArray3, TEST_LENGTH);
    if (!checkSorted(testArray3, TEST_LENGTH)) {
        printf ("Sort Failed when the array is reversed\n");
        return false;
    }
    return true;
}

bool checkSorted(const int array[], int arrayLength) {
    for (int i = 0; i < arrayLength - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}
