#include <stdio.h>

unsigned int fibonacci(int number);

int main()
{
    int amount;
    
    printf("How many fibonacci collection do you want to see?: ");
    scanf("%d", &amount);
    
    for(int i = 0; i < amount; i++)
    {
        printf("%u, ", fibonacci(i));
    }

}

unsigned int fibonacci(int number)
{
    if(number == 0)
    {
        return 0;
    }
    if(number == 1)
    {
        return 1;
    }
    
    return fibonacci(number - 1) + fibonacci(number - 2);
}