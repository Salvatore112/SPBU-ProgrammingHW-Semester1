#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"

#define ARRAY_SIZE 1000

int mostFrequentElement(int array[], int length);
bool frequentElementSearchTests();

int main() {
    if (!qsortTests() || !frequentElementSearchTests()) {
        return -1;
    }

    FILE *input = fopen("array.txt", "r");
    if (input == NULL) {
        printf("File not found");
        return 1;
    }
    int array[ARRAY_SIZE] = { 0 };
    int index = 0;
    while (fscanf(input, "%d", &array[index]) != EOF) {
        index++;
    }
    fclose(input);

    for (int i = 0; i < index; i++) {
        printf("%d ", array[i]);
    }

    quickSort(array, 0, index - 1);

    printf("The most frequent element in the array is: %d ", mostFrequentElement(array, index));

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

bool frequentElementSearchTests() {
    int test1[TEST_LENGTH] = {1, 1, 1, 1, 1, 1, 2, 2, 2, 2};
    if (mostFrequentElement(test1, TEST_LENGTH) != 1) {
        printf("Failed when the most frequent element's only at the beginning\n");
        return false;
    }

    int test2[TEST_LENGTH] = {1, 1, 1, 2, 2, 2, 2, 2, 2, 2};
    if (mostFrequentElement(test2, TEST_LENGTH) != 2) {
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
