#include <stdio.h>
#include <stdbool.h>

unsigned int collection[1000];

unsigned int fibonacci(int number);
bool fibonacciTest();

int main()
{
    if(!fibonacciTest())
    {
        return 1;
    }
    
    int sum = 0;
    
    for(int i = 0; i < 100; i++)
    {
        unsigned int number = fibonacci(i);
        
        if(number <= 1000000 && number % 2 == 0)
        {
            sum += number;
        }

    }

    printf("the sum of the Fibonacci elements that are less or equal to one million is %d", sum);
    
}


unsigned int fibonacci(int number){
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

bool fibonacciTest()
{
    int sum = 0;
    int expectedSumOfFirstEvenElements = 188;
    for(int i = 0; i <= 12; i++)
    {
        unsigned int number = fibonacci(i);
        
        if(number % 2 == 0)
        {
            sum += number;
        }

    }
    if(sum != expectedSumOfFirstEvenElements)
    {
        printf("Failed to calculate the first even elements\n");
        return false;
    }
    
    int sum1 = 0;
    int expectedSumOfFirstElements = 376;
    for(int i = 0; i <= 12; i++)
    {
        unsigned int number = fibonacci(i);
        sum1 += number;

    }
    if(sum1 != expectedSumOfFirstElements)
    {
        printf("Failed to calculate the first elements\n");
        return false;
    }
    return true;
}
