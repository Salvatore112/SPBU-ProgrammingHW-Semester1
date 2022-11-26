#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
} LinkedList;

void printList(LinkedList *linkedList) {
    Node *temp = linkedList->head;
    if (temp == NULL) {
        printf("The list is empty!\n");
        return;
    }
    printf("The list is: ");
    while (temp->next != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
    printf("\n");
}

void insert(int value, LinkedList *linkedList) {
    Node *temp1 = malloc(sizeof(Node));
    if (temp1 == NULL) {
        printf("Out of memory\n");
        exit(1);
    }
    temp1->data = value;
    temp1->next = NULL;
    if (linkedList->head == NULL) {
        linkedList->head = temp1;
    } else {
        temp1->next = linkedList->head->next;
        linkedList->head->next = temp1;
    }
}

LinkedList* createList() {
    LinkedList *linkedlist = malloc(sizeof(LinkedList));
    linkedlist->head = NULL;
    return linkedlist;
}

int listLength(LinkedList* linkedList) {
    Node* temp = linkedList->head;
    int length = 1;
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }
    return length;
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