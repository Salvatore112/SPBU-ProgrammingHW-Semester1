#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define strLength 100

typedef struct entryStruct
{
    char name[strLength];
    char number[strLength];

} entry;

void printOptions();
void addEntry(entry collection[], int *entryNumber);
void displayEntries(entry collection[], int length);
void saveEntries(entry collection[], int length, FILE *dataBase);
int readEntries(FILE *dataBase, entry collection[]);
const char* findByName(entry collection[], char name[], int entryNumber);
const char* findByNumber(entry collection[], char name[], int entryNumber);
bool testsFindByName();
bool testsFindByNumber();

int main()
{
    if(!(testsFindByName() && testsFindByNumber()))
    {
        return 1;
    }
    
    entry collection[100];
    FILE *dataBaseRead = fopen("dataBase.txt", "r");

    int entryNumber = readEntries(dataBaseRead, collection);
    fclose(dataBaseRead);

    FILE *dataBase = fopen("dataBase.txt", "w");

    int option = 0;
    do
    {
        printOptions();
        scanf("%d", &option);

        switch (option)
        {
            case 0:
                continue;
                break;
            case 1:
                addEntry(collection, &entryNumber);
                break;
            case 2:
                displayEntries(collection, entryNumber);
                break;
            case 3:
                printf("\nEnter the name of the person that you want to find: ");
                char soughtName[strLength];
                scanf("%s", soughtName);
                if(findByName(collection, soughtName, entryNumber) != NULL)
                {
                    printf("%s has the number %s\n", soughtName, findByName(collection, soughtName, entryNumber));
                }
                else
                {
                    printf("There is no such a person in the phone book!\n");
                }
                break;
            case 4:
                printf("\nEnter the number of the person you want to find: ");
                char soughtNumber[strLength];
                scanf("%s", soughtNumber);
                if (findByNumber(collection, soughtNumber, entryNumber) != NULL)
                {
                    printf("The number %s belongs to %s\n", soughtName, findByNumber(collection, soughtNumber, entryNumber));
                }
                else
                {
                    printf("There is no such a number in the phone book!\n"); 
                }
                break;
            case 5:
                saveEntries(collection, entryNumber, dataBase);
                break;
        }
    } while (option != 0); 

    return 0;
}

void printOptions()
{
    printf("\n*A phonebook*\n");
    printf("Options: \n");
    printf("0 - exit the phonebook\n");
    printf("1 - add a new entry\n");
    printf("2 - display all the entries\n");
    printf("3 - find the phone number by name\n");
    printf("4 - find the name by the phone number\n");
    printf("5 - save entries to the database\n");
    printf("Enter a corresponding digit to choose an option: ");
}

void addEntry(entry collection[], int *entryNumber)
{
    if (*entryNumber < 99)
    {
        entry newEntry;
        char newName[strLength];
        char newNumber[strLength];
        
        printf("Enter the name: ");
        scanf("%s", &newName);
        strcpy(newEntry.name, newName);
        
        printf("Enter the number: ");
        scanf("%s", &newNumber);
        strcpy(newEntry.number, newNumber);

        collection[*entryNumber] = newEntry;
        (*entryNumber)++;

        printf("\n* DONE *\n");
    }
    else
    {
        printf("The limit is 100 entries! Can't write more!\n");
    }
} 

void displayEntries(entry collection[], int length)
{
    printf("\n* ALL THE ENTRIES *\n");
    
    for (int i = 0; i < length; i++)
    {
        printf("%s %s\n", collection[i].name, collection[i].number);
    }
    
    printf("\n* Done *\n");
}

void saveEntries(entry collection[], int length, FILE *dataBase)
{
    for (int i = 0; i < length; i++)
    {
        fprintf(dataBase, "%s %s\n", collection[i].name, collection[i].number);
    }

    printf("\n* Entries are saved! *\n");
}

int readEntries(FILE *dataBase, entry collection[])
{
    int i = 0;
    char newName[strLength];
    char newNumber[strLength];
    while(fscanf(dataBase, "%s", newName) != EOF && fscanf(dataBase, "%s", newNumber) != EOF)
    {
        strcpy(collection[i].name, newName);
        strcpy(collection[i].number, newNumber);
        i++;
    }
    return i;
}

const char* findByName(entry collection[], char name[], int entryNumber)
{
    bool found = false;
    for (int i = 0; i < entryNumber; i++)
    {
        int result = strcmp(name,collection[i].name);
        if (result == 0)
        {
            found = true;
            return collection[i].number;
        }
    }
    return NULL;
}

bool testsFindByName()
{
    entry testCollection1[5] = {{"Mark", "124215"}, {"James", "656334"}, {"Henry", "876754"}, {"Layne", "876333"}, {"Stan", "099975"}};
    if (strcmp(findByName(testCollection1, "Stan", 5), "099975") != 0)
    {
        printf("searching by name failed on the standart test\n");
        return false;
    }

    entry testCollection2[5] = {{"Mark", "124215"}, {"James", "656334"}, {"Henry", "876754"}, {"Layne", "876333"}, {"Stan", "099975"}};
    if (findByName(testCollection2, "Nathan", 5) != NULL)
    {
        printf("searching by name failed when there is no such a name in the phone book\n");
        return false;
    }

    entry testCollection3[5];
    if (findByName(testCollection3, "Karl", 5) != NULL)
    {
        printf("searching by name failed when there is no entries\n");
        return false;
    }
    return true;
}

const char* findByNumber(entry collection[], char number[], int entryNumber)
{
    for (int i = 0; i < entryNumber; i++)
    {
        int result = strcmp(number, collection[i].number);
        if(result == 0)
        {
            return collection[i].name;
        }
    }
    return NULL;
}

bool testsFindByNumber()
{
    entry testCollection1[5] = {{"Mark", "124215"}, {"James", "656334"}, {"Henry", "876754"}, {"Layne", "876333"}, {"Stan", "099975"}};
    if (strcmp(findByNumber(testCollection1, "656334", 5), "James") != 0)
    {
        printf("searching by number failed on the standart test\n");
        return false;
    }

    entry testCollection2[5] = {{"Mark", "124215"}, {"James", "656334"}, {"Henry", "876754"}, {"Layne", "876333"}, {"Stan", "099975"}};
    if (findByNumber(testCollection2, "99999", 5) != NULL)
    {
        printf("searching by number failed when there is no such a number in the phone book\n");
        return false;
    }

    entry testCollection3[5];
    if (findByNumber(testCollection3, "1111", 5) != NULL)
    {
        printf("searching by number failed when there is no entries\n");
        return false;
    }
    return true;
}
