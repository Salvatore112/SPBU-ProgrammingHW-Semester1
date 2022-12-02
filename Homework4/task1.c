#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

#define BITS (sizeof(int) * 8)

void decimalToBinary(int number, int binaryNumber[]);
void displayBinary(int array[]);
bool binaryConvertTests();
void binaryAddition(const int number1[], const int number2[], int result[]);
bool binAdditionTests();
int countZeros(const int binNum[]);
int countOnes(const int binNum[]);
int binaryToDecimal(const int binNum[]);
bool decimalToBinTests();

int main() {
    if (!(decimalToBinTests() && binAdditionTests() && binaryConvertTests())) {
        return 1;
    }

    setlocale(LC_ALL, "Rus");

    int number1 = 0;
    int number2 = 0;

    printf("Введите первое число: ");
    scanf("%d", &number1);
    printf("Введите второе число: ");
    scanf("%d", &number2);

    int binNumber1[BITS] = { 0 };
    int binNumber2[BITS] = { 0 };

    decimalToBinary(number1, binNumber1);
    decimalToBinary(number2, binNumber2);

    printf("Первое число в двоичной представлении в дополнительном коде: ");
    displayBinary(binNumber1);
    printf("\nВторое число в двоичной представлении в дополнительном коде: ");
    displayBinary(binNumber2);

    int result[BITS] = { 0 };
    binaryAddition(binNumber1, binNumber2, result);

    printf("\nСумма обоих чисел в двоичной представлении в дополнительном коде: ");
    displayBinary(result);

    printf("\nСумма чисел в десятичном виде: %d", binaryToDecimal(result));

    return 0;
}

void decimalToBinary(int number, int binaryNumber[]) {
    int bit = 1;
    for (int i = BITS - 1; i >= 0; i--) {
        binaryNumber[i] = ((number & bit) ? 1 : 0);
        number >>= 1;
    }
}

void displayBinary(int array[]) {
    for (int i = 0; i < BITS; i++) {
        printf("%d ", array[i]);
    }
}

void binaryAddition(const int number1[], const int number2[], int result[]) {
    int inMind = 0;

    for (int i = BITS - 1; i >= 0; i--) {
        int interResult = number1[i] + number2[i] + inMind;
        switch (interResult) {
            case 0:
                result[i] = 0;
                inMind = 0;
                break;
            case 1:
                result[i] = 1;
                inMind = 0;
                break;
            case 2:
                result[i] = 0;
                inMind = 1;
                break;
            case 3:
                result[i] = 1;
                inMind = 1;
                break;
            default:
                printf("Unexpected error\n");
        }
	}
}

int countZeros(const int binNum[]) {
    int count = 0;
    for (int i = 0; i < BITS; i++) {
        if (binNum[i] == 0) {
            count++;
        }
    }
    return count;
}

int countOnes(const int binNum[]) {
    int count = 0;
    for (int i = 0; i < BITS; i++) {
        if (binNum[i] == 1) {
            count++;
        }
    }
    return count;
}

int binaryToDecimal(const int binNum[]) {
    int currentExponent = 1;
    int result = 0;
    for (int i = BITS - 1; i >= 0; i--) {
        result += binNum[i] * currentExponent;

        currentExponent *= 2;
    }
    return result;
}

bool decimalToBinTests() {
    int testVal1 = 100;
    int binVal1[BITS] = { 0 };
    decimalToBinary(testVal1, binVal1);
    if (binaryToDecimal(binVal1) != testVal1) {
        printf("Decimal to binary convert failed on a positive number");
        return false;
    }

    int testVal2 = -124;
    int binVal2[BITS] = { 0 };
    decimalToBinary(testVal2, binVal2);
    if (binaryToDecimal(binVal2) != testVal2) {
        printf("Decimal to binary convert failed on a positive number");
        return false;
    }
    return true;
}

bool binaryConvertTests() {
    int testNum1 = 2049;
    int testBinNum1[BITS] = { 0 };
    decimalToBinary(testNum1, testBinNum1);
    if (!(testBinNum1[BITS - 1] == 1 && testBinNum1[BITS - 12] == 1 && countZeros(testBinNum1) == 30)) {
        printf("Binary convert failed on a positive number!\n");
        return false;
    }

    int testNum2 = -257;
    int testBinNum2[BITS] = { 0 };
    decimalToBinary(testNum2, testBinNum2);
    if (!(testBinNum2[BITS - 9] == 0 && countOnes(testBinNum2) == 31)) {
        printf("Binary convert failed on a negative number!\n");
        return false;
    }
    return true;
}

bool binAdditionTests() {
    int testNum11 = 1020;
    int testNum12 = 4;
    int testNumBin11[BITS] = { 0 };
    int testNumBin12[BITS] = { 0 };
    int result1[BITS] = { 0 };
    decimalToBinary(testNum11, testNumBin11);
    decimalToBinary(testNum12, testNumBin12);
    binaryAddition(testNumBin11, testNumBin12, result1);
    if (!(result1[BITS - 11] == 1 && countZeros(result1) == 31)) {
        printf("Addition failed on adding two positive values\n");
        return false;
    }

    int testNum21 = -130;
    int testNum22 = 1;
    int testNumBin21[BITS] = { 0 };
    int testNumBin22[BITS] = { 0 };
    int result2[BITS] = { 0 };
    decimalToBinary(testNum21, testNumBin21);
    decimalToBinary(testNum22, testNumBin22);
    binaryAddition(testNumBin21, testNumBin22, result2);
    if (!(countOnes(result2) == 31 && result2[BITS - 8] == 0)) {
        printf("Addition failed on adding negative and positive value\n");
        return false;
    }

    int testNum31 = -510;
    int testNum32 = -3;
    int testNumBin31[BITS] = { 0 };
    int testNumBin32[BITS] = { 0 };
    int result3[BITS] = { 0 };
    decimalToBinary(testNum31, testNumBin31);
    decimalToBinary(testNum32, testNumBin32);
    binaryAddition(testNumBin31, testNumBin32, result3);
    if (!(countOnes(result3) == 31 && result3[BITS - 10] == 0)) {
        printf("Addition failed on adding two negative values\n");
        return false;
    }
    return true;
}
