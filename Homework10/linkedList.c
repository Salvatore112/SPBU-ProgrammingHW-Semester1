#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "LinkedList.h"

typedef struct Node
{
    char *word;
    int frequency;
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
        printf("%s ", temp->word);
        temp = temp->next;
    }
    printf("%s ", temp->word);
    printf("\n");
}

void listInsertBeginning(char* word, LinkedList *linkedList) {
    Node* temp = malloc(sizeof(Node));
    temp->word = word;
    temp->frequency = 1;
    temp->next = NULL;
    if (linkedList->head != NULL) {
        temp->next = linkedList->head;
        linkedList->head = temp;
    } else {
        linkedList->head = temp;
    }
}

LinkedList* createList() {
    LinkedList *linkedlist = malloc(sizeof(LinkedList));
    linkedlist->head = NULL;
    return linkedlist;
}

int getFrequency(LinkedList* linkedList) {
    return linkedList->head->frequency;
}

bool isEmpty(LinkedList* linkedList) {
    return linkedList == NULL;
}

const char* getWord(LinkedList* linkedList) {
    return linkedList->head->word;
}

bool listTraverse(LinkedList* linkedList) {
    if (linkedList->head->next == NULL) {
        return true;
    }
    linkedList->head = linkedList->head->next;
    return false;
}

bool isInTheList(LinkedList* linkedList, char* word) {
    Node* temp = linkedList->head;
    while (temp != NULL) {
        if (strcmp(word, temp->word) == 0) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void incrementFrequency(LinkedList* linkedList, char* word) {
    Node* temp = linkedList->head;
    while (temp != NULL) {
        if (strcmp(word, temp->word) == 0) {
            temp->frequency++;
            return;
        }
    }
}

void conveyFrequency(LinkedList* linkedList, char* word, int newFrequency) {
    Node* temp = linkedList->head;
    while (temp != NULL) {
        if (strcmp(word, temp->word) == 0) {
            temp->frequency = newFrequency;
            return;
        }
    }
}

int listLength(LinkedList* linkedList) {
    if (linkedList == NULL) {
        return 0;
    }
    Node* temp = linkedList->head;
    int length = 1;
    while(temp->next != NULL) {
        temp = temp->next;
        length++;
    }
    return length;
}
