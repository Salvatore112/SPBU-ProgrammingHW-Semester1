#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"
#include "stackTests.h"

bool pushTests() {
    Node *testStack1 = NULL;
    
    push(&testStack1, 'q');
    char testElement1 = testStack1->element;
    if (testElement1 != 'q') {
        printf("Push Failed on adding the first element");
        return false;
    } 

    Node *testStack2 = NULL;
    push(&testStack2, 'w');
    push(&testStack2, 'g');
    push(&testStack2, 'f');
    char testElement2 = testStack2->element;
    if (testElement2 != 'f') {
        printf("Push Failed on adding element (not the first)");
        return false;
    }
    return true;
}

bool popTests() {
    Node *testStack1 = NULL;
    int errorCode1 = 0;
    pop(&testStack1, &errorCode1);
    if(errorCode1 != -1) {
        printf("Pop Failed when trying to pop an empty stack");
        return false;
    };

    Node *testStack2 = NULL;
    int errorCode2 = 0;
    push(&testStack2, 'h');
    if (pop(&testStack2, &errorCode2) != 'h') {
        printf("Pop Failed when trying to pop the first element");
        return false;
    };

    Node *testStack3 = NULL;
    int errorCode3 = 0;
    push(&testStack2, 'w');
    push(&testStack2, 'e');
    push(&testStack2, 'r');
    push(&testStack2, 't');
    if(pop(&testStack2, &errorCode3) != 't') {
        printf("Pop Failed when trying to pop some element");
        return false;
    };
    return true;
};

bool isEmptyTests() {
    Node *testStack1 = NULL;
    if (isEmpty(testStack1) == false) {
        printf("IsEmpty failed on an empty stack");
        return false;
    } 
    Node *testStack2 = NULL;
    push(&testStack2, 'k');
    if (isEmpty(testStack2) != false) {
        printf("IsEmpty failed on not an empty stack");
        return false;
    }
    return true;
}

bool peekTests() {
    Node *testStack1 = NULL;
    if (peek(testStack1) != '0') {
        printf("peek failed on trying to peek an empty stack");
        return false;
    };  

    Node *testStack2 = NULL;
    push(&testStack2, 'o');
    if (peek(testStack2) != 'o') {
        printf("peek failed on trying to peek a stack of one element");
        return false;
    };

    Node *testStack3 = NULL;
    push(&testStack3, 'i');
    push(&testStack3, 'j');
    push(&testStack3, 'v');
    if (peek(testStack3) != 'v') {
        printf("peek failed on trying to peek a stack of more than one element");
        return false;
    };
    return true;
}

bool clearTests()
{
    Node *testStack1 = NULL;
    clear(&testStack1);
    if (peek(testStack1) != '0') {
        printf("Clear failed on an empty stack");
        return false;
    }

    Node *testStack2 = NULL;
    push(&testStack2, '9');
    push(&testStack2, '2');
    push(&testStack2, '4');
    clear(&testStack2);
    if (peek(testStack2) != '0') {
        printf("Clear failed");
        return false;
    }
    return true;
}

bool stackTests() {
    return clearTests() && pushTests() && popTests() && isEmptyTests() && peekTests();
}
