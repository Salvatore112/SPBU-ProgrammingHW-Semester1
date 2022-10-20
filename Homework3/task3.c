#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define testLength 10

bool isSorted(int array[], int length);
void swap(int *oneValue, int *anotherValue);
int partition(int array[], int low, int high);
void quickSort(int array[], int low, int high);
bool qsortTests();
int mostFrequentElement(int array[], int length);
bool frequenElementSearchTests();

int main() {
    if (!qsortTests() || !frequenElementSearchTests()) {
        return -1;
    }
    
    int length;

    printf("Enter the length of the array: ");
    scanf("%d", &length);
    while (length <= 0) {
        printf("The length must be of an natural number\n");
        printf("Enter the length of the array: ");
        scanf("%d ", &length);
    }

    int *array = malloc(length * sizeof(int));
    
    for (int i = 0; i < length; i++) {
        printf("Enter the element #%d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("The most frequent element in the array is %d\n", mostFrequentElement(array, length));

    free(array);
    return 0;
}

bool isSorted(int array[], int length){
    for (int i = 0; i < length - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

void swap(int *oneValue, int *anotherValue) {
    int temp = *oneValue;
    *oneValue = *anotherValue;
    *anotherValue = temp;
}

int partition(int array[], int low, int high) {
    int pivotVal = array[high];
    int i = low;
    
    for (int j = low; j < high; j++) {
        if (array[j] < pivotVal) {
            swap(&array[j], &array[i]);
            i++;
        }
    }
    swap(&array[i], &array[high]);
    return i;
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(array, low, high);
        quickSort(array, 0, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}

int mostFrequentElement(int array[], int length) {
    int mostFrequent = array[0];
    int count = 1;
    int maxCount = -1;
    for (int i = 1; i < length - 1; i++) {
        if (array[i] == array[i + 1]) {
            count++;
            if (count > maxCount) {
                maxCount = count;
                mostFrequent = array[i];
            }
        }
        else {
            count = 1;
        }
    }
    return mostFrequent;
}

bool qsortTests() {
    int test1[testLength] = {7, 7, 7, 7, 7, 7, 7, 7, 7, 7};
    quickSort(test1, 0, testLength - 1);
    if (!isSorted(test1, testLength)) {
        printf("Failed on an array of the same elements\n");
        return false;
    }
    
    int test2[testLength] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    quickSort(test2, 0, testLength - 1);
    if (!isSorted(test2, testLength)) {
        printf("Failed on an sorted array\n");
        return false;
    }

    int test3[testLength] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    quickSort(test3, 0, testLength - 1);
    if (!isSorted(test3, testLength)) {
        printf("Failed on an reversed array\n");
        return false;
    }

    int test4[testLength] = {124, 211, 2233, 4424, 225, 6142, 72, 812, 21239, 0};
    quickSort(test4, 0, testLength - 1);
    if (!isSorted(test4, testLength)) {
        printf("Failed when the first pivot is the smallest element\n");
        return false;
    }

    int test5[testLength] = {124, 211, 2233, 4424, 225, 6142, 72, 812, 21239, 9999};
    quickSort(test5, 0, testLength - 1);
    if (!isSorted(test5, testLength)) {
        printf("Failed when the first pivot is the biggest element\n");
        return false;
    }
    return true;
} 

bool frequenElementSearchTests() {
    int test1[testLength] = {1, 1, 1, 1, 1, 1, 2, 2, 2, 2};
    if (mostFrequentElement(test1, testLength) != 1)  {
        printf("Failed when the most frequent element's only at the beginning\n");
        return false;
    }

    int test2[testLength] = {1, 1, 1, 2, 2, 2, 2, 2, 2, 2};
    if (mostFrequentElement(test2, testLength) != 2) {
        printf("Failed when the most frequent element's only at the end\n");
        return false;
    }

    int test3[1] = { 9 };
    if (mostFrequentElement(test3, 1) != 9) {
        printf("Failed when there's only one element\n");
        return false;
    }

    return true;
}
