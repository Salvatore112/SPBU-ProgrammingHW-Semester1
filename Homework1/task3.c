#include <stdio.h>
#include <stdlib.h>

void display(int ar[], int size);
void reverse(int array[], int begining, int end);

int main()
{
    int m = 0;
    int n = 0;

    printf("Enter the size of the first array: ");
    scanf("%d", &m);
    printf("Enter the size of the second array: ");
    scanf("%d", &n);

    int *array = malloc( (m + n) * sizeof(int));

    for (int i = 0; i < m + n; i++)
    {
        printf("Enter the element #%d: ", i);
        scanf("%d", &array[i]);
    }

    reverse(array, 0, m + n);
    
    reverse(array, 0, n);

    reverse(array, n, n + m);
    
    display(array, m + n);
}

void reverse(int array[], int begining, int end)
{
    int tempVal;
    
    for (int i = begining; i < (end + begining) / 2; i++)
    {
        tempVal = array[i];
        array[i] = array[(end + begining) - i - 1];
        array[(end + begining) - i - 1] = tempVal;
    }
}

void display(int array[], int size)
{
    for (int j = 0; j < size; j++)
    {
        printf("%d\n", array[j]);
    }
}
