#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isRealNumber(char* string);
bool isDigit(char character);
bool tests();

int main() {
    if (!tests()) {
        return 1;
    }
    char* string = "2.4E+100";
    (isRealNumber(string)) ? printf("It's a real number\n") : printf("It's not a real number\n");
    return 0;
}

bool isRealNumber(char* string) {
    if (!isDigit(string[0])) {
        return false;
    }
    int length = strlen(string);
    int state = 0;
    for (int i = 0; i < length; i++) {
        char character = string[i];
        switch (state) {
            case 0:
                if (isDigit(character)) {
                    state = 1;
                } else {
                    return false;
                }
                break;
            case 1:
                if (isDigit(character)) {
                    state = 1;
                } else if (character == '.') {
                    state = 2;
                } else if (character == 'E') {
                    state = 3;
                } else {
                    return false;
                }
                break;
            case 2:
                if (isDigit(character)) {
                    state = 3;
                } else {
                    return false;
                }
                break;
            case 3:
                if (isDigit(character)) {
                    state = 3;
                } else if (character == 'E') {
                    state = 4;
                } else {
                    return false;
                }
                break;
            case 4:
                if (character == '-' || character == '+'|| isDigit(character)) {
                    state = 5;
                } else {
                    return false;
                }
                break;
            case 5:
                if (!isDigit(character)) {
                    return false;
                }
                break;
        }
    }
    return isDigit(string[length - 1]);
}

bool isDigit(char character) {
    return (character - '0' <= 9 && character - '0' >= 0) ? true : false;
}

bool tests() {
    // Test 1: A number without floating point.
    char* testString1 = "221";
    if (!isRealNumber(testString1)) {
        printf("Tests failed on passing a number without floating point");
        return false;
    }

    // Test 2: A number with floating point.
    char* testString2 = "221.662";
    if (!isRealNumber(testString2)) {
        printf("Tests failed on passing a number with floating point");
        return false;
    }

    // Test 3: A number with exponent notation.
    char* testString3 = "221E1";
    if (!isRealNumber(testString3)) {
        printf("Tests failed on passing a number with exponent notation");
        return false;
    }

    // Test 4: A number with exponent notation and order.
    char* testString4 = "221.2E+63";
    if (!isRealNumber(testString4)) {
        printf("Tests failed on passing a number  with exponent notation and order");
        return false;
    }

    // Test 5: A number containing letters
    char* testString5 = "111a";
    if (isRealNumber(testString5)) {
        printf("Tests failed on passing a number containing letters");
        return false;
    }

    // Test 6: A number ending with E.
    char* testString6 = "111E";
    if (isRealNumber(testString6)) {
        printf("Tests failed on passing a number ending with E");
        return false;
    }

    // Test 7: A number ending with '.'.
    char* testString7 = "111.";
    if (isRealNumber(testString7)) {
        printf("Tests failed on passing a number ending with \'.\'");
        return false;
    }

    // Test 8: No number.
    char* testString8 = "";
    if (isRealNumber(testString8)) {
        printf("Tests failed when there's no number");
        return false;
    }
    return true;
}
