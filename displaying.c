#include "constants.h"
#include "utils.h"
#include "displaying.h"
#include "stack_manipulation.h"

void display_stack(int indexOfTheStack)
{
    // system("clear");
    long int val;
    long int ret;

    display_horizontale_separation();
    for (int row = indexOfTheStack -1; row > -1; row--)
    {
        ret = GetN(&val, row);
        display_cell(val, row);
    }
}

void display_horizontale_separation()
{
    printf("------------------------\n");
}

void display_cell(long int val, int row)
{
    printf("|          %3ld           |\t°%2d\n", val,row);
    display_horizontale_separation();
}

void display_user_action()
{
    printf("Which actions you want to do ?\n\tu: Push\t\t\t\to: Pop\t\t\t\tg :Get\n\tU: Push with selected index\tO: Pop with selected index\tG: Get with selected index\n\tt: Top\t\t\t\tm: Max\n\tq: Quit\n");
}

void display_return_value(int retVal)
{
    if(retVal != NULL_VAR)
    {
        printf("\nValeur de retour : %d\n", retVal);
    } else 
    {
        printf("\nValeur de retour : NULL");
    }
}

void display_is_ok(int isOk)
{
    printf("\nIs ok ? : %d\n", isOk);    
}