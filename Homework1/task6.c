#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char s[1000];
    char s1[1000];

    printf("Enter a string (No longer than 1000 characters): ");
    scanf("%s", s);
    printf("\nEnter a substring (No longer than 1000 characters): ");
    scanf("%s", s1);

    int lengthS = strlen(s);
    int lengthS1 = strlen(s1);
    int counter = 0;
    bool substringFound = false;

    for (int i = 0; i < lengthS - lengthS1 + 1; i++) {
        substringFound = true;
        for (int j = 0; j < lengthS1; j++) {
            if (s[i + j] != s1[j]) {
                substringFound = false;
                break;
            }
        }
        if (substringFound) {
            counter++;
        }
    }

    printf("\nS includes S1 %d times!\n", counter);

    return 0;
}
