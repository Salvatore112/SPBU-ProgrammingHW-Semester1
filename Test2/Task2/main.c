#include <stdio.h>
#include <stdbool.h>
#include "binarySearchTree.h"

#define TEST_LENGTH 10

bool tests();
bool isSorted(int array[], int length);

int main() {
    if (!tests()) {
        return 1;
    }
    int array[] = {214, 645, 214, 765, 65878, 214125, 6555};
    int length = sizeof(array)/sizeof(array[0]);
    inOrderSort(array, length);
    printf("Sorted array ");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}

bool isSorted(int array[], int length) {
    for (int i = 0; i < length - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

bool tests() {
    int testArray1[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    inOrderSort(testArray1, TEST_LENGTH);
    if(!isSorted(testArray1, TEST_LENGTH)) {
        printf("Tests failed on a reversed array");
        return false;
    }

    int testArray2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    inOrderSort(testArray2, TEST_LENGTH);
    if(!isSorted(testArray2, TEST_LENGTH)) {
        printf("Tests failed on a sorted array");
        return false;
    }

    int testArray3[] = {15, 15, 15, 15, 15, 15, 15, 15, 15, 15};
    inOrderSort(testArray3, TEST_LENGTH);
    if(!isSorted(testArray3, TEST_LENGTH)) {
        printf("Tests failed on an array of the same element");
        return false;
    }
    return true;
}