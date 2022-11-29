#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

float power(int base, int exponent, int *errorCode);
bool tests();

int main() {
    if (!tests()) {
        return 1;
    }

    int base = 0;
    int exponent = 0;
    int errorCode = 0;

    printf("Enter the base of the power: ");
    scanf("%d", &base);
    printf("Enter the base of the exponent: ");
    scanf("%d", &exponent);

    float answer = power(base, exponent, &errorCode);
    if (errorCode != 0) {
        printf("Not defined");
    } else {
        printf("%.5f", answer);
    }
    
    return 0;
}

float power(int base, int exponent, int *errorCode) {
    bool wasNegative = true;
    if (exponent > 0) {
        wasNegative = false;
    }
    exponent = abs(exponent);

    if (base == 0 && exponent == 0) {
        *errorCode = 1;
        return 1;
    }

    float answer = 1;

    for (int i = 0; i < exponent; i++) {
        answer = answer * base;
    }

    *errorCode = 0;
    return wasNegative ? 1.0f / answer : answer;
}

bool tests() {
    float expectedAnswer1 = 1024;
    int errorCode1 = 1;
    if (power(2, 10, &errorCode1) != expectedAnswer1) {
        printf("Failed when the exponent is positive\n");
        return false;
    }

    float expectedAnswer2 = 0.25;
    int errorCode2 = 1;
    if (power(2, -4, &errorCode2) - expectedAnswer2 > 0.0001) {
        printf("Failed when the exponent is negative\n");
        return false;
    }

    float expectedAnswer3 = 10;
    int errorCode3 = 1;
    if (power(10, 1, &errorCode3) != expectedAnswer3) {
        printf("Failed when the exponent is 1\n");
        return false;
    }

    float expectedAnswer4 = 1;
    int errorCode4 = 1;
    if (power(10, 0, &errorCode4) != expectedAnswer4) {
        printf("Failed when the exponent is 0\n");
        return false;
    }

    return true;
}




