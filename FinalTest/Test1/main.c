#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define BITS (sizeof(char) * 8)

const char* binaryToDecimal(char binNumber[]);
bool tests();

int main(void) {
    if (!tests()) {
        return 1;
    }
    char binary[BITS] = "1000";
    printf("%s in decimal is %s", binary, binaryToDecimal(binary));
    return 0;
}

const char* binaryToDecimal(char binNumber[]) {
    int binNumberInt = atoi(binNumber);
    int result = 0;
    int i = 0;
    int remaining = 0;

    while (binNumberInt!=0) {
        remaining = binNumberInt % 10;
        binNumberInt /= 10;
        result += remaining * pow(2, i);
        ++i;
    }

    char *output = calloc(BITS, sizeof( char ));
    itoa(result, output, 10);

    return output;
}

bool tests() {
    char testString1[BITS] = "100111";
    char expectedString1[BITS] = "39";
    if (strcmp(binaryToDecimal(testString1), expectedString1) != 0) {
        printf("Tests failed");
        return false;
    }
    return true;
}