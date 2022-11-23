#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedList.h"

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
} LinkedList;

void insert(int value, int index, LinkedList *linkedList) {
    Node *temp1 = malloc(sizeof(Node));
    if (temp1 == NULL) {
        printf("Out of memory\n");
        exit(1);
    }
    temp1->data = value;
    temp1->next = NULL;
    if (index == 0) {
        temp1->next = linkedList->head;
        linkedList->head = temp1;
        return;
    }
    Node *temp2 = linkedList->head;
    for (int i = 0; i < index - 1; i++) {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

LinkedList* createList() {
    LinkedList *linkedlist = malloc(sizeof(LinkedList));
    linkedlist->head = NULL;
    return linkedlist;
}

int accessElement(int index, LinkedList *linkedList) {
    Node *temp = linkedList->head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("Error: index out of range\n");
            exit(1);
        }
    }
    return temp->data;
}

int listLength(LinkedList* linkedList) {
    if (linkedList->head == NULL) {
        return 0;
    }
    int length = 1;
    Node* temp = linkedList->head;
    while (temp->next != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

bool isSymmetricalRecursion(LinkedList* linkedList, int length, int index) {
    if (index > length/2) {
        return true;
    }
    if (accessElement(index, linkedList) != accessElement(length - 1 - index, linkedList)) {
        return false;
    }
    return isSymmetricalRecursion(linkedList, length, index + 1);
}

bool isSymmetrical(LinkedList* list) {
    return isSymmetricalRecursion(list, listLength(list), 0);
}

void deleteList(LinkedList* linkedList) {
    Node* current = linkedList->head;
    Node* temp = NULL;
    while (current != NULL) {
        temp = current->next;
        free(current);
        current = temp;
    }
    linkedList->head = NULL;
}