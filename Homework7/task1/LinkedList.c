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

void orderInsert(int value, LinkedList *linkedList) {
    Node *temp = linkedList->head;
    if (temp == NULL) {
        insert (value, 0, linkedList);
        return;
    }
    int i = 0;
    while (temp->data < value) {
        temp = temp->next;
        i++;
        if (temp == NULL) {
            insert(value, i, linkedList);
            return;
        }
    }

    insert(value, i, linkedList);
}

void deleteViaIndex(LinkedList *linkedList, int index) {
    Node *temp1 = linkedList->head;
    if (index == 0) {
        linkedList->head = temp1->next;
        free(temp1);
        return;
    }
    for (int i = 0; i < index - 1; i++) {
        temp1 = temp1->next;
    }
    Node *temp2 = temp1->next;
    if (temp2 == NULL) {
        free(temp1);
    }
    temp1->next = temp2->next;
    free(temp2);
}

bool deleteViaValue(LinkedList *linkedList, int value) {
    Node *temp = linkedList->head;
    int i = 0;
    while (temp->data != value) {
        i++;
        temp = temp->next;
        if (temp == NULL) {
            return false;
        }
    }
    deleteViaIndex(linkedList, i);
    return true;
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













