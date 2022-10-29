#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"

bool tests();

int main() {
    if (!tests()) {

        return 1;
    }

    FILE *file = fopen("D:\\Homework7Task3\\dataBase.txt", "r");
    if (file == NULL) {
        printf("Couldn't find the file\n");
        return 1;
    }

    LinkedList *dictionary = createList();

    int i = 0;
    while (!feof(file)) {
        char *bufferName = malloc(sizeof(char) * 100);
        if (bufferName == NULL) {
            printf("Out of memory!\n");
            return 1;
        }
        char *hyphen = malloc(sizeof(char) * 2);
        if (hyphen == NULL) {
            printf("Out of memory!\n");
            return 1;
        }
        char *bufferNumber = malloc(sizeof(char) * 100);
        if (bufferNumber == NULL) {
            printf("Out of memory!\n");
            return 1;
        }
        fscanf(file, "%s", bufferName);
        fscanf(file, "%s", hyphen);
        fscanf(file, "%s", bufferNumber);
        int newNumber = atoi(bufferNumber);
        insert(newNumber, bufferName, i, dictionary);
        i++;
    }

    bool choice = 0;

    printf("How would you like to sort entries?\n");
    printf("0 - sort by a telephone number\n");
    printf("1 - sort by a name\n");
    printf("Enter a corresponding digit to choose:");
    scanf("%d", &choice);
    if (choice == 1) {
        mergeSort(dictionary, true);
    }
    else {
        mergeSort(dictionary, false);
    }

    printList(dictionary);
    deleteList(dictionary);
    fclose(file);
    return 0;
}

bool tests() {
    LinkedList *testList1 = createList();
    insert(734, "Harry", 0, testList1);
    insert(241, "Matthew", 1, testList1);
    insert(333, "Simon", 2, testList1);
    insert(2, "Oliver", 3, testList1);
    insert(11, "Richard", 4, testList1);
    mergeSort(testList1, false);
    if (!isSorted(testList1, false)) {
        printf("Failed on sorting by a number\n");
        return false;
    }
    mergeSort(testList1, true);
    if (!isSorted(testList1, true)) {
        printf("Failed on sorting by a name\n");
        return false;
    }

    LinkedList *testList2 = createList();
    
    insert(555, "Tom", 0, testList2);
    insert(555, "Tom", 1, testList2);
    insert(555, "Tom", 2, testList2);
    insert(555, "Tom", 3, testList2);
    insert(555, "Tom", 4, testList2);
    mergeSort(testList2, false);
    if (!isSorted(testList2, false)) {
        printf("Failed on sorting by a number (all elements are the same)\n");
        return false;
    }
    mergeSort(testList2, true);
    if (!isSorted(testList2, true)) {
        printf("Failed on sorting by a name (all elements are the same)\n");
        return false;
    }
    
    LinkedList *testList3 = createList();

    insert(22222, "Zack", 0, testList3);
    insert(2222, "Walter", 1, testList3);
    insert(222, "Coef", 2, testList3);
    insert(22, "Bob", 3, testList3);
    insert(2, "Alex", 4, testList3);
    mergeSort(testList3, false);
    if (!isSorted(testList3, false)) {
        printf("Failed on sorting by a number (list is reversed)\n");
        return false;
    }
    mergeSort(testList3, true);
    if (!isSorted(testList3, true)) {
        printf("Failed on sorting by a name (list is reversed)\n");
        return false;
    }
    return true;
}

