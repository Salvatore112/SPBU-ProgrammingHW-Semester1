#include <stdio.h>
#include <stdbool.h>

unsigned int fibonacci(int number);

bool test();

int main() {
    if (!test()) {
        return 1;
    }
    
    int amount = 0;

    printf("How many fibonacci cnumbers do you want to see?: ");
    scanf("%u", &amount);
    
    while (amount <= 0) {
        printf("Enter a natural number!\n!");
        printf("How many fibonacci cnumbers do you want to see?: ");
        scanf("%u", &amount);
    }
    
    for (int i = 0; i < amount; i++) {
        printf("%u, ", fibonacci(i));
    }

}

unsigned int fibonacci(int number) {
    if (number == 0) {
        return 0;
    }
    if (number == 1) {
        return 1;
    }
    
    return fibonacci(number - 1) + fibonacci(number - 2);
}

bool test() {
    int FirstElementsSum = 0;
    int expectedSum = 1596;
    for (int i = 0; i <= 15; i++) {
        FirstElementsSum += fibonacci(i);
    }
    if (expectedSum != FirstElementsSum) {
        printf("Test failed");
        return false;
    }
    return true;
}
