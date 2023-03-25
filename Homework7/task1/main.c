#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"
#include "LinkedListTests.h"

void options();

int main() {
    if (!tests()) {
        return 1;
    }

    int choice = 0;
    LinkedList *sortedList = createList();

    do {
        options();
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                printf("Exiting...\n");
                return 0;
            case 1:
                int value1 = 0;
                printf("Enter a value you want to add: ");
                scanf("%d", &value1);
                orderInsert(value1, sortedList);
                break;
            case 2:
                int value2 = 0;
                printf("Enter a value you want to delete: ");
                scanf("%d", &value2);
                if(!deleteViaValue(sortedList, value2)) {
                    printf("There's no such a value on the list!\n");
                };
                break;
            case 3:
                printList(sortedList);
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    } while (choice != 0);
}

void options() {
    printf("Sorted list Options\n");
    printf("0 - Exit\n");
    printf("1 - Add a value to the sorted list\n");
    printf("2 - Delete a value from the list\n");
    printf("3 - Print the list\n");
    printf("Enter a corresponding digit to choose an option: ");
}
