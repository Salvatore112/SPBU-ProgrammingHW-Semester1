#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"
#include "stackTests.h"

bool isBalanced(char string[], int length);
bool closedBracket(Node **stack, char openBracket);
bool tests();

int main() {
    if(!(tests() && stackTests())) {
        return 1;
    }
    
    int size = 0;
    
    printf("Enter the size of the string:");
    scanf("%d", &size);
    while (size <= 0) {
        printf("Invalid input, enter a natural number!\n");
        printf("Enter the size of the string:");
        scanf("%d", &size);
    }
    
    char *string = malloc(size * sizeof(char));
    if (string == NULL) {
        printf("Out of memory\n");
        return 1;
    }
    for (int i = 0; i < size; i++) {
        printf("Enter the element #%d (one of the following brackets '({[]})': ", i);
        scanf("%c", &string[i]);
        scanf("%c");
    }

    if (isBalanced(string, size)) {
        printf("The string is balanced\n");
    }
    else {
        printf("The string is not balanced\n");
    }
    free(string);
}

bool isBalanced(char string[], int length) {
    Node *stack = NULL;
    for (int i = 0; i < length; i++) {
        switch (string[i]) {
            case '(':
            case '[':
            case '{':
                push(&stack, string[i]);
                break;
            case ')':
                if(!(closedBracket(&stack, '(')))
                {
                    return false;
                }
                break;
            case ']':
                if(!(closedBracket(&stack, '[')))
                {
                    return false;
                }
                break;
            case '}':
                if(!(closedBracket(&stack, '{')))
                {
                    return false;
                }
                break;
        }
    }
    
    if (peek(stack) == '0') {
        return true;
    }
    return false;
}

bool closedBracket(Node **stack, char openBracket) {
    if (peek(*stack) == openBracket) {
        int errorCode = 0;
        pop(&(*stack), &errorCode);
        return true;
    }
    return false;
}

bool tests() {
    char testString1[] = "({)}";
    if (isBalanced(testString1, 4)) {
        printf("Failed on the example string\n");
        return false;
    }
    char testString2[] = "({})";
    if (!isBalanced(testString2, 4)) {
        printf("Failed on the example string\n");
        return false;
    }
    char testString3[] = "(((())";
    if (isBalanced(testString3, 6)) {
        printf("Failed when there are remaining brackets on the stack\n");
        return false;
    }
    char testString4[] = "(())))";
    if (isBalanced(testString4, 6)) {
        printf("Failed when there are too many brackets to be removed from the stack\n");
        return false;
    }
    char testString5[] = "[({[()]})]";
    if (!isBalanced(testString5, 10)) {
        printf("Failed when there are all kinds of brackets\n");
        return false;
    }
    char testString6[] = "[({[{()]})]";
    if (isBalanced(testString6, 11)) {
        printf("Failed when there are all kinds of brackets\n");
        return false;
    }
    return true;
}
