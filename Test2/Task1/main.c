#include <stdio.h>
#include <stdbool.h>
#include "linkedList.h"

bool tests();

int main() {
    if (!tests()) {
        return 1;
    }
    FILE* file = fopen("input.txt", "r");
    LinkedList* list = createList();
    int number = 0;
    int index = 0;
    while (!feof(file)) {
        fscanf(file, "%d", &number);
        insert(number, index, list);
        index++;
    }
    isSymmetrical(list) ? printf("The list is symmetrical") : printf("The list is not symmetrical");
    deleteList(list);
    fclose(file);
    return 0;
}
//10 20 30 40 20 10
bool tests() {
    LinkedList* testList1 = createList();
    insert(10, 0, testList1);
    insert(20, 1, testList1);
    insert(30, 2, testList1);
    insert(20, 3, testList1);
    insert(10, 4, testList1);
    if (!isSymmetrical(testList1)) {
        printf("Test failed on the first example array");
        return false;
    }

    LinkedList* testList2 = createList();
    insert(10, 0, testList2);
    insert(20, 1, testList2);
    insert(30, 2, testList2);
    insert(40, 3, testList2);
    insert(20, 4, testList2);
    insert(10, 5, testList2);
    if (isSymmetrical(testList2)) {
        printf("Test failed on the second example array");
        return false;
    }

    LinkedList* testList3 = createList();
    insert(5, 0, testList3);
    insert(5, 1, testList3);
    insert(5, 2, testList3);
    insert(5, 3, testList3);
    insert(5, 4, testList3);
    insert(5, 5, testList3);
    if (!isSymmetrical(testList3)) {
        printf("Test failed on an array of the same element");
        return false;
    }
    deleteList(testList1);
    deleteList(testList2);
    deleteList(testList3);
    return true;
}