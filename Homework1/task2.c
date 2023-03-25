#include <stdio.h>
#include <stdbool.h>

int partialQuotient(int dividend, int divisor);

int main() {
    int dividend = 0;
    int divisor = 0;

    printf("Please enter a dividend: ");
    scanf("%d", &dividend);
    printf("Please enter a divisor: ");
    scanf("%d", &divisor);

    printf("Incomplete quotient = %d\n", partialQuotient(dividend, divisor));
}

int partialQuotient(int dividend, int divisor) {
    bool dividendIsNegative = false;
    bool divisorIsNegative = false;

    if (dividend < 0) {
        dividend = -dividend;
        dividendIsNegative = true;
    }
    if (divisor < 0) {
        divisor = -divisor;
        divisorIsNegative = true;
    }

    int initialDividend = dividend;

    int count = 0;
    while (initialDividend > divisor) {
        initialDividend -= divisor;
        count++;
    }

    bool answerNegative = dividendIsNegative != divisorIsNegative;

    if (answerNegative) {
        return (dividendIsNegative && !divisorIsNegative) ? -count - 1 : -count;
    }

    return (dividendIsNegative && divisorIsNegative) ? count + 1 : count;
}
