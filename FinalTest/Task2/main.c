#include <stdio.h>
#include "linkedList.h"

bool tests();

int main(void) {
    if (!tests()) {
        return 1;
    }
    int errorCode = 0;
    LinkedList* newList = createList(&errorCode);
    endInsert("aa", newList);
    endInsert("ab", newList);
    endInsert("c", newList);
    addAStrings(newList);
    return 0;
}

bool tests() {
    int errorCode = 0;
    LinkedList* testList1 = createList(&errorCode);
    LinkedList* expectedList = createList(&errorCode);
    if (errorCode < 0) {
        printf("Memory allocation error\n");
        return false;
    }
    endInsert("a", testList1);
    endInsert("b", testList1);
    endInsert("c", testList1);
    addAStrings(testList1);

    endInsert("a", expectedList);
    endInsert("b", expectedList);
    endInsert("c", expectedList);
    endInsert("a", expectedList);
    if (!listsTheSame(testList1, expectedList)) {
        printf("Tests failed on the example list");
        deleteList(testList1);
        deleteList(expectedList);
        return false;
    }
    deleteList(testList1);
    deleteList(expectedList);
    return true;
}
