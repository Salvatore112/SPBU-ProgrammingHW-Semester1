#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"
#include "LinkedListTests.h"

bool accessElementTests() {
    LinkedList *testList1 = createList();
    orderInsert(21, testList1);
    orderInsert(52, testList1);
    orderInsert(24, testList1);
    if (accessElement(0, testList1) != 21 || accessElement(1, testList1) != 24 || accessElement(2, testList1) != 52) {
        printf("accessElement failed");
        return false;
    }
    return true;
}

bool deleteViaValueTests() {
    LinkedList *testList1 = createList();
    orderInsert(10, testList1);
    orderInsert(20, testList1);
    orderInsert(30, testList1);
    deleteViaValue(testList1, 10);
    if (accessElement(0, testList1) != 20) {
        printf("deleteViaValueTests failed on deleting the first element\n");
        return false ;
    }

    LinkedList *testList2 = createList();
    orderInsert(10, testList2);
    orderInsert(20, testList2);
    orderInsert(30, testList2);
    deleteViaValue(testList2, 20);
    if (accessElement(0, testList2) != 10 || accessElement(1, testList1) != 30) {
        printf("deleteViaValueTests failed on deleting the middle element\n");
        return false ;
    }

    LinkedList *testList3 = createList();
    orderInsert(10, testList3);
    orderInsert(20, testList3);
    orderInsert(30, testList3);
    deleteViaValue(testList3, 30);
    if (accessElement(1, testList3) != 20 || accessElement(0, testList3) != 10) {
        printf("deleteViaindexTests failed on deleting the last\n");
        return false;
    }
    return true;
}

bool deleteViaindexTests() {
    LinkedList *testList1 = createList();
    orderInsert(10, testList1);
    orderInsert(20, testList1);
    orderInsert(30, testList1);
    deleteViaIndex(testList1, 0);
    if (accessElement(0, testList1) != 20) {
        printf("deleteViaindexTests failed on deleting the first element\n");
        return false ;
    }

    LinkedList *testList2 = createList();
    orderInsert(10, testList2);
    orderInsert(20, testList2);
    orderInsert(30, testList2);
    deleteViaIndex(testList2, 1);
    if (accessElement(0, testList2) != 10 || accessElement(1, testList2) != 30) {
        printf("deleteViaindexTests failed on deleting the middle element\n");
        return false ;
    }

    LinkedList *testList3 = createList();
    orderInsert(10, testList3);
    orderInsert(20, testList3);
    orderInsert(30, testList3);
    deleteViaIndex(testList3, 2);
    if (accessElement(1, testList3) != 20 || accessElement(0, testList3) != 10) {
        printf("deleteViaindexTests failed on deleting the last\n");
        return false;
    }
    return true;
}

bool insertTests() {
    LinkedList *testList1 = createList();
    insert(100, 0, testList1);
    insert(200, 1, testList1);
    insert(300, 2, testList1);
    if (!(accessElement(0, testList1) == 100 && accessElement(1, testList1) == 200 && accessElement(2, testList1) == 300)) {
        printf("Insert failed");
        return false;
    }
    return true;
}

bool orderInsertTests() {
    LinkedList *testList1 = createList();
    orderInsert(10000, testList1);
    orderInsert(25, testList1);
    orderInsert(0, testList1);
    if (!(accessElement(0, testList1) == 0 && accessElement(1, testList1) == 25 && accessElement(2, testList1) == 10000)) {
        printf("orderInsert failed");
        return false;
    }
    return true;
}

bool tests() {
    if (!(accessElementTests() && deleteViaValueTests() && insertTests() && orderInsertTests())) {
        return false;
    }
    return true;
}