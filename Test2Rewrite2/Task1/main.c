#include <stdio.h>
#include "LinkedList.h"

bool tests();

bool program(char* inputFileName, char* outputFileName, int a, int b);

bool checkNumbers(char* outputFile, int* expectedResult, int length);

int main(void) {
    if (!tests()) {
        return 1;
    }
    if ((program("input.txt", "output.txt", 10, 20))){
        return 1;
    };
    return 0;
}

bool program(char* inputFileName, char* outputFileName, int a, int b) {
    FILE* fileInput = fopen(inputFileName, "r");
    if (fileInput == NULL) {
        printf("File not found\n");
        return 1;
    }

    bool errorCode = 0;
    LinkedList* lessThanA = createList(&errorCode);
    if (errorCode) {
        printf("Out of memory\n");
        return 1;
    }
    LinkedList* betweenAnB = createList(&errorCode);
    if (errorCode) {
        printf("Out of memory\n");
        return 1;
    }
    LinkedList* greaterThanB = createList(&errorCode);
    if (errorCode) {
        printf("Out of memory\n");
        return 1;
    }

    while (!feof(fileInput)) {
        int number = 0;
        fscanf(fileInput, "%d", &number);
        if (number < a) {
            endInsert(number, lessThanA);
        } else if (number > b) {
            endInsert(number, greaterThanB);
        } else {
            endInsert(number, betweenAnB);
        }
    }
    fclose(fileInput);

    FILE* fileOutput = fopen(outputFileName, "w");
    if (fileOutput == NULL) {
        printf("File not found");
        deleteList(lessThanA);
        deleteList(greaterThanB);
        deleteList(betweenAnB);
        return 1;
    }

    printToFile(lessThanA, fileOutput);
    printToFile(betweenAnB, fileOutput);
    printToFile(greaterThanB, fileOutput);

    deleteList(lessThanA);
    deleteList(betweenAnB);
    deleteList(greaterThanB);
    fclose(fileOutput);
}

bool checkNumbers(char* outputFile, int expectedResult[], int length) {
    FILE* testOutput = fopen(outputFile, "r");
    int i = 0;
    while (i < length) {
        int outputNumber = 0;
        fscanf(testOutput, "%d", &outputNumber);
        if (outputNumber != expectedResult[i]) {
            return false;
        }
        i++;
    }
    fclose(testOutput);
    return true;
}

bool tests() {
    // Test1: reversed Array.
    program("testInput1.txt", "testOutput1.txt", 5, 30);
    int expectedResult1[] = {4, 1, 30, 25, 24, 5, 50, 40};
    if (!checkNumbers("testOutput1.txt", expectedResult1, 7)) {
        printf("Tests failed on a reversed array");
        return false;
    }

    // Test2: sorted Array.
    program("testInput2.txt", "testOutput2.txt", 5, 10);
    int expectedResult2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    if (!checkNumbers("testOutput2.txt", expectedResult2, 10)) {
        printf("Tests failed on a sorted array array");
        return false;
    }

    // Test3: empty file.
    program("testInput3.txt", "testOutput3.txt", 5, 10);
    int testNumber = 0;
    FILE* testFile3 = fopen("testOutput3.txt", "r");
    fscanf(testFile3, "%d", &testNumber);
    if (testNumber != 0) {
        printf("Tests failed on an empty file");
        return false;
    }
    fclose(testFile3);

    // Test4: only numbers that are greater than B
    program("testInput4.txt", "testOutput4.txt", 5, 10);
    int expectedResult4[] = {100, 200, 300, 400};
    if (!checkNumbers("testOutput4.txt", expectedResult4, 4)) {
        printf("Tests when the file contains only numbers that are greater than b");
        return false;
    }

    // Test5: only numbers that are smaller than A
    program("testInput5.txt", "testOutput5.txt", 5, 10);
    int expectedResult5[] = {1, 2, 3, 4};
    if (!checkNumbers("testOutput5.txt", expectedResult5, 4)) {
        printf("Tests when the file contains only numbers that are smaller than a");
        return false;
    }

    // Test6: only numbers that are bigger or equal than A and smaller or equal to B
    program("testInput6.txt", "testOutput6.txt", 5, 10);
    int expectedResult6[] = {6, 7, 8, 9};
    if (!checkNumbers("testOutput6.txt", expectedResult6, 4)) {
        printf("Tests when the file contains only numbers that are bigger or equal than A and smaller or equal to B");
        return false;
    }
    return true;
}