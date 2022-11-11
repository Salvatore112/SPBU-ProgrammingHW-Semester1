int main() {
    int number = 0;
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
