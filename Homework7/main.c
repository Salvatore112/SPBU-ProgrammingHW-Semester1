#include <stdio.h>
#include <stdbool.h>
#include "LinkedList.h"

bool tests1();

int main() {
    if (!(tests1())) {
        return 1;
    }

    int n = 0;
    printf("Enter a number of warriors: ");
    scanf("%d", &n);
    while (n <= 0) {
        printf("Invalid input\n");
        printf("Enter a number of warriors: ");
        scanf("%d", &n);
    }
    int m = 0;
    printf("Enter a warrior who gets killed: ");
    scanf("%d", &m);
    while (m <= 0) {
        printf("Invalid input\n");
        printf("Enter a warrior who gets killed: ");
        scanf("%d", &m);
    }


    LinkedList *circle = createCircle(n);

    printf("The position to survive is %d\n", count(circle, m));

    return 0;
}

bool tests1() {
    LinkedList *test1 = createCircle(1);
    if (count(test1, 10) != 1) {
        printf("Failed when there's one warrior\n");
        return false;
    }

    LinkedList *test3 = createCircle(41);
    if (count(test3, 3) != 31) {
        printf("Failed on a regular test\n");
        return false;
    }
    return true;
}

