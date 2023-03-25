#include <stdio.h>
#include <stdbool.h>
#include "stringLexer.h"

bool tests();

int main(void) {
    if (!tests()) {
        return 1;
    }
    char* string = "123AA@AA.";
    (isValidString(string) == 1 ) ? printf("%s is a valid string", string) :
    printf("%s is not a valid string", string);
}

bool tests() {
    char* testString1 = "MAIL123._%+-@ABCD456-.";
    if (!isValidString(testString1)) {
        printf("Tests failed when the string is valid");
        return false;
    }

    char* testString2 = "MAIj123._%+-@ABCD456-.";
    if (isValidString(testString2)) {
        printf("Tests failed when the string contains 1 invalid character");
        return false;
    }

    char* testString3 = "MAIj123._%+-@@ABCD456-.";
    if (isValidString(testString3)) {
        printf("Tests failed when the string contains 2 at characters");
        return false;
    }

    char* testString4 = "MAIj123._%+-@ABCD456-..";
    if (isValidString(testString4)) {
        printf("Tests failed when the string contains 2 dots");
        return false;
    }

    char* testString5 = "@ABCD456-.";
    if (isValidString(testString5)) {
        printf("Tests failed when the string doesn't contain characters from the first closure");
        return false;
    }

    char* testString6 = "MAIL123._%+-@.";
    if (isValidString(testString6)) {
        printf("Tests failed when the string doesn't contain characters from the second closure");
        return false;
    }
    return true;
}

