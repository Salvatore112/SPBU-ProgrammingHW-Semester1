#include <stdio.h>

unsigned int collection[1000];

unsigned int fibonacci(int number)
{
    if(number == 0)
    {
        collection[0] = 0;
        return collection[0];
    }
    if(number == 1)
    {
        collection[1] = 1;
        return collection[1];
    }
    collection[number] = collection[number - 1] + collection[number - 2];
    return collection[number];
}

int main()
{
    int amount;
    
    printf("How many fibonacci collection do you want to see?: ");
    scanf("%d", &amount);

    for(int i = 0; i < amount; i++)
    {
       printf("%u, ", fibonacci(i));
    }
    
    return 0;
}
