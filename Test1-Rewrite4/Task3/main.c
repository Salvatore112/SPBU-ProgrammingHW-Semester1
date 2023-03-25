#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

bool tests();
void reverse(char* fileName, int *errorCode);

int main(void) {
    if (!tests()) {
        return 1;
    }
    int errorCode = 0;
    reverse("file.txt", &errorCode);
    if (errorCode < 0) {
        printf("Error: failed on opening a file in reverse function.");
        return 1;
    }
    return 0;
}

void reverse(char* fileName, int *errorCode) {
    FILE* fileToRead = fopen(fileName, "r");
    if (fileToRead == NULL) {
        *errorCode = -1;
    }

    int numbers[SIZE] = { 0 };

    int index = 0;

    while (!feof(fileToRead)) {
        fscanf(fileToRead, "%d", &numbers[index]);
        index++;
    }

    fclose(fileToRead);
    FILE* fileToWrite = fopen(fileName, "w");
    if (fileToWrite == NULL) {
        *errorCode = -1;
    }

    for (int j = index - 1; j >= 0; j--) {
        if (j != 0) {
            fprintf(fileToWrite, "%d ", numbers[j]);
        } else {
            fprintf(fileToWrite, "%d", numbers[j]);
        }
    }
    fclose(fileToWrite);
}

bool tests() {
    // Test1 : the file contains only the same elements.
    FILE* testFile1Writing = fopen("testFile1.txt", "w");
    if (testFile1Writing == NULL) {
        printf("Tests failed on creating a file in test 1.\n");
        return false;
    }
    for (int i = 0; i < 10; i++) {
        if (i != 9) {
            fprintf(testFile1Writing, "%d ", 5);
        } else {
            fprintf(testFile1Writing, "%d", 5);
        }
    }
    fclose(testFile1Writing);
    int errorCode1 = 0;
    reverse("testFile1.txt", &errorCode1);
    if (errorCode1 < 0) {
        printf("Tests failed on opening a file in reverse function in test 1.\n");
        return false;
    }
    FILE* testFile1Reading = fopen("testFile1.txt", "r");
    if (testFile1Reading == NULL) {
        printf("Tests failed on opening a file in test 1.\n");
        return false;
    }
    for (int i = 0; i < 10; i++) {
        int temp = 0;
        fscanf(testFile1Reading, "%d", &temp);
        if (temp != 5) {
            printf("Tests failed when all the elements in the file are the same.\n");
            return false;
        }
    }

    // Test2 : the fail contains numbers in ascending order.
    FILE* testFile2Writing = fopen("testFile2.txt", "w");
    if (testFile2Writing == NULL) {
        printf("Tests failed on creating a file in test 2.\n");
        return false;
    }
    for (int i = 0; i < 10; i++) {
        if (i != 9) {
            fprintf(testFile2Writing, "%d ", i);
        } else {
            fprintf(testFile2Writing, "%d", i);
        }
    }
    fclose(testFile2Writing);
    int errorCode2 = 0;
    reverse("testFile2.txt", &errorCode2);
    if (errorCode2 < 0) {
        printf("Tests failed on opening a file in reverse function in test 2.\n");
        return false;
    }
    FILE* testFile2Reading = fopen("testFile2.txt", "r");
    if (testFile2Reading == NULL) {
        printf("Tests failed on opening a file in test 2.\n");
        return false;
    }
    int expectedResult2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    for (int i = 0; i < 10; i++) {
        int temp = 0;
        fscanf(testFile2Reading, "%d", &temp);
        if (temp != expectedResult2[i]) {
            printf("Tests failed when all the elements in the file are in ascending order.\n");
            return false;
        }
    }

    // Test3 : the fail contains numbers in descending order.
    FILE* testFile3Writing = fopen("testFile3.txt", "w");
    if (testFile3Writing == NULL) {
        printf("Tests failed on creating a file in test 3.\n");
        return false;
    }
    for (int i = 9; i >= 0; i--) {
        if (i != 0) {
            fprintf(testFile3Writing, "%d ", i);
        } else {
            fprintf(testFile3Writing, "%d", i);
        }
    }
    fclose(testFile3Writing);
    int errorCode3 = 0;
    reverse("testFile3.txt", &errorCode3);
    if (errorCode3 < 0) {
        printf("Tests failed on opening a file in reverse function in test 3.\n");
        return false;
    }
    FILE* testFile3Reading = fopen("testFile3.txt", "r");
    if (testFile2Reading == NULL) {
        printf("Tests failed on opening a file in test 3.\n");
        return false;
    }
    int expectedResult3[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 10; i++) {
        int temp = 0;
        fscanf(testFile3Reading, "%d", &temp);
        if (temp != expectedResult3[i]) {
            printf("Tests failed when all the elements in the file are in descending order.\n");
            return false;
        }
    }

    // Test 4: Empty file.
    FILE* testFile4Writing = fopen("testFile4.txt", "w");
    if (testFile4Writing == NULL) {
        printf("Tests failed on creating a file in test 4.\n");
        return false;
    }
    fclose(testFile4Writing);
    int errorCode4 = 0;
    reverse("testFile4.txt", &errorCode4);
    if (errorCode4 < 0) {
        printf("Tests failed on opening a file in reverse function in test 4.\n");
        return false;
    }
    FILE* testFile4Reading = fopen("testFile4.txt", "r");
    if (testFile2Reading == NULL) {
        printf("Tests failed on opening a file in test 4.\n");
        return false;
    }
    int temp = 0;
    fscanf(testFile4Reading, "%d", &temp);
    if (temp != 0) {
        printf("Tests failed on an empty file.\n");
        return false;
    }
    return true;
}

