#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
} LinkedList;

void printToFile(LinkedList* linkedList, FILE* file) {
    Node *temp = linkedList->head;
    if (temp == NULL) {
        return;
    }

    while (temp->next != NULL) {
        fprintf(file, "%d ", temp->data);
        temp = temp->next;
    }
    fprintf(file, "%d ", temp->data);
}

bool endInsert(int data, LinkedList *linkedList) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (newNode == NULL) {
        return 1;
    }
    if (linkedList->head == NULL) {
        linkedList->head = newNode;
    } else {
        Node* lastNode = linkedList->head;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
    return 0;
}

LinkedList* createList(bool *errorCode) {
    LinkedList *linkedlist = malloc(sizeof(LinkedList));
    if (linkedlist == NULL) {
        *errorCode = 1;
        return NULL;
    }
    linkedlist->head = NULL;
    return linkedlist;
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