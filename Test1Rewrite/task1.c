#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

int countSum(int number);
int findWithTheBiggest(int array[], int tempArray[], int size);
bool sameArrays(int array1[], int array2[], int length); // function that compares two arrays of the same length (for tests)
bool tests();

int main() {
    if (!tests()) {
        return 1;
    }
    
    int size = 0;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    while (size <= 0) {
        printf("Enter a natural number!\n");
        printf("Enter the size of the array: ");
        scanf("%d", &size);
    }
    
    int *array = malloc(sizeof(int) * size);
    if (array == NULL) {
        printf("Out of memory\n");
        return 1;
    }
    int *temp = calloc(size, sizeof(int));
    if (temp == NULL) {
        printf("Out of memory\n");
        return 1;
    }

    for (int i = 0; i < size;  i++) {
        printf("Enter the number #%d: ", i);
        scanf("%d", &array[i]);
    }
    
    int amount = findWithTheBiggest(array, temp, size);
    for (int i = 0; i <= amount ; i++) {
        printf("%d ", temp[i]);
    }
    free(temp);
    free(array);
}

int countSum(int number) {
    number = abs(number);
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int findWithTheBiggest(int array[], int tempArray[], int size) {
    int maxSum = INT_MIN;
    int amount = 0;
    for (int i = 0; i < size; i++) {
        if (countSum(array[i]) > maxSum) {
            maxSum = countSum(array[i]);
            amount = 0;
            tempArray[amount] = array[i];
            continue;
        }
        if (countSum(array[i]) == maxSum) {
            amount = amount + 1;
            tempArray[amount] = array[i];
        }
    }
    return amount;
}

bool sameArrays(int array1[], int array2[], int length) {
    for (int i = 0; i < length; i++) {
        if (array1[i] != array2[i]) {
            return false;
        }
    }
    return true;
}

bool tests() {
    int testArray1[5] = {5, 5, 5, 5, 5};
    int testTemp1[5] = { 0 };
    int expectedArray1[5] = {5, 5, 5, 5, 5};
    findWithTheBiggest(testArray1, testTemp1, 5);
    if (!sameArrays(testTemp1, expectedArray1, 5)) {
        printf("Failed on the array with the same elements\n");
        return false;
    }

    int testArray2[5] = {5, -5, 5, -5, 5};
    int testTemp2[5] = { 0 };
    int expectedArray2[5] = {5, -5, 5, -5, 5};
    findWithTheBiggest(testArray2, testTemp2, 5);
    if (!sameArrays(testTemp2, expectedArray2, 5)) {
        printf("Failed on the array with the same elements (positive and negative)\n");
        return false;
    }
    return true;

    int testArray3[5] = {3, 12, 111, 50, 23};
    int testTemp3[5] = { 0 };
    int expectedArray3[5] = {50, 23};
    findWithTheBiggest(testArray3, testTemp3, 5);
    if (!sameArrays(testTemp3, expectedArray3, 5)) {
        printf("Failed on the array when there's more than one groups of the elements having the same sum of digits\n");
        return false;
    }
    return true;

    int testArray4[5] = {-9, 22221, 45, 9, 333};
    int testTemp4[5] = { 0 };
    int expectedArray4[5] = {-9, 22221, 45, 9, 333};
    findWithTheBiggest(testArray4, testTemp4, 5);
    if (!sameArrays(testTemp4, expectedArray4, 5)) {
        printf("Failed when the number is represented in varios ways\n");
        return false;
    }
    return true;
}
