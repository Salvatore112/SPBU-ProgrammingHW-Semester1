#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"

#define testLength 10
#define arraySize 1000

int mostFrequentElement(int array[], int length);
bool frequenElementSearchTests();

int main() {
    if (!qsortTests() || !frequenElementSearchTests()) {
        return -1;
    }

    FILE *input = fopen("array.txt", "r");
    int array[arraySize];
    int index = 0;
    while (fscanf(input, "%d", &array[index]) != EOF) {
        index++;
    }

    for (int i = 0; i < index; i++) {
        printf("%d ", array[i]);
    }

    quickSort(array, 0, index - 1);

    printf("The most frequent element in the array is: %d ", mostFrequentElement(array, index));


    fclose(input);
    return 0;
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

bool frequenElementSearchTests() {
    int test1[testLength] = {1, 1, 1, 1, 1, 1, 2, 2, 2, 2};
    if (mostFrequentElement(test1, testLength) != 1) {
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
