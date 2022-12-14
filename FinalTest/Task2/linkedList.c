#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "LinkedList.h"

typedef struct Node {
    char* data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
} LinkedList;

bool endInsert(char* data, LinkedList *linkedList) {
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

int listLength (LinkedList* linkedList) {
    Node* temp = linkedList->head;
    int count = 1;
    while (temp->next != NULL) {
        count += 1;
        temp = temp->next;
    }
    return count;
}

void addAStrings(LinkedList* linkedList) {
    int length = listLength(linkedList);
    int i = 0;
    Node* temp = linkedList->head;
    while (i < length) {
        if (temp->data[0] == 'a') {
            endInsert(temp->data, linkedList);
        }
        temp = temp->next;
        i++;
    }
}

bool listsTheSame(LinkedList *linkedList1, LinkedList* linkedList2) {
    Node* head1 = linkedList1->head;
    Node* head2 = linkedList2->head;
    while (head1->next != NULL && head2->next != NULL) {
        if (strcmp(head1->data, head2->data) != 0) {
            return false;
        }
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    return (head1->next == NULL && head2->next == NULL) ? true : false;
}