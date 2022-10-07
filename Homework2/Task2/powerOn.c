#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

float power(int base, int exponent);
bool tests();

int main()
{
    if (!tests())
    {
        return 1;
    }
    
    int base = 0;
    int exponent = 0;

    printf("Enter the base of the power: ");
    scanf("%d", &base);
    printf("Enter the base of the exponent: ");
    scanf("%d", &exponent);

    if (exponent < 0)
    {
        printf("%d^(%d) = %f\n", base, exponent, 1/power(base, -exponent));
    }
    if (exponent >= 0)
    {
        printf("%d^%d = %.0f\n", base, exponent, power(base, exponent));
    }
    
    
    return 0;
}

float power(int base, int exponent)
{
    if (base == 0 && exponent == 0)
    {
        printf("0^0 is not defined! \n");
        exit(1);
    }
    
    float answer = 1;
    
    for (int i = 0; i < exponent; i++)
    {
        answer = answer * base;
    }
    
    return answer;
}

bool tests()
{
    float expectedAnswer1 = 1024;
    if (power(2, 10) != expectedAnswer1)
    {
        printf("Failed when the exponent is positive\n");
        return false;
    }
    
    float expectedAnswer2 = 0.25;
    if (1 / power(2, 2) - expectedAnswer2 > 0.0001)
    {
        printf("Failed when the exponent is negative\n");
        return false;
    } 
 
    float expectedAnswer3 = 10;
    if (power(10, 1) != expectedAnswer3)
    {
        printf("Failed when the exponent is 1\n");
        return false;
    } 

    float expectedAnswer4 = 1;
    if (power(10, 0) != expectedAnswer4)
    {
        printf("Failed when the exponent is 0\n");
        return false;
    } 

    return true;
}


