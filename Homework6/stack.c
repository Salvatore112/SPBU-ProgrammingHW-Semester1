#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

char push(Node **head, char element) {
    Node *temp = malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Out of memory");
        return -1;
    }
    temp->element = element;
    temp->previous = *head;
    *head = temp;
    return (*head)->element;
}

char pop(Node **head, int *errorCode) {
    if (*head == NULL) {
        *errorCode = -1;
        return 0;
    }
    *errorCode = 0;
    char value = (*head)->element;

    Node *temp;
    temp = (*head)->previous;
    free(*head);
    (*head) = temp;
    return value;
}

bool isEmpty(Node *head) {
    return head == NULL;
} 

char peek(Node *head) {
    if (isEmpty(head)) {
        return 'n';
    }
    return head->element;
}

void clear(Node **head) {
    while (!isEmpty(*head)) {
        int errorCode = 0;
        pop(head, &errorCode);
        if (errorCode < 0) {
            break;
        }
    }
}


void deleteStack(Node* head) {
    if (head == NULL) {
        return;
    }
    Node* current = head;
    Node* next = NULL;
    while (current->previous != NULL) {
        next = current->previous;
        free(current);
        current = next;
    }
    free(next);
}

void displayStack(Node *stack) {
    Node *temp = stack;
    while (!isEmpty(temp)) {
        int errorCode = 0;
        printf("%c ", pop(&temp, &errorCode));
    }
}

const char* printStack(Node *stack) {
    char* input = malloc(100 *sizeof(char));
    Node *temp = stack;
    int i = 0;
    while (temp->previous != NULL) {
        input[i] = temp->element;
        temp = temp->previous;
        i++;
    }
    input[i] = temp->element;
    input[i + 1] = '\0';
    return input;
}
