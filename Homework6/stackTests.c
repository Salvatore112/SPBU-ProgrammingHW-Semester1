#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

typedef struct Node 
{
    int element;
    struct Node *previous;
} Node;

bool pushTests()
{
    Node *testStack1 = NULL;
    push(&testStack1, 120);
    if (testStack1->element != 120)
    {
        printf("Push Failed on adding the first element");
        return false;
    }

    Node *testStack2 = NULL;
    push(&testStack2, 120);
    push(&testStack2, 180);
    push(&testStack2, 190);
    if (testStack2->element != 190)
    {
        printf("Push Failed on adding element (not the first)");
        return false;
    }
    return true;
}

bool popTests()
{
    Node *testStack1 = NULL;
    int errorCode1 = 0;
    pop(&testStack1, &errorCode1);
    if(errorCode1 != -1)
    {
        printf("Pop Failed when trying to pop an empty stack");
        return false;
    };

    Node *testStack2 = NULL;
    int errorCode2 = 0;
    push(&testStack2, 100);
    if(pop(&testStack2, &errorCode2) != 100)
    {
        printf("Pop Failed when trying to pop the first element");
        return false;
    };

    Node *testStack3 = NULL;
    int errorCode3 = 0;
    push(&testStack2, 100);
    push(&testStack2, 200);
    push(&testStack2, 300);
    push(&testStack2, 400);
    if(pop(&testStack2, &errorCode3) != 400)
    {
        printf("Pop Failed when trying to pop some element");
        return false;
    };
    return true;
};

bool isEmptyTests()
{
    Node *testStack1 = NULL;
    if (isEmpty(testStack1) == false)
    {
        printf("IsEmpty failed on an empty stack");
        return false;
    } 
    Node *testStack2 = NULL;
    push(&testStack2, 100);
    if (isEmpty(testStack2) != false)
    {
        printf("IsEmpty failed on not an empty stack");
        return false;
    }
    return true;
}

bool peekTests()
{
    Node *testStack1 = NULL;
    if(peek(testStack1) != 0)
    {
        printf("peek failed on trying to peek an empty stack");
        return false;
    };  

    Node *testStack2 = NULL;
    push(&testStack2, 100);
    if(peek(testStack2) != 100)
    {
        printf("peek failed on trying to peek a stack of one element");
        return false;
    };

    Node *testStack3 = NULL;
    push(&testStack3, 100);
    push(&testStack3, 200);
    push(&testStack3, 300);
    if(peek(testStack3) != 300)
    {
        printf("peek failed on trying to peek a stack of more than one element");
        return false;
    };
    return true;
}

bool clearTests()
{
    Node *testStack1 = NULL;
    clear(&testStack1);
    if(peek(testStack1) != 0)
    {
        printf("Clear failed on an empty stack");
        return false;
    }

    Node *testStack2 = NULL;
    push(&testStack2, 1000);
    push(&testStack2, 2000);
    push(&testStack2, 3000);
    clear(&testStack2);
    if(peek(testStack2) != 0)
    {
        printf("Clear failed on an empty stack");
        return false;
    }
    return true;
}

bool stackTests()
{
    return clearTests() && pushTests() && popTests() && isEmptyTests() && peekTests();
}