#include <stdio.h>
#include <stdbool.h>

int partialDevident(int devident, int deviser);

int main()
{
    int devident = 0;
    int deviser = 0;
    
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
    
    if (devident < 0)
    {
        devident = -devident;
        devidentIsNegative = true;
    }
    if (deviser < 0)
    {
        deviser = -deviser; 
        deviserIsNegative = true;
    }

    int initialDevident = devident;
    int initialDeviser = deviser;
    int quotient = 0;
    int count = 0;

    while (devident > deviser)
    {
        devident -= deviser;
    }
        
    quotient = devident; 
    initialDevident -= quotient;

    while (initialDevident != 0)
    {
        initialDevident -= deviser;
        count++;
    }

    bool answerNegative = true;

    if (!devidentIsNegative && !deviserIsNegative || devidentIsNegative && deviserIsNegative)
    {
        answerNegative = false;
    }
    
    if (answerNegative)
    {
       if (devidentIsNegative && !deviserIsNegative)
       {
            return -count - 1;
       }
       else
       {
            return -count;
       }
    } 
    
    if (!answerNegative)
    {
       if (devidentIsNegative && deviserIsNegative)
       {
            return count + 1;
       }
       else
       {
            return count;
       }
    } 
}
