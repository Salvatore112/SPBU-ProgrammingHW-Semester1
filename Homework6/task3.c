#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"
#include "stackTests.h"

#define size 1000

Node* infixToPostfix(char infixExpression[], int length);

int main() {
    if (!stackTests()) {
        return 1;
    }
    
    char infixExpression[size];
    printf("Enter an expression in a postfix form: ");
    scanf("%[^\n]", infixExpression);
    int length = strlen(infixExpression);

    Node* expression = infixToPostfix(infixExpression, length); 
    printf("Postfix form: ");
    displayStack(expression);
    
    return 0;
}

Node* infixToPostfix(char infixExpression[], int length) {
    Node *mainStack = NULL;
    Node *auxillaryStack = NULL;

    for (int i = 0; i < length; i++) {
        if (infixExpression[i] != ' ' && infixExpression[i] != '\0') {
            switch (infixExpression[i]) {
            case '(':
                push(&auxillaryStack, infixExpression[i]);  
                break;
            case ')':
                int errorCode = 0;
                while (peek(auxillaryStack) != '(') {
                    char character = peek(auxillaryStack);
                    push(&mainStack, character);
                    pop(&auxillaryStack, &errorCode);
                }
                pop(&auxillaryStack, &errorCode);
                break;
            case '*':
                if (peek(auxillaryStack) == '+' || peek(auxillaryStack) == '-' || peek(auxillaryStack) == '(', peek(auxillaryStack) == 'n') {
                    push(&auxillaryStack, infixExpression[i]);
                }
                else {
                    int errorCode = 0;
                    push(&mainStack, pop(&auxillaryStack, &errorCode));
                    push(&auxillaryStack, infixExpression[i]);
                } 
                break;
            case '+':
            case '-':
                if ((peek(auxillaryStack) != '*' && peek(auxillaryStack) != '/') || peek(auxillaryStack) == 'n') {
                    push(&auxillaryStack, infixExpression[i]);
                }
                else {
                    push(&mainStack, infixExpression[i]);
                }
                break;
            default:
                push(&mainStack, infixExpression[i]);
                break;
            }
        }
    }
    
    while (!isEmpty(auxillaryStack)) {
        int errorCode = 0;
        push(&mainStack, pop(&auxillaryStack, &errorCode));
    }
    
    Node *reversedStack = NULL;
    while (!isEmpty(mainStack)) {
        int errorCode;
        push(&reversedStack, pop(&mainStack, &errorCode));
    }
    return reversedStack;
}
