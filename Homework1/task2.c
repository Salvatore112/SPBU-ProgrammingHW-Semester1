#include <stdio.h>
#include <stdbool.h>

int partialDevident(int devident, int deviser);

int main()
{
    int devident;
    int deviser;
    
    printf("Please enter a devident: ");
    scanf("%d", &devident);
    printf("Please enter a deviser: ");
    scanf("%d", &deviser);
    
    printf("Incomplete quotient = %d\n", partialDevident(devident, deviser));

}

int partialDevident(int devident, int deviser)
{
    bool devidentIsNegative = false; 
    bool deviserIsNegative = false; 
    
    if(devident < 0)
    {
        devident = -devident;
        devidentIsNegative = true;
    }
    if(deviser < 0)
    {
        deviser = -deviser; 
        deviserIsNegative = true;
    }

    int initialDevident = devident;
    int initialDeviser = deviser;
    int quotient = 0;
    int count = 0;

    while(devident > deviser)
    {
        devident-=deviser;
    }
        
    quotient = devident; 
    initialDevident-=quotient;

    while(initialDevident != 0)
    {
        initialDevident-=deviser;
        count++;
    }

    if(devidentIsNegative == false && deviserIsNegative == false)
    {
        return count;
    }

    if(devidentIsNegative == false && deviserIsNegative == true)
    {
        return -count;
    }

    if(devidentIsNegative == true && deviserIsNegative == false)
    {
        return -count - 1;
    }

    if(devidentIsNegative == true && deviserIsNegative == true)
    {
        return count + 1;
    }
    
}
    
