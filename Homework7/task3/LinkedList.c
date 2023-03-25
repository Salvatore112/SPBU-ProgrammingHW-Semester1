#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "LinkedList.h"

typedef struct Node
{
    int number;
    char *name;
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
    while (temp->next != NULL) {
        printf("%s ", temp->name);
        printf("%d \n", temp->number);
        temp = temp->next;
    }
    printf("%s ", temp->name);
    printf("%d \n", temp->number);
}

bool isSorted(LinkedList *linkedList, bool byName) {
    if (byName) {
        Node *temp = linkedList->head;
        while (temp->next != NULL) {
            if (strcmp(temp->name, temp->next->name) > 0 ) {
                return false;
            }
            temp = temp->next;
        }
        return true;
    }
    else {
        Node *temp = linkedList->head;
        while (temp->next != NULL) {
            if (temp->number > temp->next->number) {
                return false;
            }
            temp = temp->next;
        }
        return true;
    }
}

void insert(int value, char *name, int index, LinkedList *linkedList) {
    Node *temp1 = malloc(sizeof(Node));
    if (temp1 == NULL) {
        printf("Out of memory\n");
        exit(1);
    }
    temp1->number = value;
    temp1->name = name;
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

void mergeSort(LinkedList *linkedList, bool byName) {
    mergeSortRecursion (&(linkedList->head), byName);
}

void mergeSortRecursion(Node **head, bool byName) {
    if ((*head) == NULL || (*head)->next == NULL) {
        return;
    }

    Node *front;
    Node *back;
    split(*head, &front, &back);

    mergeSortRecursion(&front, byName);
    mergeSortRecursion(&back, byName);
    *head = mergeSortedLists(front, back, byName);
}

void split(Node *head, Node **front, Node **back) {
    int length = 0;
    Node *count = head;
    while (count->next != NULL) {
        count = count->next;
    }

    Node *temp = head;
    for (int i = 0; i < length/2 - 1; i++) {
        temp = temp->next;
    }
    *front = temp->next;
    *back = head;
    temp->next = NULL;
}

Node* mergeSortedLists(Node *front, Node *back, bool byName) {
    Node *temp = NULL;

    if (front == NULL) {
        return back;
    }
    if (back == NULL) {
        return front;
    }

    if (byName) {
        if (strcmp(front->name, back->name) < 0) {
            temp = front;
            temp->next = mergeSortedLists(front->next, back, byName);
        }
        else {
            temp = back;
            temp->next = mergeSortedLists(front, back->next, byName);
        }
        return temp;
    }
    else {
        if (front->number <= back->number) {
            temp = front;
            temp->next = mergeSortedLists(front->next, back, byName);
        }
        else {
            temp = back;
            temp->next = mergeSortedLists(front, back->next, byName);
        }
        return temp;
    }
}

void deleteList(LinkedList *list) {
    Node *temp = list->head;
    while (temp != NULL) {
        free(temp->name);
        free(temp->next);
        temp = temp->next;
    }
    free(temp);
}
