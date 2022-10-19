#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 1000

bool closedBracket(char stack[], int *stackPosition, char openBracket) {
    if (stack[*stackPosition] == openBracket && *stackPosition >= 0) {
        stack[*stackPosition] = '\0';
        *stackPosition -= 1;
        return true;
    }
    return false;
}

bool isBalanced(char s[]) {

    int stackPosition = -1;
    char stack[SIZE] = {'\0'};
    
    for (int i = 0; i < strlen(s); i++) {
        switch (s[i]) {
            case '(':
            case '{':
            case '[':
            case '<':
            stackPosition++;
            stack[stackPosition] = s[i];
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
    if (stackPosition == -1) {
        return true;
    }
    return false;
}

int main() {
    char string[SIZE];
    
    printf("Please enter a string(less or equal to 1000 characters): ");
    scanf("%s", string);
    
    if (isBalanced(string)) {
        printf("The sequence is balanced\n");
    }
    else {
        printf("The sequence isn't balanced\n");
    }
    return 0;
}


