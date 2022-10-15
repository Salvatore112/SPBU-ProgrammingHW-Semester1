#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

typedef struct Node 
{
    int element;
    struct Node *previous;
} Node;

void test()
{
    printf("ww");
}

int push(Node **head, int element)
{
    Node *temp = malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Out of memory");
        return -1;
    }
    temp->element = element;
    temp->previous = *head;
    *head = temp;
    return (*head)->element;
}

int pop(Node **head, int *errorCode)
{
    if (*head == NULL)
    {
        *errorCode = -1;
        return 0;
    }
    *errorCode = 0;
    int value = (*head)->element;

    Node *temp;
    temp = (*head)->previous;
    free(*head);
    (*head) = temp;
    return value;
}

bool isEmpty(Node *head)
{
    return head == NULL;
} 

int peek(Node *head)
{
    if(isEmpty(head))
    {
        return 0;
    }
    return head->element;
}

void clear(Node **head)
{
    while (!isEmpty(*head))
    {
        int errorCode = 0;
        pop(head, &errorCode);
        if (errorCode < 0)
        {
            break;
        }
    }
}
