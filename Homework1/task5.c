#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 1000

bool closedBracket(char stack[], int *stackPosition, char openBracket) {
    if (*stackPosition >= 0 && stack[*stackPosition] == openBracket) {
        stack[*stackPosition] = '\0';
        *stackPosition -= 1;
        return true;
    }
    return false;
}

bool isBalanced(char string[]) {

    int stackPosition = -1;
    char stack[SIZE] = {'\0'};
    
    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        switch (string[i]) {
            case '(':
            case '{':
            case '[':
            case '<':
                stackPosition++;
                stack[stackPosition] = string[i];
                break;
            case ')':
                if (!closedBracket(stack, &stackPosition, '(')) {
                    return false;
                }
                break;
            case ']':
                if (!closedBracket(stack, &stackPosition, '[')) {
                    return false;
                }
                break;
            case '}':
                if (!closedBracket(stack, &stackPosition, '{')) {
                    return false;
                }
                break;
            case '>':
                if (!closedBracket(stack, &stackPosition, '<')) {
                    return false;
                }
                break;
        }
    }
    return stackPosition == -1;
}

int main() {
    char string[SIZE];
    
    printf("Please enter a string (less or equal to 1000 characters): ");
    scanf("%s", string);
    
    if (isBalanced(string)) {
        printf("The sequence is balanced\n");
    }
    else {
        printf("The sequence isn't balanced\n");
    }
    return 0;
}


