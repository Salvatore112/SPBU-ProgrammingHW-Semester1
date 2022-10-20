#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"
#include "stackTests.h"

bool pushTests() {
    Node *testStack1 = NULL;
    
    push(&testStack1, "244");
    char* testElement1 = testStack1->element;
    if (testElement1 != "244") {
        printf("Push Failed on adding the first element");
        return false;
    } 

    Node *testStack2 = NULL;
    push(&testStack2, "112");
    push(&testStack2, "233");
    push(&testStack2, "754");
    char* testElement2 = testStack2->element;
    if (testElement2 != "754") {
        printf("Push Failed on adding element (not the first)");
        return false;
    }
    return true;
}

bool popTests() {
    Node *testStack1 = NULL;
    int errorCode1 = 0;
    pop(&testStack1, &errorCode1);
    if (errorCode1 != -1) {
        printf("Pop Failed when trying to pop an empty stack");
        return false;
    };

    Node *testStack2 = NULL;
    int errorCode2 = 0;
    push(&testStack2, "800");
    if (pop(&testStack2, &errorCode2) != "800") {
        printf("Pop Failed when trying to pop the first element");
        return false;
    };

    Node *testStack3 = NULL;
    int errorCode3 = 0;
    push(&testStack2, "200");
    push(&testStack2, "244");
    push(&testStack2, "5251");
    push(&testStack2, "52");
    if (pop(&testStack2, &errorCode3) != "52") {
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
    push(&testStack2, "621");
    if (isEmpty(testStack2) != false) {
        printf("IsEmpty failed on not an empty stack");
        return false;
    }
    return true;
}

bool peekTests() {
    Node *testStack1 = NULL;
    if (strcmp(peek(testStack1), "Empty") != 0) {
        printf("peek failed on trying to peek an empty stack");
        return false;
    };  

    Node *testStack2 = NULL;
    push(&testStack2, "214");
    if (peek(testStack2) != "214") {
        printf("peek failed on trying to peek a stack of one element");
        return false;
    };

    Node *testStack3 = NULL;
    push(&testStack3, "124");
    push(&testStack3, "457");
    push(&testStack3, "325");
    if (peek(testStack3) != "325") {
        printf("peek failed on trying to peek a stack of more than one element");
        return false;
    };
    return true;
}

bool clearTests() {
    Node *testStack1 = NULL;
    clear(&testStack1);

    if (strcmp(peek(testStack1), "Empty") != 0) {
        printf("Clear failed on an empty stack");
        return false;
    }

    Node *testStack2 = NULL;
    push(&testStack2, "92");
    push(&testStack2, "92");
    push(&testStack2, "442");
    clear(&testStack2);
    if (strcmp(peek(testStack2), "Empty") != 0) {
        printf("Clear failed");
        return false;
    }
    return true;
}

bool stackTests() {
    return clearTests() && pushTests() && popTests() && isEmptyTests() && peekTests();
}
