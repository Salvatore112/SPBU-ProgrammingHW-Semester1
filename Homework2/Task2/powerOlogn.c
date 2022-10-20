#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

float power(int base, int exponent);
bool tests();

int main() {
    if (!tests()) {
        return 1;
    } 
    
    int base;
    int exponent;

    printf("Enter the base of the power: ");
    scanf("%d", &base);
    printf("Enter the base of the exponent: ");
    scanf("%d", &exponent);

    if (exponent < 0) {
        printf("%d^(%d) = %f\n", base, exponent, 1 / power(base, -exponent));
    }
    if (exponent >= 0) {
        printf("%d^%d = %.0f\n", base, exponent, power(base, exponent));
    }
    
    return 0;
}

float power(int base, int exponent) {
    if (base == 0 && exponent == 0) {
        printf("0^0 is not defined! \n");
        exit(1);
    }
    
    if (exponent == 0) {
        return 1;
    }
    
    if (exponent % 2 == 0 ) {
        float answer = power(base, exponent/2);
        return answer * answer;
    }

    if (exponent % 2 != 0 ) {
        return base * power(base, exponent - 1);
    }
}

bool tests() {
    float expectedAnswer1 = 1024;
    if (power(2, 10) != expectedAnswer1) {
        printf("Failed when the exponent is positive\n");
        return false;
    }
    
    float expectedAnswer2 = 0.25;
    if (1 / power(2, 2) - expectedAnswer2 > 0.0001) {
        printf("Failed when the exponent is negative\n");
        return false;
    } 
 
    float expectedAnswer3 = 10;
    if (power(10, 1) != expectedAnswer3) {
        printf("Failed when the exponent is 1\n");
        return false;
    } 

    float expectedAnswer4 = 1;
    if (power(10, 0) != expectedAnswer4) {
        printf("Failed when the exponent is 0\n");
        return false;
    } 

    return true;
}
