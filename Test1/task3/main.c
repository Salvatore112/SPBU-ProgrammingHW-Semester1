#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define size 1000

void read(FILE *file, char buffer[]);
bool tests();

int main(void) {
    if (!tests()) {
        return 1;
    }

    FILE *file = fopen("D:\\CMakeBuilds\\11_09_22\\file.txt", "r");
    if (file == NULL) {
        printf("File not found");
        return 1;
    }
    char text[size] = {'\0'};
    read(file, text);
    printf("%s", text);

    fclose(file);
    return 0;
}

void read(FILE *file, char buffer[]) {
    int character = '\0';
    int position = 0;
    while (!feof(file)) {
        character = fgetc(file);
        if (character == -1) {
            break;
        }
        if (character == '\n') {
            character = fgetc(file);
            if (character == -1) {
                break;
            }
        }
        if (buffer[position - 1] != character) {
            buffer[position] = (char)character;
            position++;
        }
    }
}

bool tests() {
    FILE *testFile1 = fopen("D:\\CMakeBuilds\\11_09_22\\example.txt", "r");
    if (testFile1 == NULL) {
        printf("File not found\n");
    }
    char expectedAnswer1[] = "afgba";
    char testBuffer1[size] = {'\0'};
    read(testFile1, testBuffer1);
    if (strcmp(expectedAnswer1, testBuffer1) != 0) {
        printf("Tests failed on the example (afgba)\n");
        return false;
    }

    FILE *testFile2 = fopen("D:\\CMakeBuilds\\11_09_22\\multipleLines.txt", "r");
    if (testFile2 == NULL) {
        printf("File not found");
    }
    char expectedAnswer2[] = "bawajfiw";
    char testBuffer2[size] = {'\0'};
    read(testFile2, testBuffer2);
    if (strcmp(expectedAnswer2, testBuffer2) != 0) {
        printf("Tests failed on a file with multiple lines");
        return false;
    }

    FILE *testFile3 = fopen("D:\\CMakeBuilds\\11_09_22\\noRepeats.txt", "r");
    if (testFile2 == NULL) {
        printf("File not found");
    }
    char expectedAnswer3[] = "abcdefg";
    char testBuffer3[size] = {'\0'};
    read(testFile3, testBuffer3);
    if (strcmp(expectedAnswer3, testBuffer3) != 0) {
        printf("Tests failed on a file without repeats\n");
        return false;
    }

    fclose(testFile1);
    fclose(testFile2);
    fclose(testFile3);
    return true;
}

