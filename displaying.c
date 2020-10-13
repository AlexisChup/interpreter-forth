#include "constants.h"

void display(int stack[MAX_PILE_D], int indexOfTheStack)
{
    system("clear");

    printf("------------------------\n");
    for (int row = indexOfTheStack -1; row > -1; row--)
    {
        printf("|          %3d           |\t°%2d\n", stack[row],row);
        printf("------------------------\n");
    }
}