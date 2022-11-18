#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 3

bool test();
long long int fibonacci(int number);

int main() {
    if (!test()) {
        return 1;
    }

    int amount = 0;

    printf("How many fibonacci numbers do you want to see?: ");
    scanf("%d", &amount);

    for (int i = 0; i <= amount; i++) {
        printf("%lld, ", fibonacci(i));
    }

}

long long int fibonacci(int number) {

    long long int collection[SIZE] = { 0 };

    collection[0] = 1;
    collection[1] = 1;
    collection[2] = 2;

    for (int i = 2; i <= number; i++) {
        collection[2] = collection[1] + collection[0];
        collection[0] = collection[1];
        collection[1] = collection[2];
    }

    return collection[1];
}

bool test()
{
    int FirstElementsSum = 0;
    int expectedSum = 1569;
    for (int i = 0; i <= 15; i++) {
        FirstElementsSum += fibonacci(i);
    }
    if (expectedSum - FirstElementsSum > 0.0000001) {
        printf("Test failed");
        return false;
    }
    return true;
}
