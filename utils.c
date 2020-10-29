#include "constants.h"
#include "utils.h"

void emptyBuffer()
{
    while ((getchar()) != '\n');
}

void clearConsole()
{
    system("clear");
}

char getUserAction()
{
    char action;

    scanf("%c", &action);
    emptyBuffer();

    return action;
}

int getUserNumber(char printfCategory)
{
    int number;

    if(printfCategory == 'n')
    {
        printf("\nWrite your number / operations: \n");
    } else if (printfCategory == 'i')
    {
        printf("\nWrite the index: \n");
    }
    
    scanf("%d", &number);
    emptyBuffer();

    return number;
}