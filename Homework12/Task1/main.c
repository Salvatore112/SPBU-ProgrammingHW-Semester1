#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 1000

int search(char string[], char substring[]);
bool areMatched(char string[], char substring[], int left);
bool tests();

int main(int argc, char* argv[]) {
    if (!tests()) {
        return 1;
    }
    FILE* file = fopen("input.txt", "r");
    char* substring = argv[1];
    char string[SIZE];
    fread(string, 1, SIZE, file);
    printf("%d ", search(string, substring));
    fclose(file);
    return 0;
}

int search(char string[], char substring[]) {
    int module = 100;
    int stringLength = strlen(string);
    int substringLength = strlen(substring);
    int power = pow(7, substringLength);
    power = power % module;
    int *stringHash = calloc(strlen(string), sizeof(int));
    int count = 0;
    int substringHash = substring[0] % module;
    for (int i = 1; i < substringLength; i++) {
        substringHash = (substringHash * 7 + substring[i]) % module;
    }

    stringHash[0] = string[0] % module;
    for (int i = 1; i < stringLength; i++) {
        stringHash[i] = (stringHash[i - 1] * 7 + string[i]) % module;
    }
    for (int i = substringLength - 1; i < stringLength; i++) {
        if (i > substringLength - 1) {
            int tempHash = (stringHash[i] - stringHash[i - substringLength] * power) % module;
            if (tempHash < 0) {
                tempHash += module;
            }
            if (tempHash == substringHash && areMatched(string, substring, i - substringLength + 1)) {
                count++;
            }
        } else {
            if (stringHash[i] == substringHash && areMatched(string, substring, i - substringLength + 1)) {
                count++;
            }
        }
    }
    return count;
}

bool areMatched(char string[], char substring[], int left) {
    int substringLength = strlen(substring);
    for (int i = 0; i < substringLength; i++) {
        if (string[left + i] != substring[i]) {
            return false;
        }
    }
    return true;
}

bool tests() {
    char testString1[] = "adadada";
    char testSubtring1[] = "ada";
    if (search(testString1, testSubtring1) != 3) {
        printf("tests failed on a string that contains templates whose suffixes are postfixes of another templates");
        return false;
    }

    char testString2[] = "wwwww";
    char testSubtring2[] = "ada";
    if (search(testString2, testSubtring2) != 0) {
        printf("tests failed on a string that contains no templates");
        return false;
    }
    return true;
}