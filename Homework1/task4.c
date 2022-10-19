#include <stdio.h>

#define SIZE 28

int main() {
    int arraySums[SIZE] = {0};
    for (int i = 0; i < 10; i++) {
       for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                arraySums[i + j + k] += 1;
            }
       } 
    }

    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        count += arraySums[i] * arraySums[i];
    }
    printf("Total amount of lucky tickets: %d\n", count);
}
