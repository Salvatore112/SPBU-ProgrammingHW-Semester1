#include <stdio.h>
#include <string.h>

int isBalanced(char s[])
{

    int stackPosition = -1;
    char stack[1000] = {'\0'};
    
    for(int i = 0; i < strlen(s); i++)
    {
        switch(s[i])
        {
            case '(':
            case '{':
            case '[':
            case '<':
            stackPosition++;
            stack[stackPosition] = s[i];
            break;
            case ')':
                if(stack[stackPosition] == '(' && stackPosition >= 0)
                {
                    stack[stackPosition] = '\0';
                    stackPosition--;
                }
                else
                {
                    return 0;
                }
                break;
            case ']':
                if(stack[stackPosition] == '[' && stackPosition >= 0)
                {
                    stack[stackPosition] = '\0';
                    stackPosition--;
                }
                else
                {
                    return 0;
                }
                break;
            case '}':
                if(stack[stackPosition] == '{' && stackPosition >= 0)
                {
                    stack[stackPosition] = '\0';
                    stackPosition--;
                }
                else
                {
                    return 0;
                }
                break;
            case '>':
                if(stack[stackPosition] == '<' && stackPosition >= 0)
                {
                    stack[stackPosition] = '\0';
                    stackPosition--;
                }
                else
                {
                    return 0;
                }
                break;
        }
    }
    if(stackPosition == -1)
    {
        return 1;
    }
    return 0;
}

int main()
{

    char string[1000];
    printf("Please enter a string: ");
    scanf("%s", string);
    if(isBalanced(string))
    {
        printf("The sequence is balanced\n");
    }
    else
    {
        printf("The sequence isn't balanced\n");
    }
    return 0;
}
