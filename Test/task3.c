#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void readAllTheComments(FILE *file, char *data[], int linesRead);


int main()
{
    FILE *file1 = fopen("allTheLinesAreComments.txt", "r");
    FILE *file2 = fopen("NoComments.txt", "r");
    FILE *file3 = fopen("commetsAndNoCommentsAreAlternating.txt", "r");

    char *data1[20] = { 0 };

    int linesRead1 = 0;

    while(!feof(file1))
    {
        char *buffer = malloc(sizeof(char) * 100);
        fgets(buffer, 100, file1);
        
        if(buffer[0] == ';')
        {
            data1[linesRead1] = buffer;
            linesRead1++;
        }

    }
    
    if(linesRead1 != 5)
    {
        printf("Failed when all the lines are comments\n");
        return 1;
    }

    char *data2[20] = { 0 };

    int linesRead2 = 0;

    while(!feof(file2))
    {
        char *buffer = malloc(sizeof(char) * 100);
        fgets(buffer, 100, file2);
        
        if(buffer[0] == ';')
        {
            data1[linesRead2] = buffer;
            linesRead2++;
        }

    }
    
    if(linesRead2 != 0)
    {
        printf("Failed when there are no comments\n");
        return 1;
    }

    char *data3[20] = { 0 };

    int linesRead3 = 0;

    while(!feof(file3))
    {
        char *buffer = malloc(sizeof(char) * 100);
        fgets(buffer, 100, file3);
        
        if(buffer[0] == ';')
        {
            data1[linesRead3] = buffer;
            linesRead3++;
        }

    }
    
    if(linesRead3 != 4)
    {
        printf("Failed when the comments and strings alternate\n");
        return 1;
    }

    printf("Tests are passed!\n");
    
    fclose(file1);
    fclose(file2);
    fclose(file3);

    return 0;
}

void readAllTheComments(FILE *file,char *data[],int linesRead)
{
    while(!feof(file))
    {
        char *buffer = malloc(sizeof(char) * 100);
        fgets(buffer, 100, file);
        
        if(buffer[0] == ';')
        {
            data[linesRead] = buffer;
            linesRead++;
        }

    }
}
