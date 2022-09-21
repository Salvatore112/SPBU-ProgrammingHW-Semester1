#include <stdio.h>
#include <string.h>

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
    int check = 0;
    
    for(int i = 0; i < lengthS; i++)
    {
        check = 1;
        for(int j = 0; j < lengthS1; j++)
        {
            if(s[i+j]!=s1[j])
            {
                check = 0;
                break;
            }
        }
        if(check == 1)
        {
            counter++;
        }
    }
    
    printf("\nS includes S1 %d times!\n", counter);

    return 0;
}
