//x^4 + x^3 + x^2 + x + 1
#include<stdio.h>

int main()
{
    double x;
    printf("Please, enter the x: ");
    scanf("%lf", &x);
    
    double a = x*x;
    double answer = (a + x) * (a + 1) + 1;
    printf("x^4 + x^3 + x^2 + x + 1 = %.2lf", answer);

    return 0;
}
