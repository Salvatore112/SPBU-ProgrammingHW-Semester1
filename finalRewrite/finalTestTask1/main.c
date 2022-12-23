#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void printArray(int** array, int rows, int columns);
void swapColumns(int** array, int oneRow, int anotherRow, int length);
void sortArray(int** array, int rows, int columns);
const int** createArray(int rows, int columns);
bool isSorted(int** array, int columns);
bool tests();

int main() {
    if (!tests()) {
        return 1;
    }
    int rows = 5;
    int columns = 5;
    srand(time(0));
    int **array = calloc(sizeof(int*), rows);
    if (array == NULL) {
        printf("Out of memory\n");
        return 1;
    }
    for (int k = 0; k < columns; k++) {
        array[k] = calloc(sizeof(int), columns);
        if (array[k] == NULL) {
            printf("Out of memory\n");
            return 1;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            array[i][j] = rand() % 100;
        }
    }
    printf("Before sort\n");
    printArray(array, rows, columns);
    sortArray(array, rows, columns);
    printf("After sort\n");
    printArray(array, rows, columns);
    return 0;
}

void printArray(int** array, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void swapColumns(int** array, int oneRow, int anotherRow, int length) {
    for (int i = 0; i < length; i++) {
        int temp = array[i][oneRow];
        array[i][oneRow] = array[i][anotherRow];
        array[i][anotherRow] = temp;
    }
}

void sortArray(int** array, int rows, int columns) {
    for (int i = 0; i < columns; i++) {
        for (int j = i; j < columns; j++) {
            if (array[0][i] > array[0][j]) {
                swapColumns(array, i, j, rows);
            }
        }
    }
}

bool isSorted(int** array, int columns) {
    for(int i = 0; i < columns - 1; i++) {
        if (array[0][i] > array[0][i + 1]) {
            return false;
        }
    }
    return true;
}

bool tests() {
    int rows = 5;
    int columns = 5;
    int **testArray = calloc(sizeof(int*), rows);
    if (testArray == NULL) {
        printf("Tests failed: out of memory\n");
        return false;
    }
    for (int k = 0; k < columns; k++) {
        testArray[k] = calloc(sizeof(int), columns);
        if (testArray[k] == NULL) {
            printf("Tests failed: out of memory\n");
            return false;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            testArray[i][j] = 1;
        }
    }
    sortArray(testArray, rows, columns);
    if (!isSorted(testArray, columns)) {
        printf("Tests failed on an array with the same number");
        return false;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            testArray[i][j] = rand() % 100;
        }
    }
    sortArray(testArray, rows, columns);
    if (!isSorted(testArray, columns)) {
        printf("Tests failed on an array with random numbers");
        return false;
    }
    return true;
}