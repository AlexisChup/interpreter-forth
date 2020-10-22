#include "constants.h"
#include "utils.h"
#include "displaying.h"

void display_stack(int stack[MAX_PILE_D], int indexOfTheStack)
{
    // system("clear");

    printf("------------------------\n");
    for (int row = indexOfTheStack -1; row > -1; row--)
    {
        printf("|          %3d           |\t°%2d\n", stack[row],row);
        printf("------------------------\n");
    }
}

void display_user_action()
{
    printf("Which actions you want to do ?\n\tu: Push\t\t\t\to: Pop\t\t\t\tg :Get\n\tU: Push with selected index\tO: Pop with selected index\tG: Get with selected index\n\tt: Top\t\t\t\tm: Max\n\tq: Quit\n");
}

void display_return_value(int retVal)
{
    printf("\nValeur de retour : %d\n", retVal);
}

void display_is_ok(int isOk)
{
    printf("\nIs ok ? : %d\n", isOk);    
}