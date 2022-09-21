#include <stdio.h>

float power(int base, int exponent);

int main()
{
    int base;
    int exponent;

    printf("Enter the base of the power: ");
    scanf("%d", &base);
    printf("Enter the base of the exponent: ");
    scanf("%d", &exponent);

    if(exponent < 0)
    {
        printf("%d^(%d) = %f\n", base, exponent, 1/power(base, -exponent));
    }
    if(exponent >= 0)
    {
        printf("%d^%d = %.0f\n", base, exponent, power(base, exponent));
    }
    
    return 0;
}

float power(int base, int exponent)
{
    if(exponent == 0)
    {
        return 1;
    }
    
    if(exponent % 2 == 0 )
    {
        float answer = power(base, exponent/2);
        return answer * answer;
    }

    if(exponent % 2 != 0 )
    {
        return base * power(base, exponent - 1);
    }

}
