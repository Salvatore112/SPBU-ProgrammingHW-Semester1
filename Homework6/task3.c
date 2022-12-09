#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "stackTests.h"

#define SIZE 1000

Node* infixToPostfix(char infixExpression[]);
bool tests();

int main() {
    if (!tests() || !stackTests()) {
        return 1;
    }
    
    char infixExpression[SIZE] = { 0 };

    printf("Enter an expression in a postfix form: ");
    scanf("%[^\n]", infixExpression);

    Node* expression = infixToPostfix(infixExpression);
    printf("Postfix form: ");
    displayStack(expression);
    
    return 0;
}
// 1 * 2 + 3 * 4
Node* infixToPostfix(char infixExpression[]) {
    int length = strlen(infixExpression);
    Node *mainStack = NULL;
    Node *auxillaryStack = NULL;

    for (int i = 0; i < length; i++) {
        if (infixExpression[i] != ' ' && infixExpression[i] != '\0') {
            switch (infixExpression[i]) {
            case '(':
                push(&auxillaryStack, infixExpression[i]);  
                break;
            case ')': {
                int errorCode = 0;
                while (peek(auxillaryStack) != '(') {
                    char character = peek(auxillaryStack);
                    push(&mainStack, character);
                    pop(&auxillaryStack, &errorCode);
                }
                pop(&auxillaryStack, &errorCode);
                break;
            }
            case '*':
            case '/':
                if (peek(auxillaryStack) == '+' || peek(auxillaryStack) == '-' || peek(auxillaryStack) == '(' ||
                            peek(auxillaryStack) == 'n') {
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
                    int errorCode = 0;
                    push(&mainStack, pop(&auxillaryStack, &errorCode));
                    push(&auxillaryStack, infixExpression[i]);
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
        int errorCode = 0;
        push(&reversedStack, pop(&mainStack, &errorCode));
    }
    return reversedStack;
}

bool tests() {
    char* testExpression1 = "1 * 2 + 3 * 4";
    char* expectedExpression = "12*34*+";
    Node* testStack1 = infixToPostfix(testExpression1);
    const char* outputExpression = printStack(testStack1);
    return strcmp(outputExpression, expectedExpression) == 0;
}
