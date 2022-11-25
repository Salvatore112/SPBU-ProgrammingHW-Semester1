#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LENGTH 10

void display(int array[], int size);
void insertionSort(int array[], int low, int high);
void swap(int *firstVal, int *secondVal);
int partition(int array[], int low, int high);
void quickSort(int array[], int low, int high);
bool tests();
bool checkSorted(const int array[], int arrayLength);

int main() {
    if (!tests()) {
        return 1;
    }

    srand(time(0));
    int size = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    while (size <= 0) {
        printf("Invalid input! (size must be greater than 0)\n");
        printf("Enter the size of the array: ");
        scanf("%d", &size);
    }

    int *array = malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Out of memory\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
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

bool tests() {
    const int bigArraySize = 100;
    int* testArray4 = malloc(bigArraySize * sizeof(int));
    if (testArray4 == NULL) {
        printf("Tests failed: No memory\n");
        return false;
    }
    for (int i = 0; i < bigArraySize; i++) {
        testArray4[i] = rand() % 100;
    }
    quickSort(testArray4, 0, bigArraySize - 1);
    if (!checkSorted(testArray4, bigArraySize)) {
        printf("Failed on an array of 100 elements");
        free(testArray4);
        return false;
    }
    int testArray2[LENGTH] = {1, 5, 8, 3, 7, 9, 2, 3, 4, 100};
    quickSort(testArray2, 0, 9);
    if (!checkSorted(testArray2, LENGTH)) {
        printf("Failed when the pivot is the biggest element");
        free(testArray4);
        return false;
    }

    int testArray3[LENGTH] = {122, 5, 8, 3, 7, 9, 2, 3, 4, 1};
    quickSort(testArray3, 0, 9);
    if (!checkSorted(testArray3, LENGTH)) {
        printf("Failed when the pivot is the smallest element");
        free(testArray4);
        return false;
    }

    int testArray1[LENGTH] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    quickSort(testArray1, 0, 9);
    if (!checkSorted(testArray1, LENGTH)) {
        printf("Failed when the elements are the same");
        free(testArray4);
        return false;
    }

    int testArray[LENGTH] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    quickSort(testArray, 0, 9);
    if (!checkSorted(testArray, LENGTH)) {
        printf("Failed when the array is sorted");
        free(testArray4);
        return false;
    }

    free(testArray4);
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

void display(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

void insertionSort(int array[], int low, int high) {
    for (int i = low; i < high; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= low && array[j] >= key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void swap(int *firstVal, int *secondVal) {
    int temp = *firstVal;
    *firstVal = *secondVal;
    *secondVal = temp;
}

int partition(int array[], int low, int high) {
    int pivotVal = array[high];

    int i = low;

    for (int j = low; j < high; j++) {
        if (array[j] <= pivotVal) {
            swap(&array[j], &array[i]);
            i++;
        }
    }
    swap(&array[high], &array[i]);
    return i;
}

void quickSort(int array[], int low, int high) {
    if (high - low + 1 < 10) {
        insertionSort(array, low, high + 1);
        return;
    }
    if (low < high) {
        int pivotIndex = partition(array, 0, high);
        quickSort(array, low, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}
