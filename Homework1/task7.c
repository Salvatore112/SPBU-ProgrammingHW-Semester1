#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int num) {
    if (num == 1) {
        return false;
    }

    int sqrtNum = sqrt(num);
    
    for (int i = 2; i <= sqrtNum; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    
    return true;
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
    
    for(int i = 1; i <= number; i++) {
        if (isPrime(i) == 1) {
            printf("%d\n", i);
        }
    }
    return 0;
}
