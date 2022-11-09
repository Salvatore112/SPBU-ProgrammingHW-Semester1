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

    int initialdividend = dividend;
    int initialdivisor = divisor;
    int quotient = 0;
    int count = 0;

    while (dividend > divisor) {
        dividend -= divisor;
    }
        
    quotient = dividend; 
    initialdividend -= quotient;

    while (initialdividend != 0) {
        initialdividend -= divisor;
        count++;
    }

    bool answerNegative = dividendIsNegative != divisorIsNegative;
    
    if (answerNegative) {
       if (dividendIsNegative && !divisorIsNegative) {
            return -count - 1;
        } else {
            return -count;
        }
    } 
    
    if (!answerNegative) {
       if (dividendIsNegative && divisorIsNegative) {
            return count + 1;
       } else {
            return count;
       }
    } 
}
