#include <stdio.h>
#include <math.h>

int isPrime(int num) {
    if (num == 1) {
        return 0;
    }

    int sqrtNum = sqrt(num);
    
    for (int i = 2; i <= round(sqrtNum); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number <= 1) {
        printf("There are no prime numbers that are less or equal to %d\n", number);
        return 0;
    }

    printf("Prime numbers that are less or equal to %d: \n", number);
    
    for (int i = 1; i <= number; i++) {
        if (isPrime(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}
