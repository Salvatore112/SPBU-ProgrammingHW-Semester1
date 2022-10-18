#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"
#include "stackTests.h"

void operation(char operand, Node **PostFix, Node **PostFixMachine);
char* calculator(char expression[], int expLength); 
bool tests();

int main()
{
    if (!(stackTests() && tests()))
    {
        return 1;
    }
    
    char expression[] = "9 6 - 1 2 + *";
    int length = strlen(expression);
    
    printf("the answer is %s",calculator(expression, length));
}

void operation(char operand, Node **PostFix, Node **PostFixMachine)
{
   int topElement = 0;
   int deeperElement = 0;
   
   char *tempResult = malloc(sizeof(char) * 10);
   if (tempResult == NULL)
   {
        printf("Out of memory!\n");
        exit(1);
   }
   
   if ((*PostFixMachine)->previous != NULL)
   {
        int errorCode = 0;
        pop(&(*PostFix), &errorCode);
        topElement = atoi(pop(&(*PostFixMachine), &errorCode));
        deeperElement = atoi(pop(&(*PostFixMachine), &errorCode));
   }
   switch (operand)
   {
        case '-':         
            itoa(deeperElement - topElement, tempResult, 10);
            push(&(*PostFixMachine), tempResult); 
            break;
        case '+':       
            itoa(deeperElement + topElement, tempResult, 10);
            push(&(*PostFixMachine), tempResult); 
            break;
        case '*':        
            itoa(deeperElement * topElement, tempResult, 10);
            push(&(*PostFixMachine), tempResult); 
            break;
        case '/':       
            itoa(deeperElement / topElement, tempResult, 10);
            push(&(*PostFixMachine), tempResult); 
            break;
   }
}

char* calculator(char expression[], int expLength)
{
    Node *postFix = NULL; 
    for (int i = expLength; i >= 0; i--)
    {
        if (expression[i] != ' ' && expression[i] != '\0')
        {
            char *string = malloc(sizeof(char) * 2);
            string[1] = '\0';
            string[0] = expression[i];
            push(&postFix, string);
        }
    }

    Node *postFixMachine = NULL;
    while (!isEmpty(postFix))
    {
        switch (*(peek(postFix)))
        {
            case '/':
            case '*':
            case '+':
            case '-':
                operation(*(peek(postFix)), &postFix, &postFixMachine);
                break;
            default:
                int errorCode = 0;
                push(&postFixMachine, pop(&postFix, &errorCode));
                break;
        }
    } 
    return peek(postFixMachine);
}  

bool tests()
{
    char testExpression1[] = "9 6 - 1 2 + *";
    int testLength1 = strlen(testExpression1);
    if (strcmp(calculator(testExpression1, testLength1), "9") != 0)
    {
        printf("Failed on the example exrepssion\n");
        return false;
    }

    char testExpression2[] = "9 9 +";
    int testLength2 = strlen(testExpression2);
    if (strcmp(calculator(testExpression2, testLength2), "18") != 0)
    {
        printf("Addition fail\n");
        return false;
    }

    char testExpression3[] = "5 9 -";
    int testLength3 = strlen(testExpression3);
    if (strcmp(calculator(testExpression3, testLength3), "-4") != 0)
    {
        printf("Subtraction fail\n");
        return false;
    }

    char testExpression4[] = "7 9 *";
    int testLength4 = strlen(testExpression4);
    if (strcmp(calculator(testExpression4, testLength3), "63") != 0)
    {
        printf("Multiplication fail\n");
        return false;
    }

    char testExpression5[] = "9 3 /";
    int testLength5 = strlen(testExpression5);
    if (strcmp(calculator(testExpression5, testLength5), "3") != 0)
    {
        printf("Devision fail\n");
        return false;
    }

    char testExpression6[] = "9 3 /";
    int testLength6 = strlen(testExpression6);
    if (strcmp(calculator(testExpression6, testLength6), "3") != 0)
    {
        printf("Devision fail\n");
        return false;
    }
    return true;
}
