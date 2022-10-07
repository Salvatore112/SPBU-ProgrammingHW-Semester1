#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool test();
long long int fibonacci(int number);

int main()
{
    if (!test())
    {
        return 1;
    }
    
    int amount = 0;
    
    printf("How many fibonacci numbers do you want to see?: ");
    scanf("%d", &amount);

    for (int i = 0; i <= amount; i++)
    {
        printf("%lld, ", fibonacci(i));
    }
    
}

long long int fibonacci(int number)
{
    if (number == 0)
    {
        return 0;
    }
    
    if (number == 1)
    {
        return 1;
    }

    long long int *collection = malloc(sizeof(long long int) * (number + 1));
    if (collection == NULL)
    {
        printf("Out of memory!\n");
        exit(1);
    }
    
    collection[0] = 0;
    collection[1] = 1;

    for (int i = 2; i <= number; i++)
    {
        collection[i] = collection[i - 1] + collection[i - 2];
    }
    
    return collection[number];

    free(collection);
}

bool test()
{
    int FirstElementsSum = 0;
    int expectedSum = 1569;
    for (int i = 0; i <= 15; i++)
    {
        FirstElementsSum += fibonacci(i);
    }
    if (expectedSum - FirstElementsSum > 0.0000001)
    {
        printf("Test failed");
        return false;
    }
    return true;
}
