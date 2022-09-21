#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    int size = 0;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int temp = 0;
    int count = 0;
    
    for(int i = 0; i < size; i++)
    {
        printf("Enter the element #%d: ", i);
        scanf("%d", &temp);
        if(temp == 0)
        {
            count++;
        }
    }

    printf("You have %d zero elements within your array\n", count);
}
