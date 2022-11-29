#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

bool isSorted(int array[], int size);
bool shuffle(int array[], int size);
void swap(int *oneValue, int *anotherValue);
void monkeySort(int array[], int size);
bool tests();

int main() {
    if (!tests()) {
        return 1;
    }
    
    srand(time(0));
    
    int size = 0;
    printf("Enter a size of the array: ");
    scanf("%d", &size);
    while (size <= 0) {
        printf("Enter a naturalNumber!\n");
        printf("Enter a size of the array: ");
        scanf("%d", &size);
    }
    int *array = malloc(sizeof(int) * size); 
    if (array == NULL) {
        printf("Out of memory\n");
        return 1;
    }
    for (int i = 0; i < size; i++) {
        printf("Enter the element #%d", i);
        scanf("%d", &array[i]);
    }

    printf("Sortedarray: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    free(array);
}

bool isSorted(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
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

bool shuffle(int array[], int size) {
    for (int i = 0; i < size; i++) {
        swap(&array[i], &array[rand() % size]);
    }
}

void monkeySort(int array[], int size) {
    while (!isSorted(array, size)) {
        shuffle(array, size);
    }
}

bool tests() {
    int testArray1[] = {1, 2, 3, 4, 5};
    monkeySort(testArray1, 5);
    if (!isSorted(testArray1, 5)) {
        printf("Test failed on a sorted array");
        return false;
    }

    int testArray2[] = {5, 4, 3, 2, 1};
    monkeySort(testArray2, 5);
    if (!isSorted(testArray2, 5)) {
        printf("Test failed on a reversed array");
        return false;
    }

    int testArray3[] = {5, 5, 5, 5, 5};
    monkeySort(testArray3, 5);
    if (!isSorted(testArray3, 5)) {
        printf("Test failed on an array of the same elements");
        return false;
    }
    return true;
}