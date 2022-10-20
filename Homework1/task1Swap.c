#include <stdio.h>

int main() {
    int firstValue = 0; // a
    int secondValue = 0; // b
    
    printf("Enter the first value: ");
    scanf("%d", &firstValue);
    printf("Enter the second value: ");
    scanf("%d", &secondValue);

    firstValue = firstValue + secondValue; // a + b
    secondValue = firstValue - secondValue; // a + b - b = a
    firstValue = firstValue - secondValue; // a + b - a = b
    
    printf("After the swap: \n");
    printf("The first value: %d\n", firstValue);
    printf("The second value: %d\n", secondValue);

    return 0;
}
